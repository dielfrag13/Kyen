#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct location_t {
    int x;
    int y;
} location_t;

typedef struct board_t {
    int x;
    int y;
    char **matrix;
    location_t location;

} board_t;

int print_board(board_t *board);
board_t *create_board(int x, int y);
int free_board(board_t *board);
void update_player(board_t *board, location_t loc, char c);



#endif
