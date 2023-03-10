#include <stdio.h>
#define SIZE 50


void shift_element(int *arr, int i)
{   
    for(int j=i; j>0 ; j--)  //move one right from the last one i times
    {
        *(arr+j)=*(arr+(j-1));  //put the val of the one before him in to him
    }
   
}

void insertion_sort(int *arr, int len)
{

    for(int i=1;i<len;i++)
    {
        int key=*(arr+i);
        int j=i-1;
        while(j>=0 && *(arr+j)>key)
        {
            shift_element(arr+j,1);
            j--;
        }
        *(arr+j+1)=key;

    }
}

int main()
{
    int arr[SIZE];

    for(int i=0;i<SIZE;i++)
    {   
        scanf("%d,",arr+i);
    }

    insertion_sort(arr,SIZE);

    for(int i=0;i<SIZE-1;i++)
    {
        printf("%d,",*(arr+i));
    }
    printf("%d",*(arr+SIZE-1));
    printf("\n");

    return 0;
}