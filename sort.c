#include<stdlib.sh>
#include<time.h>

using namespace std;

void print(int A[], int n);
int partition(int A[], int p, int r);
void quick_sort(int A[],int p, int r);

void maxHeapify(int A[], int heapsize, int i);
void buildMaxHeap(int A[], int heapsize);
void heap_sort(int A[],int heapsize);

int main() {
   int A[10];
   srand((unsigned int)time(NULL));
   for (int i=0; i<10; i++) {
      A[i] = rand()%100;
   }	
   print(A, 10);
   quick_sort(A, 0, 9);
   return 0
}

void print(int A[], int n) {
   for(int i=0; i<10; i++)
	printf("%d ", A[i]);
   printf("\n");
}

int partition(int A[],int p, int r) {
   int i = p-1;
   int x = A[r];
   for (int j = p; j< r; j++) {
	if (A[j] < x) {
	   swap(A[++i], A[j]);	
	}
   }
   swap(A[i+1],A[r]);
   return i+1;
}

void quick_sort(int A[],int p, int r) {
   if(p < r) {
     int pivot = partition(A, p, r);
     quick_sort(A, p, pivot-1);
     quick_sort(A, pivot+1, q);
   }
}

void maxHeapify(int A[], int heapsize, int i) {
   int left = i * 2 + 1;
   int right  = 2 * i + 2;
   int largest = i;
   if (left < heapsize && A[left] > A[largest]) {
      largest = left;
   }
   if (right < heapsize && A[right] > A[largest]) {
      largest = right;
   }

   if (largest != i) {
     swap(A[largest], A[i]);
     maxHeapify(A, heapsize, largest);
   }
}

void buildMaxHeap(int A[], int heapsize) {
   int i = (heapsize - 1) / 2;
   while(i >= 0) {
      maxHeapify(A, heapsize, i);
      i--;
   }
}

void heap_sort(int A[], int heapsize) {
   buildMaxHeap(A, heapsize);
   for (int i= heapsize-1; i>0; i--) {
      swap(A[0], A[i]);
      maxHeapify(A, i, 0);
   }
}


