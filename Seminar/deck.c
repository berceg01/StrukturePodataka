#include "solitaire.h"

void createDeck(position head) {
    position temp=head;

    for(int i=0; i<NUM_SUITS; i++) {
        for(int j=0; j<NUM_RANKS; j++) {
            position newCard=createCard(i,j);

            temp->next=newCard;
            temp=temp->next;
        }
    }
}

position createCard(int s, int r) {
    position newCard=(position)malloc(sizeof(card));

    if(!newCard) {
        printf("greška u mallocu!\n");
        exit(1);
    }

    newCard->suit=suits[s];
    newCard->rank=ranks[r];
    newCard->faceUp=0;
    newCard->next=NULL;

    return newCard;
}

void printStack(position head) {
    position temp = head->next;

    while (temp != NULL) {
        if (temp->faceUp == 1) {
            if(isRed(temp)) {
                printf("\033[31m%s%s->\033[0m", temp->rank, temp->suit);

            }
            else {
                printf("%s%s->", temp->rank, temp->suit);
            }
        } else {
            // karta je facedown
            printf("[**]->");
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

void shuffleDeck(position head) {
    srand(time(NULL));

     for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS; 

        position card1 = head->next;
        position card2 = head->next;
        position prev1=head;
        position prev2=head;

        for (int k = 0; k < i; k++) {
            prev1=card1;
            card1 = card1->next;
        }

        for (int k = 0; k < j; k++) {
            prev2=card2;
            card2 = card2->next;
        }

           if (card1 == card2) {
            continue;
        }

        prev1->next = card2;
        prev2->next = card1;

        position tempNext = card1->next;
        card1->next = card2->next;
        card2->next = tempNext;
    }
}

void dealCards(position head) {
    position temp = head->next;
    position prev = head;

    for (int i = 0; i < NUM_COLUMNS; i++) {
        position colHead = columns[i];
        for (int j = 0; j <= i; j++) {
            if (temp != NULL) {
             
                prev->next = temp->next;
                temp->next = NULL; 

                colHead->next = temp;
                colHead = temp; 

                if (j == i) {
                    temp->faceUp = 1;  
                }

                temp = prev->next;  
            }
        }
    }

    stock.next = temp;  
}

void display() {
    printf("Stock: ");
    printStack(&stock);

    printf("Waste: ");
    printStack(&waste);

    printf("Column 1: ");
    printStack(&column1);

    printf("Column 2: ");
    printStack(&column2);

    printf("Column 3: ");
    printStack(&column3);

    printf("Column 4: ");
    printStack(&column4);

    printf("Column 5: ");
    printStack(&column5);

    printf("Column 6: ");
    printStack(&column6);

    printf("Column 7: ");
    printStack(&column7);

    printf("Foundations: \n");
    printf("Foundation 1: ");
    printStack(&foundation1);

    printf("Foundation 2: ");
    printStack(&foundation2);

    printf("Foundation 3: ");
    printStack(&foundation3);

    printf("Foundation 4: ");
    printStack(&foundation4);
}

void displayGame() {
    position current[NUM_COLUMNS];

     for (int i = 0; i < NUM_COLUMNS; i++) {
        current[i] = columns[i]->next;
    }
    printf("Stock:\t\t");
    printf("Waste:\t");
    printf("\t");
    printf("Foundation 1:\t");
    printf("Foundation 2:\t");
    printf("Foundation 3:\t");
    printf("Foundation 4:\t");
    printf("\n");

    printTopOfStack(&stock);
    printf("\t");
    printTopOfStack(&waste);
    printf("\t");
    printTopOfStack(&foundation1);
    printf("\t");
    printTopOfStack(&foundation2);
    printf("\t");
    printTopOfStack(&foundation3);
    printf("\t");
    printTopOfStack(&foundation4);
    printf("\n");
    printf("\n");


    printf("Column 1:\t");
    printf("Column 2:\t");
    printf("Column 3:\t");
    printf("Column 4:\t");
    printf("Column 5:\t");
    printf("Column 6:\t");
    printf("Column 7:\t");
    printf("\n");

    for (int row = 0; row < MAX_COLUMN; row++) {
        for (int i = 0; i < NUM_COLUMNS; i++) {
            if (current[i] != NULL) {
                if (current[i]->faceUp == 1) {
                    if(isRed(current[i])) {
                        printf("\033[31m%s%s\033[0m\t", current[i]->rank, current[i]->suit);

                    }
                    else {
                    printf("%s%s\t", current[i]->rank, current[i]->suit);
                    }
        } else {
            // karta je facedown
            printf("[  ]\t");
        }
                printf("\t");
                current[i] = current[i]->next;
            } else {
                printf("\t\t");
            }
        }
        printf("\n");
    }
}

void printTopOfStack(position head)  {
    position temp=topOfStack(head);

    if(isEmpty(head)) {
        printf("[  ]");
        printf("\t");
    }
    else {
        if (temp->faceUp == 1) {
            if(isRed(temp)) {
                printf("\033[31m%s%s\033[0m", temp->rank, temp->suit);

            }
            else {
                printf("%s%s", temp->rank, temp->suit);
            }
        } else {
            // karta je facedown
            printf("[  ]");
        }

        printf("\t");
    }

}