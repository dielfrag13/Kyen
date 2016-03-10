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
    board_t *board = create_board(atoi(argv[1]), atoi(argv[2]));
    printf("1\n");
    int val = print_board(board);
    printf("2\n");








    /*cleanup code*/
    val = free_board(board);
    printf("%i\n", val);
    return 0;

}
