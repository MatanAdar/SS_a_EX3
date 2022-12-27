#include <stdio.h>
#define SIZE 50


void shift_element(int *arr, int i)
{
    for(int j=0; j<i ; j++)  //move one right from the last one i times
    {
        *(arr+i-j)=*(arr+i-j-1);  //put the val of the one before him in to him
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
            shift_element(arr+j,i-j);
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
        //printf("please enter a int for the arr:\n");
        scanf(" %d",arr+i);
    }
    printf("\n");
    // //printf("the array before sorted:\n");
    //  for(int i=0;i<SIZE;i++)
    // {   
    //     printf("%d,",*(arr+i));
    // }
    // printf("\n");


    insertion_sort(arr,SIZE);
    //printf("the array after sorted:\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d,",*(arr+i));
    }
    printf("\n");

    return 0;
}