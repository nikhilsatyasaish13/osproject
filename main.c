#include "incall.h"

int main() {
    pid_t p; // Store the process ID.
    int n; // An integer variable to store the input.
    short err_flag = 0; // A flag variable to detect bad input.

    do {
        if (err_flag == 1)
            printf("\nBad input! Please enter a number greater than 1.");

        printf("\nEnter any number: ");
        scanf("%d", &n);

        err_flag = 1; // Set the error flag to 1, to display error message on next iteration.

    } while (n < 1);

    err_flag = 0; // Reset the error flag.

    p = fork(); // Create a child process.

    switch (p) {
        case -1:
            // Process creation failed.
            printf("\n\nFailed to create the child process.");
            exit(1); // Abort the program.
        case 0:
            while (n >= 1) {
                printf("%d ", n);
                n = n / 2;
            }
            break;
        default:
            wait(NULL); // Wait until the child process finishes its execution.
            printf("\n");
    }

    return 0;
}