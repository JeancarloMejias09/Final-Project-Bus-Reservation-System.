#include <stdio.h>
#include "helpers.h"

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear screen
}

void print_header(const char* title) {
    printf("\n=== %s ===\n", title);
}
