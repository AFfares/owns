#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>

void search_directory(const char *directory, const char *target)
{
    DIR *dir = opendir(directory);

    if (dir == NULL)
    {
        perror(directory);
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char path[PATH_MAX];

        int length = snprintf(path, sizeof(path), "%s/%s",
                              directory, entry->d_name);

        if (length < 0 || (size_t)length >= sizeof(path))
        {
            fprintf(stderr, "Path too long\n");
            continue;
        }

        struct stat info;

        if (lstat(path, &info) == -1)
        {
            perror(path);
            continue;
        }

        if (strcmp(entry->d_name, target) == 0)
        {
            printf("%s\n", path);
        }

        if (S_ISDIR(info.st_mode))
        {
            search_directory(path, target);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: myfind <directory> <filename>\n");
        return 1;
    }

    search_directory(argv[1], argv[2]);

    return 0;
}
