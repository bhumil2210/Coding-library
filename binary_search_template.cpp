#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pair<long long int,long long int>, null_type,less< pair<long long int,long long int> >, rb_tree_tag,tree_order_statistics_node_update>
#define IOFAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)

#define pb push_back  
#define mp make_pair
#define F first
#define S second

int lower_b(int arr[], int l, int h,int key){
    
    while(l<h){
        int mid = l+(h-l)/2;
        
        if(key<=arr[mid]){
            h=mid;
        }
        else{
            l=mid+1;
        }
    }
    
    return l;
}

int upper_b_right(int arr[], int l, int h, int key){
    
    int index=-1;
    
    while(l<=h){
        int mid = l+(h-l)/2;
        
        if(key>=arr[mid]){
            l=mid+1;
        }
        else{
            index=mid;
            h=mid-1;
        }
    }
    
    return index;
}

int upper_b_left(int arr[], int l, int h, int key){
    
    int index=-1;
    
    while(l<=h){
        int mid = l+(h-l)/2;
        
        if(key<=arr[mid]){
            h=mid-1;
        }
        else{
            index=mid;
            l=mid+1;
        }
    }
    return index;
}

int main() {
    
    int a[] = {1,1,5};
    int key = 2;
    int size = 3;
    cout<<"At Index = "<<lower_b(a,0,size,key)<<"\n";
    cout<<"At Index = "<<upper_b_right(a,0,size,key)<<"\n";
    cout<<"At Index = "<<upper_b_left(a,0,size,key)<<"\n";
}