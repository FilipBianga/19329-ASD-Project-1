#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iterator>

void swap(int* a,  int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// HEAPSORT
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

// QUICKSORT
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

// MERGE-SORT
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

// Insert Sort
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
    // tablica losowa
    srand(time(NULL));
    const int n = 100000;
    int A[n];

    for(int i=0; i < n; i++)
    {
        A[i] = rand() % n;
    }

    int B[n];
    int C[n];
    int D[n];
    std::copy(std::begin(A), std::end(A), std::begin(B));
    std::copy(std::begin(A), std::end(A), std::begin(C));
    std::copy(std::begin(A), std::end(A), std::begin(D));

    // printtable(A, n);
    // QUICKSORT dla losowej
    clock_t startquick = clock();
    quicksort(A, 0, n-1);
    clock_t stopquick = clock();

    
    printf( "Czas dla tablicy losowej - quicksort: %lu ms\n", stopquick - startquick );
    
    // printtable(B, n);
    // MERGE-SORT dla losowej
    clock_t startmerge = clock();
    mergeSort(B, 0, n-1);
    clock_t stopmerge = clock();

    printf( "Czas dla tablicy losowej - merge-sort: %lu ms\n", stopmerge - startmerge );

    // printtable(C, n);
    // HEAPSORT dla losowej
    clock_t startheap = clock();
    heapsort(C, n);
    clock_t stopheap = clock();

    printf( "Czas dla tablicy losowej - heapsort: %lu ms\n", stopheap - startheap );

    // printtable(D, n);
    // INSERT SORT dla losowej
    clock_t startinsert = clock();
    insertSort(D, n);
    clock_t stopinsert = clock();

    printf( "Czas dla tablicy losowej - insertsort: %lu ms\n", stopinsert - startinsert );

    // tablica posortowana
    int E[n];
	for (int i = 0; i <= n; i++)
	{
	    E[i]= i;
	}
    int F[n];
    int G[n];
    int H[n];
    std::copy(std::begin(E), std::end(E), std::begin(F));
    std::copy(std::begin(E), std::end(E), std::begin(G));
    std::copy(std::begin(E), std::end(E), std::begin(H));
	
    // printtable(A, n);
    // QUICKSORT dla posortowanej
    clock_t startquick1 = clock();
    quicksort(E, 0, n-1);
    clock_t stopquick1 = clock();

    
    printf( "\nCzas dla tablicy posortowanej - quicksort: %lu ms\n", stopquick1 - startquick1 );
    
    // printtable(B, n);
    // MERGE-SORT dla posortowanej
    clock_t startmerge1 = clock();
    mergeSort(F, 0, n-1);
    clock_t stopmerge1 = clock();

    printf( "Czas dla tablicy posortowanej - merge-sort: %lu ms\n", stopmerge1 - startmerge1 );

    // printtable(C, n);
    // HEAPSORT dla posortowanej
    clock_t startheap1 = clock();
    heapsort(G, n);
    clock_t stopheap1 = clock();

    printf( "Czas dla tablicy posortowanej - heapsort: %lu ms\n", stopheap1 - startheap1 );

    // printtable(D, n);
    // INSERT SORT dla posortowanej
    clock_t startinsert1 = clock();
    insertSort(H, n);
    clock_t stopinsert1 = clock();

    printf( "Czas dla tablicy posortowanej - insertsort: %lu ms\n", stopinsert1 - startinsert1 );
    
    // tablica odwrotna
    int	I[n];
	for (int i = 0; i <= n; i++)
	{
	    I[i]= i;
	}

    int J[n];
    int K[n];
    int L[n];
    std::copy(std::begin(I), std::end(I), std::begin(J));
    std::copy(std::begin(I), std::end(I), std::begin(K));
    std::copy(std::begin(I), std::end(I), std::begin(L));
	
	// printtable(A, n);
    // QUICKSORT dla odwrotnej
    clock_t startquick2 = clock();
    quicksort(I, 0, n-1);
    clock_t stopquick2 = clock();

    
    printf( "\nCzas dla tablicy odwrotnej - quicksort: %lu ms\n", stopquick2 - startquick2 );
    
    // printtable(B, n);
    // MERGE-SORT dla odwrotnej
    clock_t startmerge2 = clock();
    mergeSort(J, 0, n-1);
    clock_t stopmerge2 = clock();

    printf( "Czas dla tablicy odwrotnej - merge-sort: %lu ms\n", stopmerge2 - startmerge2 );

    // printtable(C, n);
    // HEAPSORT dla odwrotnej
    clock_t startheap2 = clock();
    heapsort(K, n);
    clock_t stopheap2 = clock();

    printf( "Czas dla tablicy odwrotnej - heapsort: %lu ms\n", stopheap2 - startheap2 );

    // printtable(D, n);
    // INSERT SORT dla odwrotnej
    clock_t startinsert2 = clock();
    insertSort(L, n);
    clock_t stopinsert2 = clock();

    printf( "Czas dla tablicy odwrotnej - insertsort: %lu ms\n", stopinsert2 - startinsert2 );
}