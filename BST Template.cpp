// Goonj This file contains code for create,search, and delete node of BST along with bfs,inorder,pre and post.
// Sexy code hai 
// Hope you like it

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node *root;

struct node *new_node(int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    
    return ptr;
}

// BFS TRAVERSAL
void bfs(struct node *root){

	if(root==NULL)
		return;

	queue<struct node *>q;
	q.push(root);

	while(q.empty()==false){

		struct node *temp = q.front();
		cout<<temp->data<<"\t";
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

void postorder(struct node *root){

	if(root==NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<"\t";

}

void preorder(struct node *root){

	if(root==NULL)
		return;

	cout<<root->data<<"\t";
	preorder(root->left);
	preorder(root->right);
	
}

void inorder(struct node *root){
    
	if(root==NULL)
	    return;

	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
    
}

// INSERTING A NODE IN BST
struct node *insert(struct node *temp,int data){
    
    if(temp==NULL){
        return new_node(data);
    }
    
    if(data<temp->data){
        temp->left = insert(temp->left,data);
    }
    if(data>temp->data){
        temp->right = insert(temp->right,data);
    }
    
    return temp;
}

// SEARCHING NODE IN BST
struct node *search(struct node *temp,int val){
    
    if(temp==NULL || temp->data==val){
        return temp;
    }
    
    if(val<temp->data){
        temp = search(temp->left,val);
    }
    else if(val>temp->data){
        temp = search(temp->right,val);    
    }
        
    return temp;
}

// FINDING MINIMUM VALUE IN SUBTREE 
struct node *min_val_node(struct node *min_node){
    
    struct node *curr=min_node;
    while(curr!=NULL && curr->left!=NULL){
        curr = curr->left;
    }
    
    return curr;
    
}

// DELETE NODE WITH GIVEN VALUE
struct node *delete_node(struct node *temp,int val){
    
    if(temp==NULL){
        return temp;
    }
    
    if(val<temp->data){
        temp->left = delete_node(temp->left,val);
    }
    else if(val>temp->data){
        temp->right = delete_node(temp->right,val);
    }
    else{
        if(temp->left==NULL){
            struct node *ptr = temp->right;
            delete(temp);
            return ptr;
        }
        else if(temp->right==NULL){
            struct node *ptr = temp->left;
            delete(temp);
            return ptr;
        }
        
        struct node *min = min_val_node(temp->right);
        temp->data = min->data;
        temp->right = delete_node(temp->right,min->data);
    }
    
    return temp;
    
}

int main(){
    int a[]={4,1,5,2,6,3};
    int n = sizeof(a)/sizeof(a[0]);   
    root = insert(root,a[0]);
    for(int i=1;i<n;i++){
        root = insert(root,a[i]);
    };
    bfs(root);
    cout<<endl;
    
    int val = 23;  //value to search in a given BST
    struct node *s = search(root,val);
    if(s==NULL){
        cout<<"Value is not present in BST\n";
    }
    else if(s->data==val){
        cout<<"Value present\n";
    }
    
    int val_to_delete = 4;  //node to delete
    root = delete_node(root,val_to_delete);
    bfs(root);
    cout<<endl;
    
    return 1;
    
}

    //     4
    //   / \
    //   1   5
    //   \   \
    //     2   6
    //      \
    //       3