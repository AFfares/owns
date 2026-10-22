#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: myhistory <history-file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        perror("myhistory");
        return 1;
    }

    char *line = NULL;
    size_t capacity = 0;
    int number = 1;

    while (getline(&line, &capacity, file) != -1)
    {
        printf("%5d  %s", number, line);
        number++;
    }

    free(line);
    fclose(file);

    return 0;
}
