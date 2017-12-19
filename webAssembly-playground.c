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

// for arg 5 go like 4 + 3 in first and 2 + 1 in second iteration - 2 iteration
int EMSCRIPTEN_KEEPALIVE fibonacci_recurrence(int num) {
  if (num <= 1) return 1;

  return fibonacci_recurrence(num - 1) + fibonacci_recurrence(num - 2);
}

// memo is cache array
int memo[10000];

int EMSCRIPTEN_KEEPALIVE fibonacci_memo(int n) {
  if (memo[n] != -1) return memo[n];

  if (n == 1 || n == 2) {
    return 1;
  } else {
    return memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
  }
}
