#include <stdio.h>
#include <cs50.h>

int main (void) {
    int start;
    do
    {
        start= get_int("start size: ");
    }
    while ( start < 9 );

    int end;

    do{
        end = get_int ("end size: ");
    }
    while ( end < start );

    int years = 0;

    while ( start < end )
    {
        start = start + (start/12) ;
        years++;
    }

    printf("years: %i\n" , years);


}