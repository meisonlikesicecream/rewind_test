
#include "test.h"

int main() {

  int x[max_loop] = {0};
  int y[max_loop] = {0};

  testFunction(x, y);

  int error = 0; // Error count

  // for(int i = 0; i < max_loop; i++) {
  //   error += (x[i] == i*2) ? 0 : 1;
  //   error += (y[i] == i*2) ? 0 : 1;
  // }

  return error;
}
