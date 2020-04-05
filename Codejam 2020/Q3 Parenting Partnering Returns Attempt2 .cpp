#include<bits/stdc++.h>
using namespace std;
bool change_order(const pair<int,int> &a, const pair<int,int> &b){ 
    
    return a.first<b.first;
} 

int main(){
    int t;
    cin>>t;

    for(int k=1;k<=t;k++){
        
        map<int,int> jamie,cameron;
        vector< pair <int, int> > new_val;
        vector< pair <int, int> > old_val; 
        vector<char>result;
        
        int n;
        int s,e;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>s>>e;
            new_val.push_back(make_pair(s,e));
            old_val.push_back(make_pair(s,e));
        }
        sort(new_val.begin(), new_val.end(), change_order); 
        
        int j_s = new_val[0].first;
        int j_e = new_val[0].second;
        jamie.insert({new_val[0].first,new_val[0].second});
        result.push_back('J');
        
        int c_s = new_val[1].first;
        int c_e = new_val[1].second;
        cameron.insert({c_s,c_e});
        result.push_back('C');
        
        int flag = true;
        for(int j=2;j<new_val.size();j++){
            
            if(j_e<=new_val[j].first){
                jamie.insert({new_val[j].first,new_val[j].second});
                j_e = new_val[j].second;
                result.push_back('J');
                continue;
            }
            if(c_e<=new_val[j].first){
                cameron.insert({new_val[j].first,new_val[j].second});
                c_e = new_val[j].second;
                result.push_back('C');
                continue;
            }
            flag = false;
            break;
            
        }
        if(flag){
            
            cout<<"Case #"<<k<<": ";
            
            for(int i=0;i<old_val.size();i++){
                int q=0;
                for(q=0;q<new_val.size();q++){
                    if(new_val[q].first==old_val[i].first && new_val[q].second==old_val[i].second){
                        new_val[q] = make_pair(-1,-1);
                        break;
                    }
                }
                cout<<result[q];
            }
            
        }
        else{
            cout<<"Case #"<<k<<": IMPOSSIBLE";
        }
        cout<<endl;
    }

}