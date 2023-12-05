#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct digits{
    int x;
    int y
}digits;

int calc_digits(digits *dg){
    return dg->x * 10 + dg->y;
}

int is_digit(char c){

}


digits check_line(char c, int size){
    switch (c) {
        case 'o':
            printf("%c\n", c);
            break;
        case 'n':
            printf("%c\n", c);
            break;
        case 'e':
            printf("%c\n", c);
            break;
        case 's':
            printf("%c\n", c);
            break;
        case 'f':
            printf("%c\n", c);
            break;
        case 't':
            printf("%c\n", c);
            break;
        default:
            break;
    }
}


digits *get_digits(char *line, int size){
    digits *dg = (digits*) malloc(sizeof(digits));
    dg->x = -1;
    dg->y = -1;
    for (int i=0;i<size;i++){
        check_line(line[i],1);
        int n = line[i] - 48;
        if ((n >=0 ) && (n<=9)){
            if (dg->x == -1){
                dg->x = n;
            } else {
                dg->y = n;
            }
        }
    }
    if (dg->y == -1) dg->y = dg->x;
    return dg;
}


void read_input(FILE *fp, char **buffer){
    int size;
    ssize_t bytes_read;
    char *line = NULL;
    int sum = 0;
    while ((bytes_read = getline(&line, &size, fp)) > 0 ) {
        printf("%s", line);
        digits *dg = get_digits(line, strlen(line));
        sum += calc_digits(dg);
        free(dg);
    }
    printf("\nSum: %d\n", sum);

}

int main() {
    FILE *fp = fopen("./input.txt", "r");
    char *buffer[1024];
    bzero(buffer,  1024);
    if (fp == NULL){
        perror("Open file");
        exit(EXIT_FAILURE);
    }
    read_input(fp, buffer);

    return 0;
}
