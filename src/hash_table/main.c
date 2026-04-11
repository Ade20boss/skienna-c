#include <stdio.h>
#include <stdlib.h>


long get_file_size(const char *filename)
{
    long file_size;
    FILE *file_pointer = fopen(filename, "rb");
    if (file_pointer == NULL)
    {
        return -1;
    }



    if (fseek(file_pointer, 0, SEEK_END) == 0)
    {
        long ftell_check = ftell(file_pointer);
        if (ftell_check < 0){
            fclose(file_pointer);
            return -1;
        }
        file_size = ftell_check;
        fclose(file_pointer);
    }

    else
    {
        fclose(file_pointer);
        return -1;
    }

    return file_size;
}

int main()
{
    const char *file_path = "shakespeare.txt";
    long filesize = get_file_size(file_path);
    if (filesize == -1)
    {
        fprintf(stderr, "Unable to get file size");
        return 1;
    }
    else
    {
        printf("Size of %s is %ld\n", file_path, filesize);
    }




    return 0;
}