#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

struct node *createnode(int data){
	struct node *x = (struct node *)malloc(sizeof(struct node *));
	x->data = data;
	x->left = x->right = NULL;

	return x;
}

void bfs(struct node *root){

	if(root==NULL)
		return;

	queue<struct node *>q;
	q.push(root);

	while(q.empty()==false){

		struct node *temp = q.front();
		cout<<temp->data<<"\n";
		q.pop();

		if(temp->left!=NULL){
			q.push(temp->left);
		}

		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}
	return;
}

int main(){

	struct node *y = createnode(1);
	y->left = createnode(2);
	y->right = createnode(3);
	y->left->left = createnode(4);
	y->left->right = createnode(5);
	y->right->left = createnode(6);
	y->right->right = createnode(7);

	bfs(y);

	return 1;
}