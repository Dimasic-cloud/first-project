#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int nb, nw, nl;
} Length;

Length counter(Length* len, FILE* file);

int main()
{
    char s[MAX_SIZE] = {0};
    Length len = {0, 0, 0};
    Length* len_ptr = &len;
    int c, i = 0;

    printf("wride filename");
    while ((c = getchar()) != '\n') {
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

    counter(len_ptr, f);
    printf("quantity: byte = %d, words = %d, lines = %d\n", len.nb, len.nw, len.nl);

    fclose(f);
    
    return 0;
}

Length counter(Length* l, FILE* f)
{
    int c;
    char is_space = 0;

    while ((c = fgetc(f)) != EOF) {
        l->nb += sizeof(c);

        if (c == ' ') {
            if (is_space) {
                l->nw += 1;
            }

            is_space = 1;
        }
        else {
            if (c == '\n') {
                l->nl += 1;
            }
            is_space = 1;
        }
    }

    return* l;
}