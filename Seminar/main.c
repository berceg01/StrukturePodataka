#include "solitaire.h"

char* suits[] = { "♥", "♦", "♠", "♣" };
char* ranks[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

card stock= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card waste= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card column1= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card column2= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card column3= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card column4= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card column5= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card column6= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card column7= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card foundation1= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card foundation2= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card foundation3= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
card foundation4= {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};
position columns[] = { &column1, &column2, &column3, &column4, &column5, &column6, &column7 };
position foundations[] = { &foundation1, &foundation2, &foundation3, &foundation4};
position tableau[] = { &stock, &waste, &column1, &column2, &column3, &column4, &column5, &column6, &column7, &foundation1, &foundation2, &foundation3, &foundation4 };

int main() {
    card head = {.suit=NULL, .rank=NULL, .faceUp=0, .next=NULL};

    createDeck(&head);
    shuffleDeck(&head);
    dealCards(&head);

    displayGame();

    while(!checkWin()) {
        input();
        displayGame();
    }

    freeCards();

    return 0;

}