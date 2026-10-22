#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 20

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: myless <filename>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        perror("myless");
        return 1;
    }

    char *line = NULL;
    size_t capacity = 0;
    int count = 0;
    int result;

    while ((result = getline(&line, &capacity, file)) != -1)
    {
        printf("%s", line);
        count++;

        if (count == PAGE_SIZE)
        {
            printf("\n-- Press Enter for next page, or q then Enter to quit --");
            fflush(stdout);

            int choice = getchar();

            if (choice == 'q' || choice == 'Q')
            {
                break;
            }

            while (choice != '\n' && choice != EOF)
            {
                choice = getchar();
            }

            count = 0;
            printf("\n");
        }
    }

    free(line);
    fclose(file);

    return 0;
}
