#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        
        int n;
        cin>>n;
        map<int,set<int>> cols;
        int mat[n][n];
        int rake=0;
        int r=0,c=0;
        
        for(int i=0;i<n;i++){
            set<int>temp;
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
                temp.insert(mat[i][j]);
                if(i==j){
                    rake+=mat[i][j];
                }
                cols[j].insert(mat[i][j]);
            }
            if(temp.size()!=n){
                r+=1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(cols[i].size()!=n){
                c+=1;
            }
        }
        cout<<"Case #"<<k<<": "<<rake<<" "<<r<<" "<<c<<endl;
    }

}