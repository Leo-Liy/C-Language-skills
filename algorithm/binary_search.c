#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, int item)
{
    int low = 0;
    int high = sizeof(array)/sizeof(int);
    int mid,guess;
    while (low <= high)
    {
        mid = (low + high);
        guess = array[mid];
        if (guess == item)
        {
            return mid;
        }
        else if (guess > item)
        {
            high = mid - 1;
        }
        else
        {
           low = mid + 1; 
        }
        
    }
    return -1;
}

int main()
{
    int a[5]={1,3,5,7,9};
    int count = sizeof(a)/sizeof(int);
    int guess, index;
    printf("Ple input a guess data:");
    scanf("%d", &guess);
    for (int i = 0; i < count; i++)
    {
        printf("%d  ", *(a+i));
    }
    printf("\n");
    index = binary_search(a,guess);
    printf("The index is: %d \n", index);
    getchar();
}
