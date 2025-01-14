#ifndef SOLITAIRE_H
#define SOLITAIRE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52
#define NUM_FOUNDATIONS 4
#define NUM_COLUMNS 7
#define MAX 1024
#define MAX_COLUMN 19

typedef struct Card* position;

typedef struct Card {
    char* suit;
    char* rank;
    int faceUp; //0 ako nije, 1 ako je face up
    position next;
} card;

extern char* suits[];
extern char* ranks[];

extern card stock;
extern card waste;
extern card column1;
extern card column2;
extern card column3;
extern card column4;
extern card column5;
extern card column6;
extern card column7;
extern card foundation1;
extern card foundation2;
extern card foundation3;
extern card foundation4;
extern position columns[];
extern position foundations[];
extern position tableau[];


position createCard(int, int);
void createDeck(position);
void shuffleDeck(position);
void printStack(position);
void dealCards(position);
void display();
void push(position, position);
position pop(position);
position topOfStack(position);
void input();
void draw();
void recycle();
bool isEmpty(position);
void flip(position);
void move(char[], char[]);
int translate(char[]);
bool isValidMove(int, int);
bool isOpposite(char*, char*);
bool isDescending(char*, char*);
int translateRanks(char*);
bool isValidMove2(int, int);
bool isIncreasing(int, int);
bool isSame(int, int);
bool isKing(position);
bool isAce(position);
bool isFoundation(int);
bool isColumn(int);
bool isRed(position);
void movePile(char[], char[], int);
bool isValidMove3(int, int, int);
bool checkWin();
void quit();
void freeStack(position);
void freeCards();
void displayGame();
void printTopOfStack(position);
void flipDown(position);

#endif