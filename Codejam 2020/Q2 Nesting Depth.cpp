#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
        
    for(int k=1;k<=t;k++){
        
        string s;
        cin>>s;
        int arr[s.size()];
        string res;
        
        for(int i=0;i<s.size();i++){
            arr[i] = (int)s[i] - 48;
        }
        
        for(int i=0;i<s.size();i++){
            
            if(i==0){
                    
                for(int j=0;j<arr[i];j++){
                    res+="(";
                }
            }
            else{
                
                if(arr[i]<arr[i-1]){
                    for(int j=0;j<arr[i-1]-arr[i];j++){
                        res+=")";    
                    }
                }
                else if(arr[i]>arr[i-1]){
                    for(int j=0;j<arr[i]-arr[i-1];j++){
                        res+="(";
                    }
                }
                
            }
            
            res+=to_string(arr[i]);
        
        }
        
        for(int i=0;i<arr[s.size()-1];i++){
            res+=")";
        }
        cout<<"Case #"<<k<<": ";
        for(int i=0;i<res.size();i++){
            cout<<res[i];
        }
        cout<<endl;
    }
    
}