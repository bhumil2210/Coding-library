//https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>adj;
vector<int>dist;
int INF = 9999;

void addedge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    
}

void bellmanford(int v,int E){
    
    for(int i=0;i<v;i++){
        dist[i] = INF;
    }
    int src=0;
    dist[src] = 0;
    
    for(int i=1;i<=v-1;i++){
        for(int j=0;j<v;j++){
            for(auto it = adj[j].begin();it!=adj[j].end();it++){
                int v = it->first;
                int w = it->second;
                
                if(dist[j]!=INF && dist[j]+w<dist[v]){
                    dist[v] = dist[j] + w;
                }
            }
        }
    }
    
    
    for(int i=1;i<=v-1;i++){
        for(int j=0;j<v;j++){
            for(auto it = adj[j].begin();it!=adj[j].end();it++){
                int v = it->first;
                int w = it->second;
                
                if(dist[j]!=INF && dist[j]+w<dist[v]){
                    cout<<"Negative cycle exists";
                    return;
                }
            }
        }
    }
    
    for(int i=0;i<v;i++){
        cout<<dist[i]<<endl;
    }
    
}

int main(){
    
    int v = 5;
    int E = 8;
    adj.assign(v,vector<pair<int,int>>());
    dist.assign(v,INF);
    
    addedge(0,1,-1);
    addedge(0,2,4);
    addedge(1,2,3);
    addedge(1,3,2);
    addedge(1,4,2);
    addedge(3,2,5);
    addedge(3,1,1);
    addedge(4,3,-3);
    
    bellmanford(v,E);
    
    return 1;
}