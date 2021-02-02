#include "system.h"
#include "periphs.h"
#include <iob-uart.h>
#include "iob_timer.h"
#include "iob_knn.h"
#include "random.h" //random generator for bare metal

#include <stdlib.h>

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

  //cmwc_rand
  //random_init(S);
  //num = (short) cmwc_rand();

  srand(S);



  short num;
  short max = 0;
  int x[100];
  int y[97];

  //init dataset

  for (int j = 0; j < 100; j++){
    x[j] = rand()%100;
  } 


  for ( int i=3; i<100; i++) {
        //init coordinates

  y[i] = x[i]*x[i-1]-x[i-2]/x[i-3];
  
  uart_printf("\ny[%d] = %d",i, y[i]);     
    
  }
  uart_printf("\n");
  return 0;  
}

