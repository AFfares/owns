#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: myhead <filename>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        perror("myhead");
        return 1;
    }

    char *line = NULL;
    size_t capacity = 0;
    int count = 0;

    while (count < 10 && getline(&line, &capacity, file) != -1)
    {
        printf("%s", line);
        count++;
    }

    free(line);
    fclose(file);

    return 0;
}
