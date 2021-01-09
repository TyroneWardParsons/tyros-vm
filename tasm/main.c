/* TASM */
/* main.c */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* main entry point */
int main(int argc, const char* argv[])
{
    if (argc == 1)
    {
        fprintf(stderr, "%s\n", "No input file argument.");
        exit(EXIT_FAILURE);
    }

    const char* path = argv[1];
    FILE* fp = fopen(path, "r");

    if (fp == NULL)
    {
        perror("Error while opening file");
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