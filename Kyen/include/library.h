#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <stdio.h>
#include <stdlib.h>

#define UP 420
#define DOWN 69
#define LEFT 1337
#define RIGHT 9001

typedef struct player_t {
    int x; /*x location*/
    int y; /*y location*/
    char piece; /*player's 'piece' on the board*/
} player_t;

typedef struct board_t {
    int x;          /*the x dimension*/
    int y;          /*the y dimension*/
    char **matrix;  /*the board itself*/
    char **original; /*the original board w/o players*/
    player_t *players; /*the array of players on the board*/
    int playercount;

} board_t;

int print_board(board_t *board);
board_t *create_board(int x, int y, int players);
int free_board(board_t *board);
void update_players(board_t *board);
void move_player(board_t *board, int player, int direction);


#endif
