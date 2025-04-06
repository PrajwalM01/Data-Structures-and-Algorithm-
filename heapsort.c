#include<stdio.h>
#include<stdlib.h>
void maxheapify( int *, int , int);

void maxheap(int *arr, int beg , int end)
{
    for(int i= end / 2 ; i>= beg ;i--)
       maxheapify(arr, i , end);

}
void swap(int *a, int *b)
{
    int temp= *a;
    *a=*b;
    *b =temp;
    
}

void maxheapify( int *arr ,  int i ,int size)
{
    int max = i , left = i *2 , right = i *2 + 1, temp;
  if(left <= size && arr[left] > arr[max])
       max =left;
       if(right <= size && arr[right]> arr[max])
         max = right ;

         if( max != i)
          {
             swap( &arr[i], &arr[max]);
             maxheapify(arr,max,size);

          }
}



void heapsort(int *arr, int size)
{
    for(int i=size;i>=2;i--)
    {
        swap(&arr[1],&arr[i]);
        maxheapify(arr,1,i-1);
    }

}


int main()
{
    int n,i;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);
   int *arr= (int *)malloc(n* sizeof(int));
   printf("Enter the elements os array\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);

    }
     printf("Unsorted array is \n");
    for(i=1;i<=n;i++)
      printf("%d ",arr[i]);

    maxheap(arr,1,n);
    heapsort(arr,n);
   printf("\n");
    printf("Sorted array is \n");
    for(i=1;i<=n;i++)
      printf("%d ",arr[i]);
  
   free(arr);
   return 0;

}