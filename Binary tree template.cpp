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

struct node *create_BT(int a[],struct node *temp,int i,int n){
    
    if(i<n){
        struct node *p = new_node(a[i]);
        temp=p;
        
        temp->left = create_BT(a,temp->left,2*i+1,n);
        
        temp->right = create_BT(a,temp->right,2*i+2,n);
    }
    return temp;
}

void insert(struct node *root,int data){
    
    queue<struct node*>q;
    q.push(root);
    
    while(!q.empty()){
        struct node *ptr = q.front();
        q.pop();
        
        if(!ptr->left){
            ptr->left = new_node(data);
            break;
        }
        else{
            q.push(ptr->left);
        }
        
        if(!ptr->right){
            ptr->right = new_node(data);
            break;
        }
        else{
            q.push(ptr->right);
        }
        
    }

}

void delete_deepest_node(struct node *root, struct node *node_to_delete){
    
    queue<struct node *>q;
    q.push(root);
    
    while(!q.empty()){
        struct node *ptr = q.front();
        q.pop();
        
        if(ptr==node_to_delete){
            ptr=NULL;
            delete(ptr);
            return;
        }
        
        if(ptr->left){
            if(ptr->left==node_to_delete){
                ptr->left=NULL;
                delete(ptr->left);
                return;
            }
            else{
                q.push(ptr->left);
            }
        }
        
        if(ptr->right){
            if(ptr->right==node_to_delete){
                ptr->right=NULL;
                delete(ptr->right);
                return;
            }
            else{
                q.push(ptr->right);
            }
        }
    }
    
}

void delete_node(struct node *root,int data){
    
    if(root==NULL){
        cout<<"Tree doesn't exist";
    }
    
    if(root->left==NULL && root->right==NULL){
        if(root->data==data){
            root=NULL;
        }
        else{
            cout<<"value doesn't exist";
        }
    }
    struct node *data_node=NULL;
        
    queue<struct node *>q;
    q.push(root);
    struct node *ptr;
    
    while(!q.empty()){
        ptr = q.front();
        q.pop();
        
        if(ptr->data==data){
            data_node = ptr;
        }
        
        if(ptr->left){
            q.push(ptr->left);
        }
        if(ptr->right){
            q.push(ptr->right);
        }
    }
    
    if(data_node!=NULL){
        int x = ptr->data;
        delete_deepest_node(root,ptr);
        data_node->data=x;
    }
    else{
        cout<<"value doesn't exist";
    }
}

int main(){
    int a[]={1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    root = create_BT(a,root,0,n);
    inorder(root);
    cout<<endl;
    
    insert(root,7);
    inorder(root);
    cout<<endl;
    
    delete_node(root,4);
    inorder(root);
    cout<<endl;
    
    bfs(root);
    cout<<endl;
    
    return 1;
    
}