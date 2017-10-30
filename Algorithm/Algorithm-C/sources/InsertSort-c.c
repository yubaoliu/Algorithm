#include <stdio.h>
#define ElementType int

void InsertionSort(ElementType A[],int N);

int main()
{
  int A[]={34,8,64,51,32,21};
  InsertionSort(A, 6);
  for(int i=0; i<6; i++)
  {
    printf("%d ",A[i]);
  }
  printf("\n");

}

void InsertionSort(ElementType A[],int N)
{
  ElementType tmp;
  for(int i=1; i< N; i++)//unsorted subarray, i:1->N-1
  {
    tmp=A[i];

    for(int j=i; j>0 && tmp>=A[j];j--)//sorted subarray, j:i->0
    {
      A[j]=tmp;
    }
  }
}
