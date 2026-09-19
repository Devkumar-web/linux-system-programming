#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Create a file named "testfile.txt" with read/write permissions for the owner
    // and read permissions for others (0644)
    int fd = creat("testfile.txt", 0644);

    // Check if the file creation was successful
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    // Print the file descriptor value
    printf("File created successfully.\n");
    printf("The file descriptor value is: %d\n", fd);

    // Close the file descriptor to free up system resources
    close(fd);

    return 0;
}
