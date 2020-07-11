#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>visited;
void addedge(int a,int b){
    graph[a].push_back(b);
}
void travesal(int start,int n){
    vector<int>::iterator i;
    queue<int>q;
    int flag=0;
    q.push(start);
    visited[start]=true;
    int j=0;
   
    while(j<n){
        int u=q.front();
        for(i=graph[u].begin();i!=graph[u].end();i++){
            int y=*i;
            if(visited[*i]==true){
                // cout<<"here34";
                cout<<"looop present";
                flag=12;
                break;
               
            }
            else{
                // cout<<"here";
                visited[*i]=true;
                q.push(*i);
            }
           
        }
        if(i==graph[u].end()){
                // cout<<"here1";
                q.pop();
            }
        if(flag==12){
            // cout<<"here2";
            break;
        }
    j++;
    }
    if(flag==0){
        cout<<"no loop present";
    }
   
}
int main(){
    int n=6;
    visited.assign(n,false);
    graph.assign(n,vector<int>());
    addedge(0,1);
    addedge(1,2);
    addedge(2,3);
    addedge(3,4);
    addedge(4,5);
    // addedge(5,6);
    travesal(0,n);
    return 1;
}
