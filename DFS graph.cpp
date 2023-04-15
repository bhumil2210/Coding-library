#include<bits/stdc++.h>
using namespace std;
int adjacency_list[10][10];
bool visited[10];

void addedge(int u,int v){

	adjacency_list[u][v] = 1;

}

void recurDSFUtil(int i, bool *visited){

	for(auto it=adjacency_list[i].begin();it!=adjacency_list.end()){
		if(visited[*it]==false){
			cout << *it << '\n';
			visited[*it]=true;
			recurDSFUtil(*it,visited);
		}
	}

}

void recurDSF(int n){
	bool visited[n];
	for(int i=0;i<n;i++) visited[i]=false;

	for(int i=0;i<n;i++){
		if(visited[i]==false){
			cout << i<<"\n";
			visited[i]=true;
			recurDSFUtil(i,visited);
		}
	}
}

void dfs(int root){

	stack<int>s;
	s.push(root);
	visited[root]=true;
	cout<<root<<"\t";

	while(s.empty()==false){

		int x = s.top(),i=0;
		int size = sizeof(adjacency_list[0])/sizeof(adjacency_list[0][0]);
		for(i=0;i<size;i++){
			if(adjacency_list[x][i]==1 && visited[i]==false){
				s.push(i);
				visited[i]=true;
				cout<<i<<"\t";
				break;
			}
		}
		if(i==size){
			s.pop();
		}

	}

}


int main(int argc, char const *argv[])
{
	
	for(int i=0;i<10;i++){
		visited[i]=false;
	}

    for(int m=0;m<10;m++){
        for(int n=0;n<10;n++){
            adjacency_list[m][n] = 0;
        }
    }
	
	addedge(0,1);
	addedge(0,2);
	addedge(1, 2); 
    addedge(2, 0); 
    addedge(2, 3); 
    addedge(3, 3);

    dfs(2);

	return 0;
}