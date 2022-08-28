#include "snake.h"

int getPosX(field *game) {
	int x;

	for (int i = 0; i < game->row; i++) {
		for (int j = 0; j < game->column; j++) {
			if (game->field[i][j] == 'O') {
				x = j;
			}
		}
	}

	return x;
}

int getPosY(field *game) {
	int y; 

	for (int i = 0; i < game->row; i++) {
		for (int j = 0; j < game->column; j++) {
			if (game->field[i][j] == 'O') {
				y = i;
			}
		}
	}

	return y;
}

int moveUp(field *game) {
	int newPosX = (int)game->snakePositionsX.array[game->snakePositionsX.used-1];
	int newPosY = (int)game->snakePositionsY.array[game->snakePositionsY.used-1] - 1;
	int lastPosX = (int)game->snakePositionsX.array[game->last];
	int lastPosY = (int)game->snakePositionsY.array[game->last];

	int crash = 0;

	if(game->field[newPosY][newPosX] == 'X'){
		if(game->apple > 0){
			game->apple--;
		} else {
			game->field[lastPosY][lastPosX] = ' ';
		}
		game->field[newPosY][newPosX] = 'O';
		crash = -1;
	} else {

		if(game->apple > 0){
			game->apple--;
		} else {
			game->field[lastPosY][lastPosX] = ' ';
			game->last++;
		}

		if( 
			(game->field[newPosY][newPosX] - '0') > 0  && 
			(game->field[newPosY][newPosX] - '0') <= 9
		){
			game->apple += (game->field[newPosY][newPosX] - '0');
		}

		if(game->field[newPosY][newPosX] == 'O'){
			crash = -2;
		}

		game->field[newPosY][newPosX] = 'O';

		insertArray(&game->snakePositionsY, newPosY);
		insertArray(&game->snakePositionsX, newPosX);
	}

	return crash;
}

int moveLeft(field *game) {
	
	int newPosX = (int)game->snakePositionsX.array[game->snakePositionsX.used-1] - 1;
	int newPosY = (int)game->snakePositionsY.array[game->snakePositionsY.used-1];
	int lastPosX = (int)game->snakePositionsX.array[game->last];
	int lastPosY = (int)game->snakePositionsY.array[game->last];

	int crash = 0;

	if(game->field[newPosY][newPosX] == 'X'){
		if(game->apple > 0){
			game->apple--;
		} else {
			game->field[lastPosY][lastPosX] = ' ';
		}
		game->field[newPosY][newPosX] = 'O';
		crash = -1;
	}  else {

		if(game->apple > 0){
			game->apple--;
		} else {
			game->field[lastPosY][lastPosX] = ' ';
			game->last++;
		}

		if( 
			(game->field[newPosY][newPosX] - '0') > 0  && 
			(game->field[newPosY][newPosX] - '0') <= 9
		){
			game->apple += (game->field[newPosY][newPosX] - '0');
		}

		if(game->field[newPosY][newPosX] == 'O'){
			crash = -2;
		}

		game->field[newPosY][newPosX] = 'O';

		insertArray(&game->snakePositionsY, newPosY);
		insertArray(&game->snakePositionsX, newPosX);
	}

	return crash;
}

int moveDown(field *game) {
	int newPosX = (int)game->snakePositionsX.array[game->snakePositionsX.used-1];
	int newPosY = (int)game->snakePositionsY.array[game->snakePositionsY.used-1] + 1;
	int lastPosX = (int)game->snakePositionsX.array[game->last];
	int lastPosY = (int)game->snakePositionsY.array[game->last];

	int crash = 0;

	if(game->field[newPosY][newPosX] == 'X'){
		if(game->apple > 0){
			game->apple--;
		} else {
			game->field[lastPosY][lastPosX] = ' ';
		}
		game->field[newPosY][newPosX] = 'O';
		crash = -1;
	}  else {

		if(game->apple > 0){
			game->apple--;
		} else {
			game->field[lastPosY][lastPosX] = ' ';
			game->last++;
		}

		if( 
			(game->field[newPosY][newPosX] - '0') > 0  && 
			(game->field[newPosY][newPosX] - '0') <= 9
		){
			game->apple += (game->field[newPosY][newPosX] - '0');
		}

		if(game->field[newPosY][newPosX] == 'O'){
			crash = -2;
		}

		game->field[newPosY][newPosX] = 'O';

		insertArray(&game->snakePositionsY, newPosY);
		insertArray(&game->snakePositionsX, newPosX);
	}
	return crash;
}

