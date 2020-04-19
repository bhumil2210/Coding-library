#include<bits/stdc++.h>
#define IOFAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)

#define pb push_back  

unsigned int nextPowerOf2(unsigned int n)   
{ 
    n--; 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
    n++; 
    return n; 
}

int main(){
    int t;
    cin>>t;
    fo(i,t){
        vector<char> res;
        int x,y;
        cin>>x>>y;
        if(abs(x)==abs(y)){
            cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
        }
        else if(x%2==0 && y%2==0){
            cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
        }
        else if(x%2!=0 && y%2!=0){
            cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
        }
        else{
            int flag1 = 0, flag2 = 0, flag3 = 0;
            if(x>=0 && y<0){
                flag1 = 1;
                y = -y;
            }
            else if(x<0 && y>=0){
                flag2 = 1;
                x = -x;
            }
            else if(x<0 && y<0){
                flag3 = 1;
                x = -x;
                y = -y;
            }
            
            //vector<vector<int>> mat(x+1,vector<int>(y+1,0));
        
            // for(int i=0;i<x;i++){
            //     for(int j=0;j<y;j++){
            //         cout<<mat[i][j]<<endl;
            //     }
            // }
        
            // for(int i=0;i<=x;i++){
            //     if(i%2!=0){
            //         mat[i][0] = (i/2)+1;
            //     }
            //     else{
            //         mat[i][0] = 0;
            //     }
            // }
            
            // for(int i=0;i<=y;i++){
            //     if(i%2!=0){
            //         mat[0][i] = (i/2)+1;
            //     }
            //     else{
            //         mat[0][i] = 0;
            //     }
            // }

            // for(int i=1;i<=x;i++){
            //     for(int j=1;j<=y;j++){
                    
            //         if(mat[i-1][j-1]!=0)
            //             mat[i][j] = mat[i-1][j-1]+1;
                
            //     }
            // }
            // int moves = mat[x][y];
            // cout<<"moves = "<<moves<<endl;
        
            int change = 0;
        
            if(x==0)
                change = y-1;
            else if(y==0)
                change = x-1;
            else if(x>y)
                change = nextPowerOf2(x);
            else
                change = nextPowerOf2(y);
                
            if(change==0){
                change = 1;
            }
        
            while(x!=0 || y!=0){
                // cout<<"x = "<<x<<endl;
                // cout<<"y = "<<y<<endl;
                // cout<<"change = "<<change<<endl;
                if(x==0){
                    if(y>0){
                      y-=change;
                      change = change/2;
                      res.push_back('N');
                    }     
                    else{
                      y+=change;
                      change = change/2;
                      res.push_back('S');
                    }
                    continue;
                }
                else if(y==0){
                    if(x>0){
                      x-=change;
                      change = change/2;
                      res.push_back('E');
                    }     
                  else{
                      x+=change;
                      change = change/2;
                      res.push_back('W');
                    }
                    continue;
                }
                
                if(x>y){
                  if(x>0){
                      x-=change;
                      change = change/2;
                      res.push_back('E');
                  }     
                  else{
                      x+=change;
                      change = change/2;
                      res.push_back('W');
                  }
                }
                else{
                    if(y>0){
                      y-=change;
                      change = change/2;
                      res.push_back('N');
                    }     
                    else{
                      y+=change;
                      change = change/2;
                      res.push_back('S');
                    }
                }
                // cout<<"ending-----"<<endl;
                // cout<<x<<"\t"<<y<<endl;
            }
            
            if(flag1){
                //cout<<"flag1"<<endl;
                for(int i=0;i<res.size();i++){
                    if(res[i]=='N'){
                        res[i]='S';
                    }
                    else{
                        res[i]='N';
                    }
                }
            }
            else if(flag2){
                //cout<<"flag2"<<endl;
                for(int i=0;i<res.size();i++){
                    if(res[i]=='W'){
                        res[i]='E';
                    }
                    else{
                        res[i]='W';
                    }
                }
            }
            else if(flag3){
                //cout<<"flag3"<<endl;
                for(int i=0;i<res.size();i++){
                    if(res[i]=='N'){
                        res[i]='S';
                    }
                    else if(res[i]=='W'){
                        res[i]='E';
                    }
                    else if(res[i]=='E'){
                        res[i]='W';
                    }
                    else{
                        res[i]='N';
                    }
                }
            }
            cout<<"Case #"<<(i+1)<<": ";
            for(int i=res.size()-1;i>=0;i--){
                cout<<res[i];
            }
            cout<<endl;
        }
    }
    return 1;

}
