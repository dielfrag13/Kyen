#include "kyen.h"
#include "library.h"

int main(int argc, char **argv) {

    int i = 0;
    for (; i < argc; i++) {
        printf("%s\n", argv[i]);

    }

    if (!(/*argc == 2 ||*/ argc == 3)) {
        printf("usage: ./kyen [filename] or ./kyen [boardX] [boardY]\n");
        printf("filename not currently implemented\n");
        return 1;
    }


    board_t *board = create_board(atoi(argv[1]), atoi(argv[2]), 1);
    printf("1\n");
    int val = print_board(board);
    printf("2\n");


    char buf[16];
    int flag = 1;
    while(flag) {
        printf("enter direction >>> ");
        fgets(buf, 16, stdin);
        switch(buf[0]) {
            case 'a':
                printf("LEFT\n");
                move_player(board, 0 /*player 0*/, LEFT);
                break;
            case 'w':
                printf("UP\n");
                move_player(board, 0 /*player 0*/, UP);
                break;
            case 's':
                printf("DOWN\n");
                move_player(board, 0 /*player 0*/, DOWN);
                break;
            case 'd':
                printf("RIGHT\n");
                move_player(board, 0 /*player 0*/, RIGHT);
                break;
            case 'q':
                printf("quitting.\n");
                flag = 0;
            default:
                printf("invalid input. wasd, or q.\n");
                continue;
        }/*end switch*/
        update_players(board);
        print_board(board);

    }

    /*cleanup code*/
    val = free_board(board);
    printf("%i\n", val);
    return 0;

}
