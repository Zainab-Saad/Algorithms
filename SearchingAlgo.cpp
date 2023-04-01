#include<iostream>
using namespace std;

int binarySearchIter(int array[], int sizeOfArray, int value){
    int l = 0, r = sizeOfArray - 1, mid;
    while(l <= r){
        mid = (l+r)/2;
        if(array[mid] == value) return mid;
        else if(array[mid] > value) r = mid-1; 
        else l = mid+1;
    }
    return -1;
}

int binarySearchRecur(int array[], int l, int r, int value){
    if(l > r) return -1;
    int mid = (l+r)/2;
    if(array[mid] == value) return mid;
    else if(array[mid] > value) return binarySearchRecur(array, l, mid-1, value);
    else return binarySearchRecur(array, mid+1, r, value);
}

int main(){
    int array[] {5, 9, 17, 23, 25, 45, 59, 63, 71, 89};
    int index = binarySearchIter(array, size(array), 0);
    cout<<index<<endl;
    index = binarySearchRecur(array, 0, size(array)-1, 0);
    cout<<index<<endl;
    return 0;
}