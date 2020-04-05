// PRIM'S ALGORITHM

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair; 

vector<vector<pair<int,int>>>adj;
vector<int>Key;

//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> visited;
//priority_queue< iPair, vector <iPair>> visited; 
set<pair<int,int>> visited;

// To store parent array which in turn store MST 
vector<int> parent; 

// To keep track of vertices included in MST 
vector<bool>MST; 

int INF = 9999;

void addedge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}


void generateMST(int n){
    
    int src=0;
    visited.insert(make_pair(0,src));
    Key[src] = 0;
    
    while(!visited.empty()){
        pair<int,int> p = *(visited.begin());
        int x = p.second;
        visited.erase(visited.find(p));
        
        MST[x] = true;
        
        for(auto i = adj[x].begin();i!=adj[x].end();i++){
            
            int v = i->first;
            int w = i->second;
            
            if(MST[v]==false && Key[v]>w){
                Key[v]=w;
                visited.insert(make_pair(w,v));
                parent[v]=x;
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }
    
    
}

int main(){
    
    int v=9;
    adj.assign(v,vector<pair<int,int>>());

    Key.assign(v,INF);
    parent.assign(v,-1);
    MST.assign(v,false);
    
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
	
	generateMST(v);
    
    return 1;
}