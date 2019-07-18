#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void firstFitAlgorithms(int processArray[], int numberProcess ,int memoryBlockArray[], int numberMemoryBlock)
{
    int *allocation = malloc(numberProcess * sizeof(int));
    int flag = 0;
    //memset(allocation, -1, sizeof(allocation));
    for(int g = 0; g < numberProcess; g++)
    {
        allocation[g] = -1;
    }
    for(int i = 0; i < numberProcess; i++)
    {
        for(int j = 0; j < numberMemoryBlock && flag == 0; j++)
        {
            if(memoryBlockArray[j] >= processArray[i])
            {
                allocation[i] = j;
                memoryBlockArray[j] -= processArray[i];
                flag = 1;
            }
        }
    }
    printf("%d ",numberProcess);
    for(int z = 0; z < numberProcess; z++)
    {
        printf("%d ",allocation[z]);
    }
    //Memory block spare
    printf("%d ", numberMemoryBlock);
    for(int k = 0; k < numberMemoryBlock; k++)
    {
        printf("%d ",memoryBlockArray[k]);
    }
    free(allocation);
}


int main()
{
    int numberProcess = 0 ,numberMemoryBlock = 0;
    int processArray[numberProcess], memoryBlockArray[numberMemoryBlock];   //Memory Block
    scanf("%d",&numberMemoryBlock);
    for(int i = 0; i < numberMemoryBlock; i++)
    {
        scanf("%d",&memoryBlockArray[i]);
    }
    //Process Size
    scanf("%d",&numberProcess);
    for(int j = 0; j < numberProcess; j++)
    {
        scanf("%d",&processArray[j]);
    }

    //The algorithm for first fit
    firstFitAlgorithms(processArray, numberProcess, memoryBlockArray, numberMemoryBlock);
    
}
