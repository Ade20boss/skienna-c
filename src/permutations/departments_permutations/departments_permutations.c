#include <stdio.h>



int main()
{
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j < 8; j++)
        {
            for (int k = 1;  k < 8; k++)
            {
                if((i != j && i != k && j != k) && (i + j + k) == 12 && j % 2 == 0)
                {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
}