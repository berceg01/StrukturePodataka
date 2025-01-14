#include "solitaire.h"

void input() {
    char buffer[MAX];

    printf("Enter command! (d-draw, r-recycle, m-move, p-move pile, q-quit): \t");
    scanf("%s", buffer);

    if(strcmp(buffer, "d")==0) {
        draw();
        printf("\n");
    }
    else if(strcmp(buffer, "r")==0) {
        recycle();
        printf("\n");
    }
    else if(strcmp(buffer,"m")==0) {
        char buffer1[MAX];
        char buffer2[MAX];
        printf("From-to (npr. c1 c2)\t");
        scanf("%s %s", buffer1, buffer2);
        move(buffer1, buffer2);
        printf("\n");
    }
    else if(strcmp(buffer, "p")==0) {
        char buffer1[MAX];
        char buffer2[MAX];
        int buffer3;
        printf("From-to-starting from (npr. c1 c2 5): \t");
        scanf("%s %s %d", buffer1, buffer2, &buffer3);
        movePile(buffer1, buffer2, buffer3);
        printf("\n");
    }
    else if(strcmp(buffer, "q")==0) {
        quit();
        printf("\n");
    }
    else printf("Invalid command!\n");
}

void draw(){
    if(isEmpty(&stock)) {
        printf("Stock is empty!\n");
        return;
    }
    position temp=pop(&stock);
    push(temp, &waste);

    flip(&waste);
}

void recycle () {
    if(!isEmpty(&stock)) {
        printf("Stock is not empty!\n");
        return;
    }

    while(!isEmpty(&waste)) {
        position temp=pop(&waste);
        push(temp, &stock);
        flipDown(&stock);
    }
}

void move(char from[], char to[]) {
    int f=translate(from);
    int t=translate(to);
    position king;

    if(isColumn(t)) {
        if(isEmpty(tableau[t])) {
            king=topOfStack(tableau[f]);
            if(isKing(king)) {
                position temp=pop(tableau[f]);
                push(temp, tableau[t]);
                flip(topOfStack(tableau[f]));
            }
            else printf("Invalid move to column!\n");
            
        }

        else if(isValidMove(f,t)) {
                position temp=pop(tableau[f]);
                push(temp, tableau[t]);
                flip(topOfStack(tableau[f]));
            }
            else {
                printf("Invalid move to column\n");
            }
    }
    else if(isFoundation(t)) {
        if(isEmpty(tableau[t])) {
            if(isAce(topOfStack(tableau[f]))) {
                position temp=pop(tableau[f]);
                push(temp, tableau[t]);
                flip(topOfStack(tableau[f]));
            }
        }
        else if(isValidMove2(f,t)) {
                position temp=pop(tableau[f]);
                push(temp, tableau[t]);
                flip(topOfStack(tableau[f]));
            }
            else {
                printf("Invalid move to foundation\n");
            }
    }
    else {
        printf("Invalid move!\n");
    }
    
}

bool isValidMove(int from, int to) {
    position tempFrom=topOfStack(tableau[from]);
    position tempTo=topOfStack(tableau[to]);

    if(isOpposite(tempFrom->suit, tempTo->suit) && isDescending(tempFrom->rank, tempTo->rank)) {
        return true;
    }
    else {
        return false;
    }
}

bool isOpposite(char* start, char* to) {
    if((strcmp(start, "♥") == 0 && strcmp(to, "♠")==0) || (strcmp(start, "♠")==0 && strcmp(to, "♥")==0)) return true;
    else if((strcmp(start, "♦")==0 && strcmp(to, "♠")==0) || (strcmp(start, "♠")==0 && strcmp(to, "♦")==0)) return true;
    else if((strcmp(start, "♥")==0 && strcmp(to, "♣")==0) || (strcmp(start, "♣")==0 && strcmp(to, "♥")==0)) return true;
    else if((strcmp(start, "♦")==0 && strcmp(to, "♣")==0) || (strcmp(start, "♣")==0 && strcmp(to, "♦")==0)) return true;
    else return false;
}

bool isDescending(char* x, char* y) {
    int f=translateRanks(x);
    int t=translateRanks(y);

    if(f<t && f+1==t) return true;
    else return false;
}

bool isValidMove2(int from, int to) {
    if(isSame(from, to) && isIncreasing(from, to)) {
        return true;
    }
    else {
        return false;
    }
}

bool isIncreasing(int from, int to) {
    position temp=topOfStack(tableau[from]);
    int f=translateRanks(temp->rank);
    temp=topOfStack(tableau[to]);
    int t=translateRanks(temp->rank);

    if(f>t && f==t+1) return true;
    else return false;
}

bool isSame(int from, int to) {
    position card1, card2;
    card1=topOfStack(tableau[from]);
    card2=topOfStack(tableau[to]);

    if(strcmp(card1->suit, "♥")==0 && strcmp(card2->suit, "♥")==0) return true;
    else if(strcmp(card1->suit, "♦")==0 && strcmp(card2->suit, "♦")==0) return true;
    else if(strcmp(card1->suit, "♠")==0 && strcmp(card2->suit, "♠")==0) return true;
    else if(strcmp(card1->suit, "♣")==0 && strcmp(card2->suit, "♣")==0) return true;
    else return false;
}

bool isKing(position temp) {
    int x=translateRanks(temp->rank);

    if(x==13) return true;
    else return false;
}

bool isAce(position temp) {
    int x=translateRanks(temp->rank);

    if(x==1) return true;
    else return false;
}

bool isFoundation (int x) {
    if(x==9) return true;
    else if(x==10) return true;
    else if(x==11) return true;
    else if(x==12) return true;
    else return false;
}

bool isColumn(int x) {
    if(x==2) return true;
    else if(x==3) return true;
    else if(x==4) return true;
    else if(x==5) return true;
    else if(x==6) return true;
    else if(x==7) return true;
    else if(x==8) return true;
    else return false;
}

void movePile(char from[], char to[], int starting) {
    int f=translate(from);
    int t=translate(to);
    int s=starting;

    position temp=tableau[f];
    position prev=NULL;
    for(int i=0; i<s; i++) {
        prev=temp;
        temp=temp->next;

    }

    if(isColumn(t)) {
        if(isEmpty(tableau[t])) {
            if(isKing(temp)) {
                tableau[t]->next=temp;
                prev->next=NULL;
                flip(prev);
            }
            
        }

        else if(isValidMove3(f,t, s)) {
                position link=topOfStack(tableau[t]);
                link->next=temp;
                prev->next=NULL;
                flip(prev);
            }
            else {
                printf("Invalid move to column!\n");
            }
    }
    else {
        printf("Invalid move!\n");
    }

}

bool isValidMove3(int f, int t, int s) {
    position start=tableau[f];
    for(int i=0; i<s; i++) {
        start=start->next;
    }

    position from=topOfStack(tableau[f]);
    position to=topOfStack(tableau[t]);

    if(isOpposite(start->suit, to->suit) && isDescending(start->rank, to->rank)) return true;
    else return false;
}

bool checkWin() {
    int counter=0;
    for(int i=0; i<9; i++) {
        if(isEmpty(tableau[i])) counter++;
    }

    if(counter==9) {
        printf("Congratulations! You won!");
        return true;}
    else return false;
}

void quit() {
    printf("Thank you for playing!\n");
    freeCards();
    exit(0);
}