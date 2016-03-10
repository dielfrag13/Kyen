#include "kyen.h"
#include "library.h"


int main(int argc, char **argv) {

    int i = 0;
    for (; i < argc; i++) {
        printf("%s\n", argv[i]);

    }
    
    board_t *board = create_board(5, 5);
    printf("1\n");
    int val = print_board(board);
    printf("2\n");
    val = free_board(board);
    printf("%i\n", val);
    return 0;
}
