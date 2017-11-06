#include <stdio.h>
#define ElementType int

void InsertionSort(ElementType A[],int N);
void printArray(ElementType arr[],int n);

int main()
{
  int A[]={34,8,64,51,32,21};

  int n=sizeof(A)/sizeof(A[0]);

  printf("Before insertion sort\n");

  printArray(A, n);

  InsertionSort(A,n);


  printf("After insertion sort\n");

  printArray(A, n);
}

void InsertionSort(ElementType arr[],int n)
{
  ElementType key,i,j;
  for( i=1; i< n; i++)//unsorted subarray, i:1->N-1
  {
    key=arr[i];

    for( j=i-1; j>=0 && key<=arr[j];j--)//sorted subarray, j:i->0
    {
      arr[j+1]=arr[j];
    }
    arr[j+1]=key;
  }
}

void printArray(ElementType arr[],int n)
{
  int i;
  for (i=0;i<n;i++)
    printf("%d ",arr[i]); //ElementType:int
  printf("\n");
}
