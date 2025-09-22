#include <stdio.h>
#define MAX_SIZE 100

int counter(FILE* fime);

int main()
{
    char s[MAX_SIZE] = {0};
    int cb, cw, cl;

    int c, i = 0;
    while ((c = getchar()) != EOF) {
        if (i == 100) {
            printf("имя файла должно быть меньше, чем 99 символов, включая его расширение");
            return 1;
        }
        s[i++] = c;
    }
    s[i] += '\0';

    FILE* f = fopen(s, "r");

    if (f == NULL) {
        printf("произошла ошибка при открытии файла");
        return 2;
    }

    cb, cw, cl = counter(f);
    printf("количество: байт = %d, слов = %d, строк = %d\n", cb, cw, cl);

    fclose(f);
    
    return 0;
}

int counter(FILE* f)
{
    int c, cw=0, cl=0, cb=0;
    char is_space = 0;

    while ((c = fgetc(f)) != EOF) {
        cb += sizeof(c);

        if (c == ' ') {
            if (is_space)
                cw += 1;

            is_space = 1;
        }
        else {
            if (c = '\n') {
                cl += 1;
            }
            is_space = 1;
        }
    }

    return cb, cw, cl;
}