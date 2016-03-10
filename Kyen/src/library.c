#include "library.h"

int print_board(board_t *board) {
    printf("printBoard\n");
    return 1;

}
board_t *create_board(int x, int y) {
    printf("create_board\n");
    board_t *board = malloc(sizeof(board_t));

    board->x = x;
    board->y = y;
    board->matrix = NULL;

    return board;

}

int free_board(board_t *board) {

    printf("free_board\n");
    free(board);
    return 1;

}
