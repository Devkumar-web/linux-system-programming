#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[64];
    printf("Enter pid: "); 
    
    // Read input from the user
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';
    
    char path[256];   // Buffer to store "/proc/pid/status"
    char buffer[1024]; // Buffer to read lines from the status file

    // Format the path safely using snprintf
    snprintf(path, sizeof(path), "/proc/%s/status", input);

    // Open the process status file
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening process file (Check if PID exists)");
        return -1;
    }

    printf("\n========== PID %s ==========\n", input);

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), fp)) {
        // Filter out only relevant process metrics
        if (strncmp(buffer, "Name:", 5) == 0 ||
            strncmp(buffer, "State:", 6) == 0 ||
            strncmp(buffer, "Pid:", 4) == 0 ||
            strncmp(buffer, "PPid:", 5) == 0 ||
            strncmp(buffer, "VmRSS:", 6) == 0 ||
            strncmp(buffer, "Threads:", 8) == 0) {

            printf("%s", buffer);
        }
    }

    fclose(fp);
    return 0;
}
