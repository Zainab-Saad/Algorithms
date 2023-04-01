#include<stdlib.h>
#include <bits/stdc++.h>
#include<chrono>
#include<iostream>
using namespace std;

int* bubbleSort(int array[], int size){
    for(int i = 0; i < size - 1; i++){
        bool swapping = false;
        for(int j = 0; j < size-i-1; j++){
            if(array[j] > array[j+1]){
                swapping = true;
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
        if(!swapping)
            break;
    }
    return array;
}

void testBubbleSort(){
    int array[] = {16, 15, 8, 6, 5};
    int* sortedArray = bubbleSort(array, size(array));
    // display the array
    for(int i = 0; i < size(array); i++){
        cout<<*(sortedArray+i)<<" ";
    }
}

int* insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){
        int temp = array[i], j = i-1;
        bool flag = false;
        for(; j >=0; j--){
            if(array[j] > temp){
                array[j+1] = array[j];
                flag = true;
            }else break;
        }
        if(flag)
            array[j+1] = temp;
    }
    return array;
}

void testInsertionSort(){
    int array[] = {5, 4, 10, 1, 6, 2};
    int* sortedArray = insertionSort(array, size(array));
    // display the array
    for(int i = 0; i < size(array); i++){
        cout<<*(sortedArray+i)<<" ";
    }
}

int* selectionSort(int array[], int size){
    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i+1; j < size; j++)
            if(array[j] < array[min])
                min = j;
        if(min != i){
            // swap the two entries
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
    return array;
}

void testSelectionSort(){
    int array[] = {5, 4, 3, 2, 1, 0, -1};
    int* sortedArray = selectionSort(array, size(array));
    // display the array
    for(int i = 0; i < size(array); i++){
        cout<<*(sortedArray+i)<<" ";
    }
}

void merge(int array[], int left, int mid, int right){
    // copy the elements of sublists to dynamic arrays
    int* firstSubArray = new int[mid-left+1];
    int* secondSubArray = new int[right-mid];
    int i, j, k;
    // copy the elements of array to new arrays
    for(i = 0; i <= mid-left; i++)
        firstSubArray[i] = array[i+left];
    for(i = 0; i <= right-mid-1; i++)
        secondSubArray[i] = array[mid+1+i];

    i = 0, j = 0;
    for(k = left; k <= right; k++){
        if(i <= mid-left && j <= right-mid-1){
            if(firstSubArray[i] <= secondSubArray[j]){
                array[k] = firstSubArray[i];
                i++;
            }
            else{
                array[k] = secondSubArray[j];
                j++;
            }
        } 
        else{
            break;
        }
    }

    // if any element left in the sublists, copy to the array
    while(i != mid-left+1){
        array[k] = firstSubArray[i];
        k++;
        i++;
    }
    while(j != right-mid){
        array[k] = secondSubArray[j];
        k++;
        j++;
    }
    // delete dynamic arrays 
    delete[] firstSubArray;
    delete[] secondSubArray;

}

void mergeSort(int array[], int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        mergeSort(array, left, mid);
        mergeSort(array,mid+1, right);
        merge(array, left, mid, right);
    }
}

void testMergeSort(){
    
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right){
    int i = left+1, pivot = left;
    for(; i <= right; i++){
        if(i == pivot+1 && arr[i] < arr[pivot]){
            swap(&arr[i], &arr[pivot]);
            pivot++;
        }
        else if(arr[i] < arr[pivot]){
            int temp = arr[i];
            arr[i] = arr[pivot+1];
            arr[pivot+1] = arr[pivot];
            arr[pivot] = temp;
            pivot++; 
        }
    }
    return pivot;
}


void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}

void quickSortTest(){
}

int main(){
    quickSortTest();
    return 0;
}
