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

int is_substr(char *haystack, size_t haystack_size, char *needle, size_t needle_size){
    int i = 0;
    while (i<haystack_size){
        int k = i;
        int j = 0;
        while ( haystack[k] == needle[j] ){
            k++;
            j++;
        }
        if (j == needle_size){
            return i;
        } else {
            i++;
        }
    }
    return -1;
}

digits *get_digits(char *line, int size){
    digits *dg = (digits*) malloc(sizeof(digits));
    dg->x = -1;
    dg->y = -1;
    for (int i=0;i<size;i++){
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
    char *nums[9] = {
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"
            };
    int size;
    ssize_t bytes_read;
    char *line = NULL;
    int sum = 0;
    char *one = "one";
    while ((bytes_read = getline(&line, &size, fp)) > 0 ) {
        printf("%s", line);
        for (int i = 0; i < 9; i++){
            int found = is_substr(line, strlen(line), nums[i], strlen(nums[i]) );
            if (found > -1){
                line[found] = i + '0' + 1;
            }
        }
        printf("> %s", line);
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
