#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int[],int,int);
void merge(int[],int,int,int);

void mergeSort(int A[], int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left + right)/2;

        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

void merge(int A[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tymczasowe tablice lewej i prawej podtablicy
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    i = 0; // Startowy lewy index
    j = 0; // Startowy prawy index
    k = left; // Indeks początkowy połączonej podtablicy

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) 
        {
            A[k] = L[i];
            i++;
        }
        else 
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozostałych elementów L[], jeżeli wgl jakieś są
    while (i < n1) 
    {
        A[k] = L[i];
        i++;
        k++;
    }
    
    // Kopiowanie pozostałych elementów R[], jeżeli wgl jakieś są
    while (j < n2) 
    {
        A[k] = R[j];
        j++;
        k++;
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
    mergeSort(A, 0, 300000-1); 
    clock_t stop = clock();

	// printtable(A, 300000);
	printf( "Czas: %lu ms\n", stop - start );
}

