#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a,  int*b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

void maxheapify(int A[], int n, int i) 
{
    int largest = i;
    int l = 2 * i + 1; // LEFT
    int r = 2 * i + 2; // RIGHT
  
    if (l < n && A[l] > A[largest])
      largest = l;
  
    if (r < n && A[r] > A[largest])
      largest = r;
  
    if (largest != i) {
      swap(&A[i], &A[largest]);
      maxheapify(A, n, largest);
    }
  }
  
void heapsort(int A[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      maxheapify(A, n, i);
  
    for ( i = n - 1; i>0; i--) {
      swap(&A[0], &A[i]);
      
	maxheapify(A, i, 0);
    }
}

void printtable(int A[], int size)
{
    // wyświetlanie tablicy z jej zawartością
    printf("Tablica = [");
    for (int i=0; i < size-1; i++)
    {
        printf("%d, ", A[i]);
    }
    printf("%d]\n", A[size-1]);
}

int main ()
{
    srand(time(NULL));
    int A[300000];

    for(int i=0; i < 300000; i++)
    {
        A[i] = rand() % 300000;
    }

  clock_t start = clock();
	heapsort(A, 300000);
	clock_t stop = clock();

  // printtable(a, 300000);
	printf( "Czas: %lu ms\n", stop - start );
}