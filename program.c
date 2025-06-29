#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <windows.h>
#include <tchar.h>

#define MAX_INPUT 1024


void clear_screen() {
    printf("\033[2J\033[H");
    fflush(stdout);

};




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
            clear_screen();
            continue;
        }

        // echo command
        if (strncmp(input, "echo ", 5) == 0) {
            printf("%s\n", input + 5);
            continue;
        }

        // help 
        if (strncmp(input, "help", 4) == 0) {
            printf("echo : Usage 'echo <string>' - Returns string max size 1024 bytes\n");
            printf("exit : Usage 'exit' - Closes posh\n");
            printf("clear : Usage 'clear' - Clears terminal window\n");

            continue;


        }

        printf("Unknown command: %s\n", input);
    }

    return 0;
}
