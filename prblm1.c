#include <stdio.h>
#include <cs50.h>


int main (void)
{
  int h ;

  do{
      h = get_int("height:  ");

     }while (  8 < h < 1 );

    for( int n= h-1 ; n >= 0; n--)
    {
          for(int i= 0 ;i <= h; i++){
            if( i<=n ){
               printf(" ");
            }
            else{
              printf("#");
            }
          }

          printf("\n");

    }
}