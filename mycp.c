#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: mycp <source> <destination>\n");
        return 1;
    }

    int src = open(argv[1], O_RDONLY);

    if (src == -1)
    {
        perror("mycp: source");
        return 1;
    }

    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest == -1)
    {
        perror("mycp: destination");
        close(src);
        return 1;
    }

    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(src, buffer, sizeof(buffer))) > 0)
    {
        ssize_t total_written = 0;

        while (total_written < bytes_read)
        {
            ssize_t bytes_written = write(
                dest,
                buffer + total_written,
                (size_t)(bytes_read - total_written)
            );

            if (bytes_written == -1)
            {
                perror("mycp: write");
                close(src);
                close(dest);
                return 1;
            }

            total_written += bytes_written;
        }
    }

    if (bytes_read == -1)
    {
        perror("mycp: read");
        close(src);
        close(dest);
        return 1;
    }

    close(src);
    close(dest);

    return 0;
}
