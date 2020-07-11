/*

You are given a binary tree rooted at 1. You have to find the mirror image of any node qi 
about node 1. If it doesn't exist then print -1.
Input:
First line of input is N and Q.
Next N-1 line consists of two integers and one character first of whose is parent node , 
second is child node and character "L" representing Left child and "R" representing right child.
Next Q lines represents qi.
Output:
For each qi print it mirror node if it exists else print -1. 
NOTE: 1 is mirror image of itself.
Constraints:
1 <= N <= 103
1<= Q <= 103

SAMPLE INPUT 
10 8
1 2 R
1 3 L
2 4 R
2 5 L
3 6 R
3 7 L
5 8 R
5 9 L
7 10 R
2
5
3
6
1
10
9
4


SAMPLE OUTPUT 
3
6
2
5
1
-1
-1
7


*/

// ----------------My code-------------------
#include<bits/stdc++.h>
using namespace std;

struct Node{
  
  int data;
  struct Node *left,*right;
  char *path;
    
};

struct Node* createnode(int data){
 
 struct Node *x = (struct Node*)malloc(sizeof(struct Node));
 x->left = x->right = NULL;
 x->data = data;
 
 return x;
    
}

int main(){
    
    int n,q;
    int parent,child;
    char direction;
    cin>>n>>q;
    
    struct Node *head,*arr[1001];
    head = createnode(1);
    head->path = "";
    arr[1] = head;
    
    for(int i=0;i<n;i++){
        cin>>parent>>child>>direction;
        struct Node *temp = arr[parent];
        if(direction='L'){
            temp->left = createnode(child);
            arr[child] = temp->left;
            temp->left->path = strcat(temp->path,"L");
        }
        else if(direction=='R'){
            temp->right = createnode(child);
            arr[child] = temp->right;
            temp->right->path = strcat(temp->path,"R");
        }
        
    }

    int val;
    for(int i=0;i<q;i++){

        cin>>val;
        bool present=true;
        char *path = arr[val]->path;
        struct Node *ext=head;

        for(int k=0;path[i] && ext;k++){

            if(path[i]=='L'){
                ext = ext->right;
            }
            else if(path[i]=='R'){
                ext = ext->left;
            }
            else if(path[i]==NULL){
                cout<<"-1";
                present = false;
                break;
            }

        }
        if(present){
            cout<<ext->data<<"\n";
        }

    }
    return 1;
}

// ------------someone else's-------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
struct Node
{
    int data;
    char *path;
    struct Node *lChild;
    struct Node *rChild;
};
 
struct Node *createNode(int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->lChild = temp->rChild = NULL;
    temp->data = data;
 
    return temp;
}
 
char *concatenate(char *a, char *b)
{
    char *path = malloc(strlen(a) + strlen(b) + 1);
    strcpy(path, a);
    strcat(path, b);
 
    return path;
}
 
int main()
{
    int i;
    int N, Q;
    int index, child;
    char state;
    struct Node *head, *head1;
 
    struct Node *ar[1001];
 
    scanf("%d %d", &N, &Q);
 
    head = createNode(1);
    head->path = "";
    ar[1] = head;
 
    while(--N) {
 
        scanf("%d %d %c", &index, &child, &state);
 
        struct Node *temp = ar[index];
 
        switch(state) {
 
            case 'L':
                temp->lChild = createNode(child);
                ar[child] = temp->lChild;
                temp->lChild->path = concatenate(temp->path, "L");
 
                break;
 
            case 'R':
                temp->rChild = createNode(child);
                ar[child] = temp->rChild;
                temp->rChild->path = concatenate(temp->path, "R");
 
                break;
        }// end switch()
    }// end while()
 
    while(Q--) {
 
        scanf("%d", &child);
        char *path = ar[child]->path;
        struct Node *temp = head;
        bool present = true;
 
        for(i = 0; path[i] && temp; i++) {
 
            if(path[i] == 'R') {
                temp = temp->lChild;
            }
            else {
                temp = temp->rChild;
            }// end if
 
            if(temp == NULL) {
                printf("-1\n");
                present = false;
                break;
            }// end if
 
        }// end for
 
        if(present) {
            printf("%d\n", temp->data);
        }// end if
    }
 
    //inorder(head); printf("\n");
 
    return 0;
}