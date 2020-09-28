/* main.c */
#include <stdint.h>
#include <stdio.h>
#include "tvm.h"

/* main entry point */
int main(int argc, const char* argv[])
{   
    /* allocate the virtual machine */
    Tvm* tvm = tvm_alloc();
    tvm_load_state_from_file(tvm);

    /* execute the virtual machine */
    tvm_execute(tvm);
    tvm_print_registers(tvm);
    tvm_print_memory(tvm);

    /* free memory */
    tvm_free(tvm);   
}