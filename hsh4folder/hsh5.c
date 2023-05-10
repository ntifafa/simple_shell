#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length of command line
#define MAX_ARGS 10 // Maximum number of arguments

int main(void) {
    char *args[MAX_ARGS]; // Array of arguments
    char line[MAX_LINE];  // Command line buffer

    while (1) {
        printf("simple_shell> "); // Display prompt

        fgets(line, MAX_LINE, stdin); // Read command line from user

        // Tokenize the command line into arguments
        int i = 0;
        args[i] = strtok(line, " \n"); // First argument
        while (args[i] != NULL && i < MAX_ARGS - 1) {
            args[++i] = strtok(NULL, " \n"); // Next argument
        }
        args[i] = NULL; // Set last argument to NULL

        if (args[0] == NULL) { // Empty command line
            continue;
        }

        if (strcmp(args[0], "cd") == 0) { // Change directory command
            if (args[1] == NULL) { // Missing argument
                printf("cd: expected argument\n");
            } else {
                if (chdir(args[1]) != 0) { // Change directory failed
                    printf("cd: %s: No such file or directory\n", args[1]);
                }
            }
        } else {
            pid_t pid = fork(); // Create a child process
            if (pid == 0) { // Child process
                execvp(args[0], args); // Execute the command
                printf("%s: command not found\n", args[0]); // Command not found
                exit(1);
            } else if (pid > 0) { // Parent process
                wait(NULL); // Wait for child process to complete
            } else { // Error
                printf("fork failed\n");
            }
        }
    }

    return 0;
}
