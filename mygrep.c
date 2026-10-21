#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: mygrep <text> <filename>\n");
        return 1;
    }

    char *pattern = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("mygrep");
        return 1;
    }

    char *line = NULL;
    size_t capacity = 0;

    while (getline(&line, &capacity, file) != -1)
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%s", line);
        }
    }

    free(line);
    fclose(file);

    return 0;
}
