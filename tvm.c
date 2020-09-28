/* tvm.c */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tvm.h"

/* constants */
#define NUMBER_OF_REGISTERS 8
#define SIZE_OF_MEMORY 10 /* UINT16_MAX + 1 */

/* virtual machine structure */
struct Tvm {
    uint16_t registers[NUMBER_OF_REGISTERS];
    uint16_t memory[SIZE_OF_MEMORY];
    uint16_t program_counter;
    int is_running;
};

/* initialize registers */
void tvm_init_registers(Tvm* tvm)
{
    for (int i = 0; i < NUMBER_OF_REGISTERS; i ++)
    {
        tvm->registers[i] = 0;
    }
}

/* initialize memory */
void tvm_init_memory(Tvm* tvm)
{
    for (int i = 0; i < SIZE_OF_MEMORY; i ++)
    {
        tvm->memory[i] = 0;
    }
}

/* fetch next instruction */
uint16_t tvm_fetch(Tvm* tvm)
{
    return tvm->memory[tvm->program_counter++];
}  

/* allocate a virtual machine */
Tvm* tvm_alloc()
{
    /* allocate vm */
    Tvm* tvm = malloc(sizeof(Tvm));

    /* initialize vm */
    tvm_init_registers(tvm);
    tvm_init_memory(tvm);
    tvm->program_counter = 0;
    tvm->is_running = 0;
    
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
    /* set the machine to running */
    tvm->is_running = 1;

    /* start the execution loop */
    while (tvm->is_running)
    {
        uint16_t instruction = tvm_fetch(tvm);
        printf("%hu\n", instruction);

        if (instruction == 0)
        {
            tvm->is_running = 0;
        }
    }
}

/* load state from file */
void tvm_load_state_from_file(Tvm* tvm)
{
    tvm->memory[0] = 0x01;
    tvm->memory[1] = 0x02;
}

/* print the contents of the registers */
void tvm_print_registers(Tvm* tvm)
{
    printf("Registers\n");
    printf("PC -> 0x%04hx\n", tvm->program_counter);
    for (int i = 0; i < NUMBER_OF_REGISTERS; i ++)
    {
        printf("R%i -> 0x%04hx\n", i, tvm->registers[i]);
    } 
}

/* print the contents of the memory state */
void tvm_print_memory(Tvm* tvm)
{
    printf("Memory\n");
    for (int i = 0; i < SIZE_OF_MEMORY; i ++)
    {
        printf("0x%04x -> 0x%04hx\n", i, tvm->memory[i]);
    } 
}
