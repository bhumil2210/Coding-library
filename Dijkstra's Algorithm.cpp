#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>adj;
vector<int>dist;
set<pair<int,int>>visited;
int INF = 99999;


void addedge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void shortestPath(int start,int n){
    visited.insert(make_pair(0,start));
    dist[start]=0;
    
    while(!visited.empty()){
        
        pair<int,int> temp = *(visited.begin());
        visited.erase(visited.begin());
        
        int u = temp.second;
 
        for(auto i=adj[u].begin();i!=adj[u].end();i++){
            
            int v = i->first;
            int w = i->second;
            
            if(dist[v] > dist[u] + w){
                
                if(dist[v]!=INF){
                    visited.erase(visited.find(make_pair(dist[v],v)));
                }
                
                dist[v] = dist[u] + w;
                visited.insert(make_pair(dist[v],v));
                
                
            }
            
        }
        
    }

    for (int i = 0; i < n; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
    
}

int main() {

    int n = 9;
    
    adj.assign(n,vector<pair<int,int>>());
    dist.assign(n,INF);
    
    addedge(0, 1, 4); 
	addedge(0, 7, 8); 
	addedge(1, 2, 8); 
	addedge(1, 7, 11); 
	addedge(2, 3, 7); 
	addedge(2, 8, 2); 
	addedge(2, 5, 4); 
	addedge(3, 4, 9); 
	addedge(3, 5, 14); 
	addedge(4, 5, 10); 
	addedge(5, 6, 2); 
	addedge(6, 7, 1); 
	addedge(6, 8, 6); 
	addedge(7, 8, 7);
	
	shortestPath(0,n); 

}