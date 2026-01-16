#include <stdio.h>
#include "my.h"
#include <ctype.h>
int count_word(char str[]){
    int word_ct=0;
    char prev=' ';
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i]) && isblank(prev)) {
            word_ct++;
        }
        prev = str[i];
    }
    return word_ct;
}
void report(char str[LINES][LENGTH_LIMIT]) {
    for (int i = 0; i < LINES; i++) {
        printf("%s", str[i]);
    }
    int word_ct=0;//word count
    int upper_ct=0;//upper count
    int lower_ct=0;//lower count
    int punctuation_ct=0;//punctuation count
    int number_ct=0;//number count
    for (int i = 0; i < LINES; i++) {
        word_ct += count_word(str[i]);
        for (int j = 0; str[i][j]; j++) {
            if (isalpha(str[i][j])) {
                if (isupper(str[i][j])) {
                    upper_ct++;
                } else {
                    lower_ct++;
                }
            } else if (isdigit(str[i][j])) {
                number_ct++;
            } else if (ispunct(str[i][j])) {
                punctuation_ct++;
            }
        }
    }
    printf("Total words: %d\n", word_ct);
    printf("Total upper case letters: %d\n", upper_ct);
    printf("Total lower case letters: %d\n", lower_ct);
    printf("Total punctuation: %d\n", punctuation_ct);
    printf("Total numbers: %d\n", number_ct);
}
int main(void)
{
    char str[LINES][LENGTH_LIMIT];
    if (read_file_lines(str) == -1) {
        fprintf(stderr, "Can't read file lines\n");
        return -1;
    }
    report(str);

    return 0;
}