#include<bits/stdc++.h>
using namespace std;

vector<bool> visited; 
vector<vector<int>> g; 

void addedge(int a, int b) 
{ 
    g[a].push_back(b); 
}

void dfs(int root){

	stack<int>s;
	s.push(root);
	visited[root] = true;
	cout<<root<<"\t";

	while(s.empty()==false){

		int x = s.top();
		int i;
		
		for(i=0;i<g[x].size();i++){
		    if(!visited[g[x][i]]){
		        s.push(g[x][i]);
		        visited[g[x][i]] = true;
		        cout<<g[x][i]<<"\t";
		        break;
		    }
		}
		
		if(i==g[x].size()){
		    s.pop();
		}

	}

}


int main(int argc, char const *argv[])
{
	
    int n=5;
    visited.assign(n, false); 
    g.assign(n, vector<int>());
	

    addedge(0,1);
    addedge(0,2);
    addedge(1,3);
    addedge(2,4);
    addedge(3,4);

    dfs(0);

	return 0;
}