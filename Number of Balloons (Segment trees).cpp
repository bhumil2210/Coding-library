#include<bits/stdc++.h>
using namespace std;

void build(int node,int start,int end,int a[],int* tree){

	if(start==end){
		tree[node] = a[start]
	}
	else{

		int mid = (start+end)/2;

		build(2*node+1,start,mid,a,tree);

		build(2*node+2,mid,end,a,tree);

		tree[node] = min(tree[2*node+1],tree[2*node+2]);

	}
}

int search(int node,int start,int end,int l,int r,int* tree){

	if(r<start || l>end){
		return 0;
	}

	if(l<=start && r>=end){
		return tree[node];
	}

	int mid = (start+end)/2;
	int x1 = search(2*node+1,start,mid,l,r,tree);
	int x2 = search(2*node+2,mid,end,l,r,tree);
	return min(x1,x2);
}

void update(int node,int start,int end,int id,int val,int* tree,int a[]){

	if(start==end){
		a[id] =  val;
		tree[id] = val;
	}
	else{

		int mid = (start+end)/2;
		if(start<=idx  && idx<=end){
			update(2*node+1,start,mid,id,val,tree,a);
		}
		else{
			update(2*node+2,mid,end,id,val,tree,a);	
		}

		tree[node] = min(tree[2*node*1],tree[2*node+2]);

	}

}

int main(int argc, char const *argv[])
{
	
	int n,q;
	cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];

	int h = int(ceil(log2(n)));
	int max_size = 2*(int)pow(2,h)-1;

	int *tree[max_size];

	build(0,0,n-1,a,tree);

	int l,r;
	char w;
	for(int u=0;u<q;u++){
		cin>>w>>l>>r;
		if(w=="q")
			cout<<search(0,0,n-1,l,r,tree);
		else if(w=="u")
			update(0,0,n-1,l,r,tree,a);
	}

	return 0;
}