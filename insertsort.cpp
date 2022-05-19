#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertSort(int *A, int size) 
{
    int k, j;

    for(int i = 1; i<size; i++)
    {
        k = A[i];
        j = i;

        while(j > 0 && A[j-1]>k)
        {
            A[j] = A[j-1];
            j--;
        }

        A[j] = k;
    }
}

int main() {
    srand(time(NULL));
    int A[300000];
    for(int i=0; i < 300000; i++)
    {
        A[i] = rand() % 300000;
    }

    clock_t start = clock();
    insertSort(A, 300000-1);
    clock_t stop = clock();

    // printtable(A, 300000);
    printf( "Czas: %lu ms\n", stop - start );
}