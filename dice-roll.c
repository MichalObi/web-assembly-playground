/* headers files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <emscripten/emscripten.h>

/** function fire on load = argc is size
of parameter pass in run, char* is pointer to argument variables **/

int main(int argc, char* argv[]) {
    printf("WebAssembly module loaded\n");
}

int EMSCRIPTEN_KEEPALIVE roll_dice() {
    /* By using time as seed for srand we sure,
    that the next roll will be diff then previous one*/

    srand (time(NULL));
    return rand() % 6 + 1;
}
