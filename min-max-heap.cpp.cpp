#include <bits/stdc++.h>

using namespace std;

vector<int>heap;

inline int log2(int zvalue)
{
    if (zvalue == 0) throw std::domain_error("Log base 2 of 0 is not defined.");

    int result = 0;

    while (zvalue)
    {
        zvalue >>= 1;
        ++result;
    }

    return result - 1;
}

int parent(int ind) {
    return (ind - 1) / 2;
}

int leftChild(int ind) {
    return 2 * ind + 1;
}

int rightChild(int ind) {
    return 2 * ind + 2;
}

bool isOnMinLevel(int ind) {
    return log2(ind + 1) % 2 == 1;
}

bool isOnMaxLevel(int ind) {
    return !isOnMinLevel(ind);
}

int compare_(int a, int b){
    if(a <= b){
        return 0;
    }
    return 1;
}

void buildHeap_(int ind, int maxLevel) {
    if (ind == 0) return;

    int ind_grandparent = parent(ind);

    if (ind_grandparent == 0) return;

    ind_grandparent = parent(ind_grandparent);

    if (compare_(heap[ind], heap[ind_grandparent]) ^ maxLevel)
    {
        std::swap(heap[ind_grandparent], heap[ind]);
        buildHeap_(ind_grandparent,maxLevel);
    }
}

void buildHeap(int ind) {
    if (ind == 0) return;

    int ind_parent = parent(ind);

    if (isOnMinLevel(ind))
    {
        if (compare_(heap[ind_parent], heap[ind]))
        {
            std::swap(heap[ind_parent], heap[ind]);
            buildHeap_(ind_parent,true);
        }
        else
        {
            buildHeap_(ind,false);
        }
    }
    else
    {
        if (compare_(heap[ind], heap[ind_parent]))
        {
            std::swap(heap[ind_parent], heap[ind]);
            buildHeap_(ind_parent,false);
        }
        else
        {
            buildHeap_(ind,true);
        }
    }
}

void push_down(int ind, int maxLevel) {
   
    if (ind >= heap.size())
        throw std::invalid_argument("Element specified by index is not present");

    int smallestNode = ind;

    int left = leftChild(ind);

    if (left < heap.size() && (compare_(heap[left], heap[smallestNode]) ^ maxLevel))
        smallestNode = left;
    if (left + 1 < heap.size() && (compare_(heap[left + 1], heap[smallestNode]) ^ maxLevel))
        smallestNode = left + 1;

    int leftGrandchild = leftChild(left);
    for (int i = 0; i < 4 && leftGrandchild + i < heap.size(); ++i)
        if (compare_(heap[leftGrandchild + i], heap[smallestNode]) ^ maxLevel)
            smallestNode = leftGrandchild + i;
    if (ind == smallestNode) return;

    std::swap(heap[ind], heap[smallestNode]);        

    if (smallestNode - left > 1)
    {
        if (compare_(heap[parent(smallestNode)], heap[smallestNode]) ^ maxLevel)
            std::swap(heap[parent(smallestNode)], heap[smallestNode]);
           
        push_down(smallestNode,maxLevel);
    }
}


void down(int ind) {
    if (isOnMinLevel(ind))
        push_down(ind,false);
    else
        push_down(ind,true);
}

int findMaxIndex(){
    switch (heap.size())
    {
        case 0:
            throw std::underflow_error("No elements in the heap.");
        case 1:
            return 0;
        case 2:
            return 1;
        default:
            return compare_(heap[1], heap[2]) ? 1 : 2;
    }
}


void del(int ind) {
   
    if (ind >= (int)heap.size())
        throw std::underflow_error("No elements in the heap.");

    if (ind == heap.size() - 1)
    {
        heap.pop_back();
        return;
    }

    std::swap(heap[ind], heap[heap.size() - 1]);

    heap.pop_back();


    down(ind);
}

bool empty(){
    return heap.size() == 0;
}


int size(){
    return (int)heap.size();
}


void insertHeap(int value) {
    heap.push_back(value);

    buildHeap(heap.size() - 1);
}

int findMin(){
    if (empty())
        throw std::underflow_error("No elements in the heap.");

    return heap[0];
}


int findMax(){
    return heap[findMaxIndex()];
}


int deleteMin() {
    if (heap.size() == 0)
        throw std::underflow_error("No elements in the heap.");

    int  temp = heap[0];

    del(0);

    return temp;
}

int pop() {
    return deleteMin();
}


int deleteMax() {
    if (heap.size() == 0)
        throw std::underflow_error("No elements in the heap.");

    int smallest = findMaxIndex();

    int temp = heap[smallest];

    del(smallest);

    return temp;
}


void printHeap(){
   
    if (empty())
        cout << "Heap is Empty";
    else
        for (int i = 0; i < heap.size(); ++i)
            cout << heap[i] << " ";

    cout << "\n";
}
   
int main() {
        
    int select;
    
    while(select!=9){
        
        cout << "Please choose one of the following options:\n";
        cout << "1-> Insert heap elements\n";
        cout << "2-> Build heap\n";
        cout << "3-> Insert\n";
        cout << "4-> Print min element\n";
        cout << "5-> Print max element\n";
        cout << "6-> Remove min element\n";
        cout << "7-> Remove max element\n";
        cout << "8-> Exit\n";
        
        cin>>select;
        
        if(select==1){
            cout << "Enter the number of elements to be inserted\n";
            int n;
            cin>>n;
            cout << "Enter the elements seperated by space\n";
            for(int i=0;i<n;i++){
                int x;
                cin>>x;
                insertHeap(x);
            }
        }
        else if(select==2){
            buildHeap(heap.size() - 1);
            printHeap();
        }
        else if(select==3){
            cout << "Enter the element to be inserted\n";
            int m;
            cin>>m;
            insertHeap(m);
        }
        else if(select==4){
            cout << "The min element is...";
            cout << findMin() << "\n";
        }
        else if(select==5){
            cout << "The max element is...";
            cout << findMax() << "\n";   
        }
        else if(select==6){
            deleteMin();
            cout << "The min element is removed \n";
            cout << "current heap is \n";
            printHeap();
        }
        else if(select==7){
            deleteMax();
            cout << "The max element is removed \n";
            cout << "current heap is \n";
            printHeap();
        }
        else if(select==8){
            cout << "Exit" <<"\n";
            return 0;
        }
        else{
            cout << "Invalid option select, please select option from the menu\n";
        }
    }
}
