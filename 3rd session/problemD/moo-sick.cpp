
#include <iostream>
#include <bits/stdc++.h>

#define INF 20001

using namespace std;

int binarySearch(int arr[], int low, int high, int key);
int insertSorted(int arr[], int n, int key);
int deleteElement(int arr[], int n, int key);

int main(){
    int N, C; // N number of notes played, legth of the sequence
    cin >> N;
    int notes[N];
    for(int i=0; i<N; i++){
        cin >> notes[i];
    }
    
    cin >> C;
    int seq[C];
    for(int i=0; i<C; i++){
        cin >> seq[i];
    }
    if(C==0){
        return 0;
    }

    sort(seq, seq + C);

    int window[C];

    for(int i = 0; i<C; i++){
        window[i] = notes[i];
    }
    int res;
    int diff;
    // The idea : sort the sequence and for all windows sort the window ( this sort will not cost much as the initial window is )
    for ( int i = C; i<N+1; i++){
        sort(window, window+C);
        res = 1;
        diff = window[0] - seq[0];

        for(int i = 0; i <C; i++) {
            if(window[i] != seq[i]) { 
                res = 0;
            } else if ( diff != window[i] - seq[i]){
                res = 0;
            }
        }
        if (!res){
            res = 1;
            for(int i = 0; i <C; i++) {
                if ( diff != window[i] - seq[i]){
                    res = 0;
                }
            }
        }


        if(res){
            cout << i-C+1 << endl;
        }   
        deleteElement(window, C, notes[i-C]);
        insertSorted(window, C, notes[i]);
    }
    return 0;
}

int binarySearch(int arr[], int low, int high, int key) 
{ 
    if (high < low) 
        return -1; 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid]) 
        return mid; 
    if (key > arr[mid]) 
        return binarySearch(arr, (mid + 1), high, key); 
    return binarySearch(arr, low, (mid - 1), key); 
} 

int insertSorted(int arr[], int n, int key) {
    int i; 
    for (i = n - 1; (i >= 0 && arr[i] > key); i--) 
        arr[i + 1] = arr[i]; 
  
    arr[i + 1] = key; 
  
    return (n + 1);
}

int deleteElement(int arr[], int n, int key) 
{ 
    // Find position of element to be deleted 
    int pos = binarySearch(arr, 0, n - 1, key); 
  
    if (pos == -1) { 
        cout << "Element not found"; 
        return n; 
    } 
  
    // Deleting element 
    int i; 
    for (i = pos; i < n - 1; i++) 
        arr[i] = arr[i + 1]; 
    
    arr[n-1] = INF;
    return n - 1; 
}