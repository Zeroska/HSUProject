#include "stdio.h"
#include "string.h"
typedef enum{false, true}bool;

//Eratosthenes algorithms for finding prime number

//Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.
        
//eratosthenes function


int sieveOfEratosthenes(int limitForTheSieve)
{
    int count = 0;
    bool Array[limitForTheSieve];
    if(limitForTheSieve == 2)
    {
        return count = 1;
    }
    for(int elements = 2; elements <= limitForTheSieve; elements++) //set all the element of Array equal to 1 (unmarked)
    {
        Array[elements] = true; 
    }

    for (int number = 2; number <= limitForTheSieve; number++)
    {
        if(Array[number] == true)//for the first number is unmasked, mark all the number that can divisible by it, equal to false
        {
            for(int i = number; i*number <= limitForTheSieve;i++ )//segment fault because i*number > 32bit integer (can't store that shit) ==> Overflow became NEGATIVE. 
            {
                Array[number*i] = false;
            }
        }
    }

    for(int j = 2; j <= limitForTheSieve; j++) //count for all the Prime Number (unmarked number)
    {
        if(Array[j] == true)
        {
            count++;
        }
    }
    return count++;
}
//this version currently can't count 2 as the prime number if you enter 2 
//Also can't accept the value > 46348 because the overflow of integer
//Not yet refator
//
int main(void)
{  
    int limitForTheSieve = 0;
    scanf("%d",&limitForTheSieve);//enter the 
    int result = sieveOfEratosthenes(limitForTheSieve);
    printf("%d\n",result);
}
