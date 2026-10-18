#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: myrm <filename>\n");
        return 1;
    }

    if (unlink(argv[1]) == -1)
    {
        perror("myrm");
        return 1;
    }

    return 0;
}

