#include<iostream>
#include<vector>
using namespace std;

void pigeonHoleSort(int array[], int size){
    // find minimum and maximum elements in array[]
    int min = array[0];
    int max = array[0];
    for(int i = 0; i < size; i++){
        if(array[i] > max)
            max = array[i];
        else if(array[i] < min)
            min = array[i];
    }

    // find the range of elements 
    int range = max - min + 1;
    
    // create an array of pigeonholes
    // create array of vectors 
    // size of array is equal to range
    // each vector represent a pigeonhole that contains matching elements

    vector<int> holes[range];
    
    // traverse array[] and put each element in respective pigeonhole
    // push array[i] at holes[array[i] - min]

    for(int i = 0; i < size; i++){
        holes[array[i] - min].push_back(array[i]);
    }

    // traverse through all holes 
    // for each hole put elements back to original array
    int index = 0;
    for(int i = 0; i < range; i++){
        for(int j = 0; j < holes[i].size(); j++){
            array[index++] = holes[i][j];
        }
    }
}

struct node{
    int data;
    node* next = NULL;
};

void pigeonHoleSort(int array[], int size){
    // find the min and max element in array[]
    int min = array[0];
    int max = array[0];
    for(int i = 0; i < size; i++){
        if(array[i] < min)
            min = array[i];
        else if(array[i] > max)
            max = array[i];
    }

    // find the range of elements
    int range = max - min + 1;

    // create array of pigeonholes
    // pigeonholes at particular index of array store similar elements
    // create array of heads of linked list 
    // where each linked list is the pigeonholes of having same data

    node* holes[range];
    // initialize pointers to NULL
    for(int i = 0; i < range; i++){
        holes[i] = NULL;
    }
    for(int i = 0; i < size; i++){
        node* newNode = new node();
        newNode->data = array[i];
        if(holes[array[i]-min] == NULL){
            holes[array[i] - min] = newNode;
        }
        else{
            node* temp = holes[array[i]-min];
            while(temp->next != 0)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    
    // copy elements to original array at their right index 
    // initialize index = 0
    int index = 0;
    for(int i = 0; i < range; i++){
        node* temp = holes[i];
        while(temp != NULL){
            array[index++] = temp->data;
            temp = temp->next;
        }
    }
}

int main(){
    int arr[] = {8, 3, 2, 7, 4, 6, 8, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    pigeonHoleSort(arr, n);
 
    printf("Sorted order is : ");
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
 
    return 0;
}