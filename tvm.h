/* virtual machine structure */
typedef struct Tvm Tvm;

/* allocate a virtual machine */
Tvm* tvm_alloc();

/* free a virtual machine */
void tvm_free(Tvm* tvm);

/* execute the virtual machine */
void tvm_execute(Tvm* tvm);

/* print the contents of the registers */
void tvm_print_registers(Tvm* tvm);

/* print the contents of the memory state */
void tvm_print_memory(Tvm* tvm);