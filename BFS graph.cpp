#include<bits/stdc++.h>
using namespace std;
int adjacency_list[10][10];
bool visited[10];

void addedge(int u,int v){

	adjacency_list[u][v] = 1;

}

void bfs(int start){

	queue<int>q;
	q.push(start);
	visited[start] = true;
	while(q.empty()==false){

		int m = q.front();
		cout<<m<<"\t";
		q.pop();
		int size = sizeof(adjacency_list[0])/sizeof(adjacency_list[0][0]);
		for(int j=0;j<size;j++){

			if(adjacency_list[m][j]!=0 && visited[j]==false){
			    
				q.push(j);
				visited[j] = true;	
			}
			
		}

	}

}

int main(){
	
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

    bfs(2);

	return 1;
}