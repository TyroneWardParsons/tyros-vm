/* tvm.c */
#include <stdint.h>
#include <stdlib.h>
#include "tvm.h"

/* virtual machine structure */
struct Tvm {
    uint16_t memory[UINT16_MAX + 1];
};

/* allocate a virtual machine */
Tvm* tvm_alloc()
{
    /* allocate memory */
    Tvm* tvm = calloc(1, sizeof(Tvm));

    /* return pointer */
    return tvm;
}

/* free a virtual machine */
void tvm_free(Tvm* tvm)
{
    /* free the allocated memory */
    free(tvm);
}

/* execute the virtual machine */
void tvm_execute(Tvm* tvm)
{
    tvm->memory[5] = 255;
}