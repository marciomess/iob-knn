#include "system.h"
#include "periphs.h"
#include <iob-uart.h>
#include "iob_timer.h"
#include "iob_knn.h"
#include "random.h" //random generator for bare metal

//uncomment to use rand from C lib 
//#define cmwc_rand rand

#ifdef DEBUG //type make DEBUG=1 to print debug info
#define S 12  //random seed
#define N 10  //data set size
#define K 4   //number of neighbours (K)
#define C 4   //number data classes
#define M 4   //number samples to be classified
#else
#define S 12   
#define N 100000
#define K 10  
#define C 4  
#define M 100 
#endif

#define INFINITE ~0




///////////////////////////////////////////////////////////////////
int main() { 

  //init uart and timer
  uart_init(UART_BASE, FREQ/BAUD);
  uart_printf("\nInit timer\n");

  //generate random seed 
  random_init(S);


  short num;
  short max = 0;

  //init dataset
  for (int i=0; i<10; i++) {
    //init coordinates
    num = (short) cmwc_rand();
    uart_printf("random %d = %d\n",i, num);  

    if (num > max ){
      max = num;
    }
    
  }
  uart_printf("\nmax = %d\n", max);
  return 0;  
}

