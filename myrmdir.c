#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: myrmdir <directory>\n");
        return 1;
    }

    if (rmdir(argv[1]) == -1)
    {
        perror("myrmdir");
        return 1;
    }

    return 0;
}
