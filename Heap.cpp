// min heap
#include <bits/stdc++.h>
using namespace std;
vector<int>v={51, 23, 12, 9, 30, 2, 50};
void heap(int i,int len){
    int indexleft,indexright,j,small,right=9999,left=999;
    indexleft=2*i+1;
    indexright=2*i+2;
    if(indexright<len){
        right=v[indexright];
    }
    if(indexleft<len){
        left=v[indexleft];
    }
    if(right>=left){
        small=left;
        j=indexleft;
    }
    else{
        small=right;
        j=indexright;
    }
   
    if(v[i]>v[j]){
        swap(v[i],v[j]);
        if(j!=len && j*2+1<len && j!=i){
            heap(j,len);
    }
    }
}
void insert(int n){
    v.push_back(n);
    int parent=(v.size()-2)/2;
    int j=v.size()-1;
    while(j>=0){
        parent=(j-1)/2;
        if(v[parent]>v[j]){
            swap(v[parent],v[j]);
        }
        else{
            break;
        }
        j=parent;
    }
}
void delete_minimum(){
    int loc=v[0];
    v[0]=v[v.size()-1];
    v.pop_back();
    heap(0,v.size());
   
}
int main() {
    int len=v.size();
    for(int i=(len/2)-1;i>=0;i--){
        heap(i,len);
    }
    insert(1);
    delete_minimum();
    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<"\t";
    }
   
}

