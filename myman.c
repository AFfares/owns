#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: myman <command>\n");
        return 1;
    }

    char filename[256];

    int length = snprintf(filename, sizeof(filename),
                          "manuals/%s.txt", argv[1]);

    if (length < 0 || (size_t)length >= sizeof(filename))
    {
        fprintf(stderr, "Command name is too long\n");
        return 1;
    }

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("myman");
        return 1;
    }

    char *line = NULL;
    size_t capacity = 0;

    while (getline(&line, &capacity, file) != -1)
    {
        printf("%s", line);
    }

    free(line);
    fclose(file);

    return 0;
}
