/* main.c */
#include <stdint.h>
#include <stdio.h>
#include "tvm.h"

/* main entry point */
int main(int argc, const char* argv[])
{   
    Tvm* tvm = tvm_alloc();
    
    tvm_execute(tvm);
    tvm_print_registers(tvm);
    tvm_print_memory(tvm);

    tvm_free(tvm);   
}