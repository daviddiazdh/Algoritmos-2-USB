#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

vector<int> MAX_HEAPIFY(vector<int> A, int i, int n){
    int largest;
    int l = i*2 + 1; 
    int r = i*2 + 2;

    if(l < n && A[l] > A[i]){
        largest = l;
    } else {
        largest = i;
    }

    if(r < n && A[r] > A[largest]){
        largest = r;
    }

    if(largest != i){
        int temp;
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        A = MAX_HEAPIFY(A, largest, n);
    }

    return A;
}

vector<int> BUILD_MAX_HEAP(vector<int> A){
    float n = A.size();
    for(int i = floor(n/2) - 1; i >= 0; i--){
        A = MAX_HEAPIFY(A, i, n);
    }

    return A;
}

vector<int> HEAP_SORT(vector<int> A){

    A = BUILD_MAX_HEAP(A);
    int n = A.size();
    for(int i = n - 1; i >= 1; i--){
        int temp;
        temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        A = MAX_HEAPIFY(A, 0, i);
    }
    
    return A;
}

int main(){
    
}
