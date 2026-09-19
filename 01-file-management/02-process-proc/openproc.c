#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int is_number(const char *str) {
    if (*str == '\0')
        return 0;

    while (*str) {
        if (!isdigit((unsigned char)*str))
            return 0;
        str++;
    }

    return 1;
}

int main() {
    DIR *dir;
    struct dirent *entry;

    
    dir = opendir("/proc");

    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    //reading each directory
    while ((entry = readdir(dir)) != NULL) {

        //interested in only numeric directory name
        if (!is_number(entry->d_name))
            continue;

          
        char path[256];//to store the particular process path "/proc/pid/status"
        char buffer[1024];//to store actual details like name ,status , PID , PPID 


        //it is to store formated string in buffer 
        snprintf(path, sizeof(path),
                 "/proc/%s/status",
                 entry->d_name);

                 //it would open the file of particular given PID in read mode
        FILE *fp = fopen(path, "r");

        if (fp == NULL)
            continue;

        printf("\n========== PID %s ==========\n",
               entry->d_name);

        while (fgets(buffer, sizeof(buffer), fp)) {

            //we are filtering out only relevant information
            //by making them compare
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
    }

    closedir(dir);

    return 0;
}