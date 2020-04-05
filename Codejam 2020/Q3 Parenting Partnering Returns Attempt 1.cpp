#include<bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        
        int n;
        cin>>n;
        int flag=0;
        map<int,int> jamie,cameron;
        
        vector<char>res;
        for(int i=0;i<n;i++){
            int j,c;
            cin>>j>>c;
            
            if(i==0){
                jamie.insert({j,c});
                res.push_back('J');
                continue;
            }
            
            int jcnt=0,ccnt=0;
            
            for(auto p=jamie.begin();p!=jamie.end();p++){
                if((j<p->first && c<=p->first) || (j>=p->second && c>p->second)){
                    jcnt++;
                }
                else{
                    break;
                }
            }
            
            if(jcnt==jamie.size()){
                jamie.insert({j,c});
                res.push_back('J');
                continue;
            }
            
            for(auto q=cameron.begin();q!=cameron.end();q++){
                if((j<q->first && c<=q->first) || (j>=q->second && c>q->second)){
                    ccnt++;
                }
                else{
                    break;
                }
            }
            
            if(ccnt==cameron.size()){
                cameron.insert({j,c});
                res.push_back('C');
                continue;
            }
            
            if(jcnt!=jamie.size() && ccnt!=cameron.size()){
                flag=1;
                break;
            }
        }

        
        if(flag){
            cout<<"Case #"<<k<<": IMPOSSIBLE"<<endl;
        }
        else{
            cout<<"Case #"<<k<<": ";
            for(auto i=res.begin();i!=res.end();i++){
                cout<<*i;
            }
            cout<<endl;
        }
        
    }

}