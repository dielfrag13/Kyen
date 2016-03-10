#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct board_t {
    int x;
    int y;
    char **matrix;
} board_t;

int print_board(board_t *board);
board_t *create_board(int x, int y);
int free_board(board_t *board);




#endif
