#include<bits/stdc++.h>
using namespace std;

struct Trie{
	int count;
	int eow;
	struct Trie *next[26];
}
struct Trie *root,pool[10000000];

char str[100000];
int index = 0;

// creates Node
struct Trie *getNode(){
	struct Trie *temp = &pool[index++];
	temp->count = 0;
	temp->eow = 0;
	return temp;
}

// inserts the strings in the Trie DS
void insert(struct Trie *node, char*s){

	for(;*s!='\0';s++){
		char c = *s - 'a';
		if(!node->next[c]){
			node->next[c] = getNode();
		}
		node->next[c]->count++;
		node = node->next[c];
	}

}

// searches if substring is present and returns in how many strings
int search(struct Trie *node,char *s){

	for(;*s!='\0';s++){
		char c = *s - 'a';
		if(!node->next[c])
			return 0;
		node = node->next[c];
	}
	return node->count;
}

// checks whether the complete string is present in the dictionary
int present(struct Trie *node,char *s){

	for(;*s!='\0';s++){
		char c = *s - 'a';
		if(!node->next[c])
			return 0;
		node = node->next[c];
	}
	
	if(node->eow >= 1){
		return 1;
	}
	else
		return 0;
}

int main(){

	int n;  //no.of words in the dictionary
	root = getNode();
	for(int i=0;i<n;i++){
		cin>>str;
		insert(root,str);
	}
	int q;
	cin>>q; //no. of Querries
	for(int i=0;i<q;i++){
		cin>>str;
		int count = search(root,str); 
		int p = present(root,str);
		cout<<count<<" "<<p<<"\n";
	}
	return 0;

}