int moveRight(field *game) {
	int newPosX = (int)game->snakePositionsX.array[game->snakePositionsX.used-1] + 1;
	int newPosY = (int)game->snakePositionsY.array[game->snakePositionsY.used-1];
	int lastPosX = (int)game->snakePositionsX.array[game->last];
	int lastPosY = (int)game->snakePositionsY.array[game->last];
	int crash = 0;

	if(game->field[newPosY][newPosX] == 'X'){
		if(game->apple > 0){
			game->apple--;
		} else {
			game->field[lastPosY][lastPosX] = ' ';
		}
		game->field[newPosY][newPosX] = 'O';
		crash = -1;
	}  else {

		if(game->apple > 0){
			game->apple--;
		} else {
			game->field[lastPosY][lastPosX] = ' ';
			game->last++;
		}

		if( 
			(game->field[newPosY][newPosX] - '0') > 0  && 
			(game->field[newPosY][newPosX] - '0') <= 9
		){
			game->apple += (game->field[newPosY][newPosX] - '0');
		}

		if(game->field[newPosY][newPosX] == 'O'){
			crash = -2;
		}

		game->field[newPosY][newPosX] = 'O';

		insertArray(&game->snakePositionsY, newPosY);
		insertArray(&game->snakePositionsX, newPosX);
	}

	return crash;
}

void commandHandler(field *game, FILE *eingabeDatei, FILE *ausgabeDatei) {
	int length;
	int crash = 0;
	char cmd;
	int i = 0;

	fseek(eingabeDatei, 0, SEEK_END);
	length = ftell(eingabeDatei);
	fseek(eingabeDatei, 0, SEEK_SET);
	printGame(game, game->row, ausgabeDatei);
	fprintf(ausgabeDatei, "%d\n",game->usedComms);
	
	while ((cmd = fgetc(eingabeDatei)) != EOF) {
		i++;
		
        switch(cmd) {
			case 'w':
				crash = moveUp(game);
				break;
			case 'a':

				crash = moveLeft(game);
				break;
			case 's':
				crash = moveDown(game);
				break;
			case 'd':
				crash = moveRight(game);
				break;
		}

		if(cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd'){
			game->usedComms++;
			setApplesForField(game);
			printGame(game, game->row, ausgabeDatei);
			if(crash == 0 && game->allApples != 0 && game->usedComms <= length){
				fprintf(ausgabeDatei, "%d\n",game->usedComms);
			}
		

			else if(game->allApples == 0){
				fprintf(ausgabeDatei, "Gewonnen!\n");
			}
			
			if (crash == -1) {
				fprintf(ausgabeDatei, "Die Schlange ist in die Wand gelaufen!\n");
			}
			if (crash == -2) {
				fprintf(ausgabeDatei, "Die Schlange hat sich selbst gefressen!\n");
			}
		}
    }
}

void free_mem(field *board) {
    for (int i = 0; i < board->row; i++) {
        free(board->field[i]);
    }

    free(board->field);
	freeArray(&board->snakePositionsX);
	freeArray(&board->snakePositionsY);
    free(board);
}

void level_einlesen(const char *level, char **board) {
	FILE *levelDatei = fopen(level, "r");

	int maxLength = 82;
	int rows = getRows(level);

    for (int i = 0; i < rows; i++) {
		fgets(board[i], maxLength, levelDatei);
	}
	fclose(levelDatei);
}

field *createBoard(int row, int column, const char *level) {
	FILE *levelDatei = fopen(level, "r");

    char **boardValues = (char**)malloc(row * sizeof(char *));
    field *board = (field*)malloc(sizeof(field));

    for (int i = 0; i < row; i++) {
        boardValues[i] = (char*)malloc((column + 1) * sizeof(char));
		boardValues[i][column] = '\0';
    }

	level_einlesen(level, boardValues);

	board->apple = 0;
    board->row = row;
    board->column = column;
    board->field = boardValues;
    board->allApples = 0;
    board->usedComms = 1;

    initArray(&board->snakePositionsX, 1);
    initArray(&board->snakePositionsY, 1);

    insertArray(&board->snakePositionsX, getPosX(board));
    insertArray(&board->snakePositionsY, getPosY(board));

    board->last = 0;
	fclose(levelDatei);
    return board;
}

void printGame(field *game, int rows, FILE *output) {
	for (int i = 0; i < rows; i++) {
		fprintf(output, "%s", game->field[i]);
	}
}

