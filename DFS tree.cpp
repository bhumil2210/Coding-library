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

void preorder(struct node *root){

	if(root==NULL)
		return;

	cout<<root->data<<"\n";

	preorder(root->left);

	preorder(root->right);

}

void inorder(struct node *root){

	if(root==NULL)
		return;

	inorder(root->left);

	cout<<root->data<<"\n";

	inorder(root->right);

}

void postorder(struct node *root){

	if(root==NULL)
		return;

	postorder(root->left);

	postorder(root->right);

	cout<<root->data<<"\n";

}


int main(){

	struct node *y = createnode(1);
	y->left = createnode(2);
	y->right = createnode(3);
	y->left->left = createnode(4);
	y->left->right = createnode(5);
	y->right->left = createnode(6);
	y->right->right = createnode(7);

	preorder(y);
	inorder(y);
	postorder(y);

	return 1;

}