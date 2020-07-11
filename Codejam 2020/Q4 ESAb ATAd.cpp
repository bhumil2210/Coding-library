#include<bits/stdc++.h>

using namespace std;

int query(int x){
    cout << x <<endl;
    int res;
    cin>>res;
    return res;
}

vector<int>res(100);
int same = -1;
int diff = -1;

void ask(int s,int b){
    
    res[s]=query(s);
    res[b-s-1] = query(b-s-1);
    if(same!=-1 && res[s]==res[b-s-1]){
        same = s;
    }
    else if(diff!=-1 && res[s]!=res[b-s-1]){
        diff = s;
    }
}

void change(int b){
    
    int x = query(same);
    int y = query(diff);
    int comp = 0,rev = 0;
    
    if(same!=-1 && diff!=-1 && (x!=res[same] && y!=res[diff])){
        comp = 1;
    }
    else if(same!=-1 && diff!=-1 && (x!=res[same] && y==res[diff])){
        comp = 1;
        rev = 1;
    }
    else if(same!=-1 && diff!=-1 && (x==res[same] && y!=res[diff])){
        rev = 1;
    }
    
    if(comp){
        for(int i=0;i<b;i++){
            res[i] = !res[i];
        }
    }    
    
    if(rev){
        for(int i=0;i<b/2;i++){
            swap(res[i],res[b-i-1]);
        }
    }
}


int main() {

    int t,b;
    cin>>t>>b;
    for(int i=0;i<t;i++){
        
        int j=0; 
        for(j=0;j<5;j++){
            ask(j,b);
        }
        
        change(b);
        
        while(j<b/2){
            int k;
            for(k=0;k<4 && j<b/2;k++){
                ask(j,b);
                j++;
            }
            if(k==4)
                change(b);
        }
        
        for(int m=0;m<b;m++){
            cout<<res[m];
        }
        cout<<endl;
        char resp;
        cin>>resp;
        if(resp=='N'){
            exit(0);
        }
            
    }
    
    return 1;
}
