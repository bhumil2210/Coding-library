#include <bits/stdc++.h>
using namespace std;


class Node{
  
  public:
    vector<Node*> childNodes;
    vector<int> flatPuzzle;
    Node* parent;
    
    Node(vector<int> _flatPuzzle,Node* _parent){
        flatPuzzle = _flatPuzzle;
        parent = _parent;
    }
    
    void print(){
        int tiles = 0;
        for(auto i:flatPuzzle){
            if(tiles%3==0){
                cout << "\n";
            }
            cout << i << " ";
            tiles++;
        }
    }
    
    int findEmptySlot(){
        auto it = find(flatPuzzle.begin(),flatPuzzle.end(),0);
        auto index = distance(flatPuzzle.begin(),it);
        return (int)index;
    }
    
    void slideUp(){
       int pos =  findEmptySlot();
       vector<int> temp = flatPuzzle;
       if(pos!=0 && pos!=1 && pos!=2){
           swap(temp[pos],temp[pos-3]);
       }
       Node* child = new Node(temp,this);
       childNodes.push_back(child);
    }
    
    void slideDown(){
       int pos =  findEmptySlot();
       vector<int> temp = flatPuzzle;
       if(pos!=6 && pos!=7 && pos!=8){
           swap(temp[pos],temp[pos+3]);
       }
       Node* child = new Node(temp,this);
       childNodes.push_back(child);
    }
    
    void slideLeft(){
       int pos =  findEmptySlot();
       vector<int> temp = flatPuzzle;
       if(pos!=0 && pos!=3 && pos!=6){
           swap(temp[pos],temp[pos-1]);
       }
       Node* child = new Node(temp,this);
       childNodes.push_back(child);
    }
    
    void slideRight(){
       int pos =  findEmptySlot();
       vector<int> temp = flatPuzzle;
       if(pos!=2 && pos!=5 && pos!=8){
           swap(temp[pos],temp[pos+1]);
       }
       Node* child = new Node(temp,this);
       childNodes.push_back(child);
    }
};

bool visitedState(queue<Node*> open, Node* currChild){
	bool found = false;
	while(!open.empty()){
		if(open.front()->flatPuzzle == currChild->flatPuzzle){
			found = true;
		}
		open.pop();
	}
	return found;
}

int getPathStates(vector<Node*> finalState, Node* currChild){
    
    int height = 0;
    
	Node* curr = currChild;
	finalState.push_back(curr);
	while(curr->parent != NULL){
		curr = curr -> parent;
		finalState.push_back(curr);
	}

	reverse(finalState.begin(),finalState.end());
	
	cout << "Printing the solution...\n";
	for(auto it:finalState){
		it->print();
		cout<<"\n\n";
		height++;
	}
	
	return height;
}

void bfs(vector<int>startingState, vector<int> goalState){
    
    Node root = Node(startingState,NULL);
    
    queue<Node*> open;
    queue<Node*> close;
    
    open.push(&root);
    
    bool reachedGoal = false;
    int stepsRequired = 0;
    
    vector<Node*> finalState;
    
    while (!open.empty() && !reachedGoal){
        Node* currNode = open.front();
        close.push(currNode);
        open.pop();
        
        currNode->slideUp();
        currNode->slideDown();
        currNode->slideLeft();
        currNode->slideRight();
        
        for(auto it:currNode->childNodes){
            Node* currChild = it;
            if(currChild->flatPuzzle==goalState){
                cout << "Goal position is reached... \n";
                stepsRequired = getPathStates(finalState,currChild);
                reachedGoal = true;
            }
            if(!visitedState(open,currChild) && !visitedState(close,currChild)){
                open.push(currChild);
            }
        }
    }
    cout << "Number of steps required = " << stepsRequired - 1 << "\n";
}

bool bfsVisited(stack<Node*> open, Node* curr){
    
    bool found = false;
	while(!open.empty()){
		if(open.top()->flatPuzzle == curr->flatPuzzle){
			found = true;
		}
		open.pop();
	}
	return found;
}

void dfs(vector<int>startingState, vector<int> goalState){
    Node root = Node(startingState,NULL);
    
    stack<Node*> open;
    stack<Node*> close;
    
    open.push(&root);
 
    bool reachedGoal = false;
    int stepsRequired = 0;
    
    vector<Node*> finalState;
    
    while (!open.empty() && !reachedGoal){
        Node* currNode = open.top();
        close.push(currNode);
        vector<Node*> tmp;
        Node* currNodeNew;
        
        if(currNode->flatPuzzle==goalState){
            cout << "Goal position is reached... \n";
            stepsRequired = getPathStates(finalState,currNode);
            cout << "Number of steps required = " << stepsRequired - 1 << "\n";
            reachedGoal = true;
            break;
        }
        
        currNode->slideUp();
        tmp = currNode->childNodes;
        currNodeNew = tmp.back();
        
        if(!bfsVisited(open,currNodeNew) && !bfsVisited(close,currNodeNew) && currNode->flatPuzzle!=currNodeNew->flatPuzzle){
            open.push(currNodeNew);
            continue;
        }
        
        currNode->slideDown();
        tmp = currNode->childNodes;
        currNodeNew = tmp.back();
        
        if(!bfsVisited(open,currNodeNew) && !bfsVisited(close,currNodeNew) && currNode->flatPuzzle!=currNodeNew->flatPuzzle){
            open.push(currNodeNew);
            continue;
        }
        
        currNode->slideLeft();
        tmp = currNode->childNodes;
        currNodeNew = tmp.back();
        
        if(!bfsVisited(open,currNodeNew) && !bfsVisited(close,currNodeNew) && currNode->flatPuzzle!=currNodeNew->flatPuzzle){
            open.push(currNodeNew);
            continue;
        }
        
        currNode->slideRight();
        tmp = currNode->childNodes;
        currNodeNew = tmp.back();
        
        if(!bfsVisited(open,currNodeNew) && !bfsVisited(close,currNodeNew) && currNode->flatPuzzle!=currNodeNew->flatPuzzle){
            open.push(currNodeNew);
            continue;
        }
        
    }
    
}

int main() {

    vector<int> startingState;
    cout << "Please provide the initial state...\n";
    int tempTile;
    for(int i=0;i<9;i++){
        cin>>tempTile;
        startingState.push_back(tempTile);
    }
    
    // value=0 is the empty slot
    vector<int> goalState = {1,2,3,8,0,4,7,6,5};
    
    int choice = 0;
    cout << "Please select the search strategy...\n";
    cout << "1 -> Breadth First Search\n";
    cin >> choice;
    
    switch(choice){
        case 1:
            bfs(startingState,goalState);
            break;
        case 2:
            dfs(startingState,goalState);
            break;
        default:
            cout << "Select an appropriate option...\n";
            break;
    }
    
}