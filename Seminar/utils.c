#include "solitaire.h"

void push(position push, position stack) {
    position temp=topOfStack(stack);

    temp->next=push;
    push->next=NULL;
}

position topOfStack(position stack) {
    position temp=stack->next;
    position prev=stack;

    while(temp!=NULL && prev->next!=NULL) {
        prev=temp;
        temp=temp->next;
    }

    return prev;
}

position pop(position stack) {
    if (stack == NULL || stack->next == NULL) {
        printf("Error: Attempt to pop from an empty stack.\n");
        return NULL;
    }

    position prev = stack;
    position temp = stack->next;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    return temp;
}

bool isEmpty(position head) {
    position temp=head;

    if(temp->next==NULL) {
        return true;
    }
    else {
        return false;
    }
}

void flip(position head) {
    position temp=topOfStack(head);

    if(temp->faceUp==0) {
        temp->faceUp=1;
    } 
    else {
        return;
    }

}

int translate(char x[]) {
    if(strcmp(x, "w")==0) return 1;
    else if(strcmp(x, "c1")==0) return 2;
    else if(strcmp(x, "c2")==0) return 3;
    else if(strcmp(x, "c3")==0) return 4;
    else if(strcmp(x, "c4")==0) return 5;
    else if(strcmp(x, "c5")==0) return 6;
    else if(strcmp(x, "c6")==0) return 7;
    else if(strcmp(x, "c7")==0) return 8;
    else if(strcmp(x, "f1")==0) return 9;
    else if(strcmp(x, "f2")==0) return 10;
    else if(strcmp(x, "f3")==0) return 11;
    else if(strcmp(x, "f4")==0) return 12;

}

int translateRanks(char* rank) {

    if (strcmp(rank, "A") == 0) return 1;
    else if (strcmp(rank, "2") == 0) return 2;
    else if (strcmp(rank, "3") == 0) return 3;
    else if (strcmp(rank, "4") == 0) return 4;
    else if (strcmp(rank, "5") == 0) return 5;
    else if (strcmp(rank, "6") == 0) return 6;
    else if (strcmp(rank, "7") == 0) return 7;
    else if (strcmp(rank, "8") == 0) return 8;
    else if (strcmp(rank, "9") == 0) return 9;
    else if (strcmp(rank, "10") == 0) return 10;
    else if (strcmp(rank, "J") == 0) return 11;
    else if (strcmp(rank, "Q") == 0) return 12;
    else if (strcmp(rank, "K") == 0) return 13;
}

bool isRed(position temp) {
    if(strcmp(temp->suit, "♥")==0 || strcmp(temp->suit, "♦")==0) {
        return true;
    }
    else return false;
}

void freeStack(position stack) {
    position temp = stack->next; 
    while (temp != NULL) {
        position toFree = temp; 
        temp = temp->next;      
        free(toFree);           
    }
    stack->next = NULL;
}

void freeCards() {
    freeStack(&stock);
    freeStack(&waste);
    for (int i = 0; i < NUM_COLUMNS; i++) {
        freeStack(columns[i]);
    }
    for (int i = 0; i < NUM_FOUNDATIONS; i++) {
        freeStack(foundations[i]);
    }

}

void flipDown(position head) {
    position temp=topOfStack(head);

    if(temp->faceUp==1) {
        temp->faceUp=0;
    } 
    else {
        return;
    }

}