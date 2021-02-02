#include "interconnect.h"
#include "iob_knn.h"
#include "KNNsw_reg.h"

static int base;

void knn_start(){
IO_SET(base, KNN_ENABLE, 1);
}

void knn_stop(){
IO_SET(base, KNN_ENABLE, 0);
knn_reset();
}

void knn_init(int base_address){
base = base_address;
}

void knn_set(int x){
IO_SET(base, X, x);
}

int knn_read(){
return IO_GET(base, Y);
}

void knn_reset(){
IO_SET(base, KNN_RESET, 1);
IO_SET(base, KNN_RESET, 0);
}