#include "shell.h"

/**
 * main - Entry point of shell.
 * @ac: argument count.
 * @argv: argument variable.
 * @env: NULL terminated array of strings.
 *
 * Return: 0 on success.
 */

int main(int ac, char **argv){
    char *prompt = "(Eshell) $ ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    /* declaring void variables */
    (void)ac;

    /* A loop for the shell's prompt */
    while (1) {
        printf("%s", prompt);
        nchars_read = getline(&lineptr, &n, stdin);
        /* check if the getline function woked or failed */ 
        if (nchars_read == -1){
            printf("Exiting shell....\n");
            return (-1);
        }

        /* allocate space to copy the lineptr */
        lineptr_copy = malloc(sizeof(char) * nchars_read);
        if (lineptr_copy== NULL){
            perror("tsh: memory allocation error");
            return (-1);
        }
        /* copy lineptr to lineptr_copy */
        strcpy(lineptr_copy, lineptr);

        /* total number of tokens */
        token = strtok(lineptr, delim);

        while (token != NULL){
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        /* Allocate space for the array of strings */
        argv = malloc(sizeof(char *) * num_tokens);

        /* Store each token in the argv */
        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;


        printf("%s\n", lineptr);

        /* free the allocated memory */ 
        free(lineptr);
    } 


    return (0);
}
