#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("posh> ");
        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }

        // Remove trailing newline
        input[strcspn(input, "\n")] = 0;

        // exit = break 
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // clear command
        if (strncmp(input, "clear", 5) == 0) {
            system("cls");  
            continue;
        }

        // echo command
        if (strncmp(input, "echo ", 5) == 0) {
            printf("%s\n", input + 5);
            continue;
        }

        if (strncmp(input, "ls ", 3) == 0) {
        {

        }

        printf("Unknown command: %s\n", input);
    }

    return 0;
}
