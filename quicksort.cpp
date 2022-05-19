#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a,  int*b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p;

    for(int j=p; j <= r-1; j++)
    {
        if(A[j] <= x)
        {
            swap(&A[i], &A[j]);
            i = i+1;
        }
    }

    swap(&A[i], &A[r]);
    return i;
}

void quicksort(int A[], int p, int r)
{
    if(p < r)
    {
        int q=partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
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

int main()
{
    srand(time(NULL));
    int A[300000];

    for(int i=0; i < 300000; i++)
    {
        A[i] = rand() % 300000;
    }

    clock_t start = clock();
    quicksort(A, 0, 300000 -1);
    clock_t stop = clock();

    // printtable(A, 300000);
    printf("Czas: %lu ms\n", stop, start);

}