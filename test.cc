
#include "test.h"

// Some random function that uses "rewind"
void someFunction(int x[max_loop]) {

  #pragma HLS inline
  #pragma HLS array_partition variable=x complete dim=0

  // Some code before the main loop (initialisation)
  int z[max_loop];
  for(int i = 0; i < max_loop; i++) {
    #pragma HLS unroll
    z[i] = i;
  }

  // The main rewinded loop that uses the initialisation
  for(int i = 0; i < max_loop; i++) {
    #pragma HLS pipeline II=1 
    x[i] = i + z[i];
  }
}

// Test function
void testFunction(int x[max_loop], int y[max_loop]) {

  //#pragma HLS dataflow

  // Calls the main "rewind" loops
  someFunction<0>(x);
  someFunction<1>(y);


  // Uncomment the following to run the "rewind" loops directly in the top function

  // // Some code before the main loop (initialisation)
  // int z[max_loop];
  // int w[max_loop];
  // for(int i = 0; i < max_loop; i++) {
  //   #pragma HLS unroll
  //   z[i] = i;
  //   w[i] = i;
  // }
  // 
  // // The main "rewinded" loops that uses the initialisation
  // for(int i = 0; i < max_loop; i++) {
  //   #pragma HLS pipeline II=1 rewind
  //   x[i] = i + z[i];
  // }
  // 
  // for (int i = 0; i < max_loop; i++) {
  //   #pragma HLS pipeline II=1 rewind
  //   y[i] = i + w[i];
  // }

}
