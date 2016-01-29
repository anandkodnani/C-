#include <iostream>
#include <cstdio>
using namespace std;

struct MaxHeap {
  int size;
  int *array;
};

void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapify(MaxHeap *maxHeap, int index) {
  int largest = index;
  int left =  2 * index + 1;
  int right = 2 * index + 2;
  // See if the left node exists and is greater than root.
  if (left < maxHeap->size && maxHeap->array[left] >
      maxHeap->array[largest])
    largest = left;
  // See if the right node exists and is greater than root.
  if (right < maxHeap->size && maxHeap->array[right] >
      maxHeap->array[largest])
    largest =  right;

  if (largest != index) {
    Swap(&(maxHeap->array[index]), &(maxHeap->array[largest]));
    maxHeapify(maxHeap, largest);
  }
}

MaxHeap *createAndBuild(int *arr, int size) {
  MaxHeap *maxHeap = new MaxHeap;
  maxHeap->size = size;
  maxHeap->array = arr;

  for (int i = (maxHeap->size)/2 - 1; i >= 0; --i)
    maxHeapify(maxHeap, i);
  return maxHeap;
}

void heapSort(int *arr, int size) {
  MaxHeap *maxHeap = createAndBuild(arr, size);

  while (maxHeap->size > 1) {
    // Larget value is at the root node;
    // Swap the largest value and last element.
    Swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
    --maxHeap->size;
    maxHeapify(maxHeap, 0);
  }
}

void printArray(int *arr, int size) {
  for (int i  = 0; i < size; ++i)
    cout << " " << arr[i];
}

/* Driver piostrearogram to test above functions */
int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int size = sizeof(arr)/sizeof(arr[0]);
 
  printf("Given array is \n");
  printArray(arr, size);
 
  heapSort(arr, size);
 
  printf("\nSorted array is \n");
  printArray(arr, size);
  return 0;
}
