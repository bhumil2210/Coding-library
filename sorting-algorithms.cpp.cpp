#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void printArr(int arr[],int n){
    
    cout << "The sorted array is...\n";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}


void insertion_sort(int arr[],int n){
    
    time_t start,end;
    
    time(&start);
    
    for(int i=1;i<n;i++){
        
        int val = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>val){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=val;
    }
    printArr(arr,n);
}

void merge(int arr[], int l, int m, int r){
    
    int len1 = m - l + 1;
    int len2 = r - m;
 
    int left[len1], right[len2];
 
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < len2; j++)
        right[j] = arr[m + 1 + j];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < len1 && j < len2){
        
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesortUtil(int arr[], int l, int r){
    
    if(l>=r){
        return;
    }
    
    int m = l+(r-l)/2;
    mergesortUtil(arr,l,m);
    mergesortUtil(arr,m+1,r);
    merge(arr,l,m,r);
}

void mergesort(int arr[], int n){
    mergesortUtil(arr,0,n-1);
    printArr(arr,n);
}

int findPivot(int arr[], int l, int r){
    
    int pivot = arr[r];
    
    int i = l-1;
 
    for(int j = l; j <= r - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i+1;
}

void quicksortUtil(int arr[], int l, int r){
    
    if(l < r){
        int part = findPivot(arr, l, r);
 
        quicksortUtil(arr,l,part-1);
        quicksortUtil(arr,part+1,r);
    }
}

void limitedQuickSort(int arr[], int l, int r, int k){
    if(r-l > k){
        int part = findPivot(arr,l,r);
        limitedQuickSort(arr,l,part-1,k);
        limitedQuickSort(arr,part+1,r,k);
    }
}

void quicksort(int arr[], int n){
    quicksortUtil(arr,0,n-1);
    printArr(arr,n);
}

void quick_insertion(int arr[], int n, int k){
    limitedQuickSort(arr,0,n-1,k);
    insertion_sort(arr,n);
}

int main() {
    
    int n,k;
    cout << "Enter the number of random natural numbers to sort...\n";
    cin>>n;
    cout << "Enter k\n";
    cin>>k;
    
    int a[n];
    for(int i=0;i<n;i++){
        a[i] = rand()%100;
    }
    
    cout << "The "<<n<<" randomly generated naturals are...\n";
    for(int i=0;i<n;i++){
        cout << a[i] <<" ";
    }
    cout << "\n\n";
    
    
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Insertion Sort...\n";
    start = high_resolution_clock::now();
    insertion_sort(a,n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "The running time is " << duration.count() << " miliseconds";
    cout << "\n\n";
    
    cout << "Merge Sort...\n";
    start = high_resolution_clock::now();
    mergesort(a,n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "The running time is " << duration.count() << " miliseconds";
    cout << "\n\n";
    
    cout << "Quick Sort...\n";
    start = high_resolution_clock::now();
    quicksort(a,n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "The running time is " << duration.count() << " miliseconds";
    cout << "\n\n";
    
    cout << "Quick Insertion Sort...\n";
    start = high_resolution_clock::now();
    quick_insertion(a,n,k);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "The running time is " << duration.count() << " miliseconds";
    cout << "\n\n";
}