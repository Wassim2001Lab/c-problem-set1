#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int h ;
    do
    {
        h = get_int("height:  ");
    }
    while (8 < h || h < 1);



    for (int n = h ; n > 0; n--)
    {
        int j = h;
        for (int c = 1 ; c <= 2 * h + 1; c++)
        {
            if (c < h + 1)
            {
                if (c < n)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }
            }
            else if (c == h + 1)
            {
                printf("  ");
            }
            else if (c > h + 1)
            {
                if (j >= n)
                {
                    printf("#");
                }
                j--;
            }
        }

        printf("\n");

    }
}