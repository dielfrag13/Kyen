#include "library.h"

int print_board(board_t *board) {

    printf("printBoard\n");

    int i = 0;
    for (; i < board->x; i++) {
        printf("%s\n", board->matrix[i]);

    }
    printf("\n");

    return 1;

}


board_t *create_board(int x, int y) {
    printf("create_board\n");
    board_t *board = malloc(sizeof(board_t));

    board->x = x;
    board->y = y;
    board->matrix = malloc(x * sizeof(unsigned char *));
    int i = 0;
    int j = 0;
    for (; i < x; i++) {
        board->matrix[i] = calloc(y, sizeof(unsigned char));
        for (j=0; j < y; j++)
            board->matrix[i][j] = '.';
    }
    board->location.x = board->x / 2; /*set player loc to middle*/
    board->location.y = board->y / 2; /*         "    "         */

    update_player(board, board->location, 'p');

    return board;

}

int free_board(board_t *board) {

    printf("free_board\n");
    int i = 0;
    for (; i < board->x; i++)
        free(board->matrix[i]);
    free(board->matrix);
    free(board);
    return 1;

}

void update_player(board_t *board, location_t loc, char c) {

    board->matrix[loc.x][loc.y] = c;

}
