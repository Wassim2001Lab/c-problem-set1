#include <cs50.h>
#include <stdio.h>

bool checksum (long number , int len );
int num_len (long number);
bool is_amex (long number, int len );
bool is_visa (long number, int len );
bool is_mas (long number, int len );

int main(void)
{
    long number = get_long("number: ");
    int len = num_len(number);
    if (checksum ( number , len )==true)
    {
        if ( is_amex ( number,  len )== true)
        {
            printf("AMEX\n");
        }
        else if ( is_mas ( number, len )==true)
        {
            printf("MASTERCARD\n");
        }
        else if ( is_visa ( number, len )==true)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }


    }
    else
    {
        printf("INVALID\n");
    }

}


int num_len (long number)
{
    int count =0;
    while (number > 0)
    {
        number = number / 10 ;
        count++;
    }
    return count;

}

bool checksum (long number , int len )
{
    int sum1=0;
    int num=0;
    int sum2=0;
    bool val=false;
    for(int i=0 ;i<len ;i++)
    {
        if (i % 2== 0)
        {
            sum1 = sum1 + (number%10);
            number =number /10;
        }
        else
        {
            num = (number%10)*2;
            if (num > 9)
            {
                sum2 = sum2 + (num % 10);
                num= num/10;
                sum2 = sum2 + (num%10);
                number= number/10;
            }
            else
            {
                sum2=sum2+num;
                number= number/10;
            }
        }
    }
    if(((sum1+sum2)%10) == 0)
    {
        val = true;
    }
    return val;




}

bool is_amex (long number, int len )
{
    bool val= false;
    for (int i=0 ; i < len -2 ;i++)
    {
        number= number/10;

    }
    if (((number/10)%10) == 3 && ((number%10)==7 ||(number%10)==4 ))
    {
        val=true;
    }
    return val;


}
bool is_mas (long number, int len )
{
    bool val= false;
    for (int i=0 ; i < len -2 ;i++)
    {
        number= number/10;

    }
    if (((number/10)%10) == 5 && ((number%10) > 0 && (number%10) < 6  ) && len == 16)
    {
        val=true;
    }
    return val;


}
bool is_visa (long number, int len )
{
    bool val= false;
    for (int i=0 ; i < len -2 ;i++)
    {
        number = number/10;

    }
    if (((number/10)%10) == 4 && (len == 16 || len == 13))
    {
        val=true;
    }
    return val;


}