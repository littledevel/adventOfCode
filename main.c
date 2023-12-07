#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    FILE *p = fopen("input.txt", "r");
    if (p == NULL){
        perror("Open");
        exit(EXIT_FAILURE);
    }
    char line[256];
    ssize_t bytes = getline(line, 256, p);
    if (bytes < 0){
        perror("Reading line");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", line);

}
