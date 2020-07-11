#include<bits/stdc++.h>
using namespace std;

vector<bool> visited; 
vector<vector<int>> g; 

void addedge(int a, int b) 
{ 
    g[a].push_back(b); 
}


void bfs(int start){

	queue<int>q;
	q.push(start);
	visited[start] = true;
	while(q.empty()==false){

		int m = q.front();
		cout<<m<<"\t";
		q.pop();
		
		for(auto i=g[m].begin();i!=g[m].end();i++){
		    if(!visited[*i]){
		        q.push(*i);
		        visited[*i] = true;
		    }
		}
		

	}

}

int main(){
    
    int n=5;
    visited.assign(n, false); 
    g.assign(n, vector<int>());
	
    
    addedge(0,1);
    addedge(0,2);
    addedge(1,3);
    addedge(2,4);
    addedge(3,4);

    bfs(0);


	return 1;
}