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

/*creates a board and makes players. their 'characters' are the #
 * player they are.
 */
board_t *create_board(int x, int y, int players) {
    printf("create_board\n");
    board_t *board = malloc(sizeof(board_t));

    board->x = x;
    board->y = y;
    board->matrix = malloc(x * sizeof(unsigned char *));
    board->original = malloc(x * sizeof(unsigned char *));
    int i = 0;
    int j = 0;
    for (; i < x; i++) {
        board->matrix[i] = calloc(y, sizeof(unsigned char));
        board->original[i] = calloc(y, sizeof(unsigned char)); /*free this*/
        for (j=0; j < y; j++) {
            board->matrix[i][j] = '.';
            board->original[i][j] = '.';
        }
    }
    /*one player for now*/
    /*delete this line when you're ready fo rmultiple players*/
    players = 1;

    board->playercount = players;
    board->players = malloc(sizeof(player_t) * players /*players*/);
    for (i=0; i < players; i++)
        /*converts their player # to a character representation*/
        board->players[i].piece = (char)(i+48);

    board->players[0].x = board->x / 2; /*set first player loc to middle*/
    board->players[0].y = board->y / 2; /*           "     "            */
    print_board(board);
    update_players(board);
  
    return board;

}


/*frees all things within the board, allowing for clean exit.*/
/*currently doesn't free players.*/
int free_board(board_t *board) {

    printf("free_board\n");
    int i = 0;
    for (; i < board->x; i++)
        free(board->matrix[i]);
    free(board->matrix);
    free(board);
    return 1;

}

/*updates ALL players' locations on the board.*/
/*does no validity checking. only runs through the player array
 * and puts characters at player locations.*/
/*it's sort of useless except for initialization*/
void update_players(board_t *board) {

    int i = 0;
    int curx, cury;
    int j = 0;

    /*copy over original board*/
    for (i = 0; i < board->x; i++)
        for (j = 0; j < board->y; j++)
            board->matrix[i][j] = board->original[i][j];

    /*update players*/
    for (i = 0; i < board->playercount; i++) {
        curx = board->players[i].x;
        cury = board->players[i].y;
        //printf("player loc: %i, %i. piece: %c\n", curx, cury, board->players[i].piece);
        board->matrix[curx][cury] = board->players[i].piece;
    }

}

/*moves a player a specified direction. will do validity checking later.*/
/*player should be the number index that the player is.*/
/*direction should be UP, RIGHT, LEFT, or DOWN.*/
void move_player(board_t *board, int player, int direction) {
    switch(direction) {
    case UP:
        /*up*/
        board->players[player].x--;
        break;
    case DOWN:
        /*down*/
        board->players[player].x++;

        break;

    case LEFT:
        /*left*/
        board->players[player].y--;

        break;

    case RIGHT:
        /*right*/
        board->players[player].y++;

        break;
    default:
        printf("invalid move direction. dafuq u doooooooooin'?\n");

    }
}
