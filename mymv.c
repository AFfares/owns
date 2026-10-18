#include <stdio.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: mymv <source> <destination>\n");
        return 1;
    }

    if (rename(argv[1], argv[2]) == -1)
    {
        perror("mymv");
        return 1;
    }

    return 0;
}
