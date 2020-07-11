//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/
  
#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int>size;

bool find(int a, int b){
    
    if(arr[a]==arr[b])
        return true;
    else
        return false;   
}

int root(int i){
    
    while(arr[i] != i)
    {
        i = arr[i]; 
    }
    return i;
}


void union_op(int a,int b){
    
    int root_a = root(a);
    int root_b = root(b);
    if(size[root_a] < size[root_b])
    {
        arr[root_a] = arr[root_b];
        size[root_b] += size[root_a];
    }
    else
    {
        arr[root_b] = arr[root_a];
        size[root_a] += size[root_b];
    }

}

int main(){
    
    int n; // no. of nodes in the graph structure
    n = 6;
    arr.assign(n,1);
    size.assign(n,1);
    
    // initializing an array with node values
    // value indicates that particular node
    for(int i=0;i<n;i++){
        arr[i] = i;
    }
    
    // union operations
    union_op(0,1);
    union_op(1,2);
    union_op(3,2);
    
    // array after union operations
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
    
    //find operation
    cout<<find(1,3);
    return 1;
}



