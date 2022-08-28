#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Array{
    int *array;
    size_t used;
    size_t size;
} Array;

typedef struct field{
	int row;
	int column;
	int apple;
	char** field;
	Array snakePositionsX;
	Array snakePositionsY;
    int last;
    int allApples;
    int usedComms;
} field;


void setApplesForField(field *game);
int getColumn(const char *level);
int getRows(const char *level);
void commandHandler(field *game, FILE *eingabeDatei, FILE *ausgabeDatei);
field *createBoard(int row, int column, const char *level);
void level_einlesen(const char *level, char **board);
int run(const char *input, const char *output, const char *level);
void printGame(field *game, int rows, FILE *output);
void free_mem(field *board);
int getPosX(field *game);
int getPosY(field *game);
int moveUp(field *game);
int moveLeft(field *game);
int moveDown(field *game);
int moveRight(field *game);
int checkTxtFile(const char *str);
int checkFile(const char *input, const char *output, const char *level);

void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, int element);
int* removeElement(int* array, int sizeOfArray, int indexToRemove);
void freeArray(Array *a);

#endif