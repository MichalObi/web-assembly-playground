/* headers files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <emscripten/emscripten.h>

/** function fire on load = argc is size
of parameter pass in run, char* is pointer to argument variables **/

int main(int argc, char* argv[]) {
    printf("WebAssembly dice module loaded\n");
}

int EMSCRIPTEN_KEEPALIVE roll_dice() {
    /* By using time as seed for srand we sure,
    that the next roll will be more random */
    srand (time(NULL));
    return rand() % 6 + 1;
}

// n tell us how many times accumulator wil be extended
int EMSCRIPTEN_KEEPALIVE classic_fibonacci(int n){
  int a = 1;
  int b = 1;

  while (n-- > 1) {
    int t = a;
    a = b;
    b += t;
  }

  return b;
}
