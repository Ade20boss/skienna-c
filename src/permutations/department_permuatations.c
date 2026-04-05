#include <stdio.h>

int main()
{
    for(size_t i = 1; i < 8; i++)
    {
        for (size_t j = 2; j < 8; j+=2)
        {
            for (size_t k = 1; k < 8; k++)
            {
                if ((i+j+k) == 12 && i != j && i != k && j != k)
                    printf("%lu %lu %lu\n", i,j, k);
            }
        }
    }
    return 0;
}