/* main.c */
#include <stdint.h>
#include <stdio.h>
#include "tvm.h"

/* main entry point */
int main(int argc, const char* argv[])
{   
    Tvm* tvm = tvm_alloc();
    
    printf("Tyros Virtual Machine");

    tvm_execute(tvm);

    tvm_free(tvm);   
}