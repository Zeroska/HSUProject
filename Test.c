#include "stdio.h"


void printArray(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    //printf("\n");
}

int main(int argc, char* argv[])
{
    int a[10] = {3,7,5,2,6,4,1};
    int n = 7;
    int x = 0, count = 0; // 5 , 3, 1 ,9
    printf("Enter the element you want to delete: ");
    scanf("%d",&x);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            count ++;
            for (int j = i; j < n ; j++)
            {   
                   a[j] = a[j + 1];
            }
        }
    }
    n= n-count;
    printArray(a,n);
    printf("\n");
   /* for (int z = 0; z < n - count; z++)
    {
        printf("\t%d",a[z]);
    }
    printf("\n");
    */

    return 0;
}