int getRows(const char *level) {
	FILE *levelDatei = fopen(level, "r");
	int maxLength = 82;
	char line[82];
	unsigned int line_count = 0;

    while (fgets(line, maxLength, levelDatei)) {
        line_count++;
    }
	fclose(levelDatei);
	return line_count;
}

int getColumn(const char *level) {
	FILE *levelDatei = fopen(level, "r");
	int count = 0;
	char current;

    for (current = getc(levelDatei); current != EOF; current = getc(levelDatei)) {
		count++;
        if (current == '\n') {
            break; 
		}
	}

	fclose(levelDatei);
	return count;
}

int checkTxtFile(const char *str){
	int size = strlen(str);
	
	if(strcmp(str, "-") == 0){
		return 1;
	}
	
	if(strlen(str) < 5){
		return 0;
	}
	
	if(str[size - 1] == 't' && str[size - 2] == 'x' && str[size - 3] == 't' && str[size - 4] == '.'){
		return 1;
	}
	return 0;
}

int checkFile(char const *input, char const *output, char const *level){
	FILE *fp;

	if(!checkTxtFile(input) || !checkTxtFile(output) || !checkTxtFile(level)){
		return 3;
	}

	if(strcmp(input, "-") != 0){
		fp = fopen(input, "r");
		if(fp == NULL){
			return 2;
		}
		fclose(fp);
	}

	if(strcmp(output, "-") != 0){
		fp = fopen(output, "w");
		if(fp == NULL){
			return 2;
		}
		fclose(fp);
	}
	
	fp = fopen(level, "r");
	
	if(fp == NULL){
		return 2;
	}
	
	fclose(fp);
    return 0;
}

int run(char const *input, char const *output, char const *level) {
	// Level Verwaltung
    FILE *levelDatei = fopen(level, "r");
	FILE *eingabeDatei;
	FILE *ausgabeDatei;
	int column;
	
	column = getColumn(level);
	if (column > 81) { 
		fprintf(stderr, "Level-Datei ist nicht genau 80 Zeilen lang!");
		fclose(levelDatei);
		return 4;
	}
	
	fclose(levelDatei); 
	
	int rows = getRows(level);
   	field *game = createBoard(rows, column, level);

	// Ein-/Ausgabe Verwaltung

	if ((strcmp(input, "-") == 0) && (strcmp(output, "-") == 0)) {
		commandHandler(game, stdin, stdout);
	} else if ((strcmp(input, "-") != 0) && (strcmp(output, "-") == 0)) {
		eingabeDatei = fopen(input, "r");

		commandHandler(game, eingabeDatei, stdout);

		fclose(eingabeDatei);
	} else if ((strcmp(input, "-") == 0) && (strcmp(output, "-") != 0)) {
		ausgabeDatei = fopen(output, "w");

		commandHandler(game, stdin, ausgabeDatei);

		fclose(ausgabeDatei);
	} else if ((strcmp(input, "-") != 0) && (strcmp(output, "-") != 0)) {
		eingabeDatei = fopen(input, "r");
		ausgabeDatei = fopen(output, "w");

		commandHandler(game, eingabeDatei, ausgabeDatei);

		fclose(eingabeDatei);
		fclose(ausgabeDatei);
	}

	free_mem(game);
	return 0;
}

void initArray(Array *a, size_t initialSize) {
    a->array = malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void setApplesForField(field *game){
	int temp = 0;

    for(int i = 0; i < game->row; i++){
        for(int j = 0; j < game->column; j++){
            if((game->field[i][j] - '0') > 0 && (game->field[i][j] - '0') <= 9){
                temp++;
            }
        }
    }
	game->allApples = temp;
}

int main(int argc, char const *argv[]) {

	if ((argc - 1) % 3 != 0) {
		fprintf(stderr, "Du hast zu wenig oder zu viele Parameter!\n");
		return 1;
	}
	int val;
	// 4 - Wenn die Zeilen der Level Datei nicht genau 80 Zeilen lang sind
	for(int i = 1; i < argc; i += 3){
		val = checkFile(argv[i], argv[i + 1], argv[i + 2]);
		if(val == 2){
			fprintf(stderr, "Datei kann nicht geöffnet werden!\n");
			return 2;
		}
		else if(val == 3){
			fprintf(stderr, "Datei kann nicht gelesen werden!\n");
			return 3;
		}
	}
	if(argc == 1){
		run("-", "-", "level/1.txt");
	}
	for (int i = 1; i < argc; i += 3) {
		run(argv[i], argv[i + 1], argv[i + 2]);

	}
	
	return 0;
}