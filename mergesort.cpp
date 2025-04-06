#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;
int count=0;
void merge(int *,int,int,int);
/*void merge(vector<int> &arr,int low, int mid, int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
         count++;
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;

        }
    }
    while(left<=mid)
      {
            temp.push_back(arr[left]);
            left++;
        }

        while(right<=high)
         {
            temp.push_back(arr[right]);
            right++;
        }
for(int i=low;i<=high;i++)
 arr[i]=temp[i-low];

}*/
void mergesort(int *arr,int low,int high)
{
    if(low>=high) return;
    int mid= (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);

    merge(arr,low,mid,high);

}

void mainmerge(int *arr,int n)
 {
    mergesort(arr,0,n-1);
 }

  int  main()
  {
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
  int *arr =(int*)malloc(n*sizeof(int));
    printf("Enter the array\n");
    for(int i=0;i<n;i++)
     scanf("%d",&arr[i]);

     mainmerge(arr,n);

     for(int i=0;i<n;i++)
     printf("%d  ",arr[i]);
    

  return 0;
  }

void merge(int arr[], int low, int mid, int high)
{
    int size = high - low + 1; // Calculate the size of the temporary array
    int *temp = (int*)malloc(size * sizeof(int)); // Allocate memory for the temporary array
    if (temp == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
        return;
    }

    int left = low;
    int right = mid + 1;
    int k = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }

    while (right <= high)
    {
        temp[k++] = arr[right++];
    }

    for (int i = 0; i < size; i++)
    {
        arr[low + i] = temp[i];
    }

    free(temp); // Free the allocated memory
 }
