#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

# define NPOINTS 2000
# define MAXITER 500


double a[NPOINTS][NPOINTS], b[NPOINTS][NPOINTS], x[NPOINTS][NPOINTS];

int main(){

  double sum, time_taken; 

  struct timespec start, finish;

  // start timer.
  clock_gettime(CLOCK_REALTIME, &start);

  // Loop nest A   
  for (int i=0; i<NPOINTS; i++) {
    for (int j=0; j<NPOINTS; j++) {
       a[i][j] = 2.0; 
       b[i][j] = 3.14159265359; 
       x[j][i] = 0.0; 
    }
  }
  
  double d = 0.0;  
  for (int iters = 0; iters < MAXITER; iters++){

  // Loop nest B   
    for (int i=1; i<NPOINTS; i++) {
      for (int j=0; j<NPOINTS; j++) {
        x[j][i] = x[j][i] - a[i][j]*b[i][j];
      }
    }


  // Loop nest C   
    for (int i=0; i<NPOINTS; i++) {
      for (int j=1; j<NPOINTS; j++) {
	b[i][j] = x[j][i] * d; 
      }
    }

  }

    sum = 0.0; 
  // Loop nest D   
    for (int i=0; i<NPOINTS; i++) {
      for (int j=1; j<NPOINTS; j++) {
	sum  += a[i][j]+b[i][j];
      }
    }

    // stop timer.
    clock_gettime(CLOCK_REALTIME, &finish);

    // Calculating total time taken by the program.
    time_taken = (finish.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (finish.tv_nsec - start.tv_nsec)) * 1e-9;

/*
 *  Output the results
 */

  printf("Sum = %12.8f \n",sum);
  printf("Time = %12.3f seconds\n",time_taken);

}
