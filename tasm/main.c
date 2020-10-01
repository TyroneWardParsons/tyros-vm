/* TASM */
/* main.c */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* main entry point */
int main(int argc, const char* argv[])
{
    FILE* fp = fopen("./src/sum.tvm", "r");

    if (fp == NULL)
    {
        perror("Error while opening file.\n");
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}