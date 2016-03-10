#include "kyen.h"
#include "library.h"


int main(int argc, char **argv) {

    int i = 0;
    for (; i < argc; i++) {
        printf("%s\n", argv[i]);

    }
    
    board_t *board = create_board(5, 5);
    int val = print_board(board);
    val = free_board(board);
    printf("val\n", val);
    return 0;
}
