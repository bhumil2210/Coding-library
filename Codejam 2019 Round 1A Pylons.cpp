#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    srand (time(NULL));
    cin >> t;
    for(int i=1;i<=t;i++){
        int r,c;
        cin >> r >> c;
        int visited[r][c];
    
        if(r+c < 7){
            cout << "Case #" << i << ": IMPOSSIBLE" << endl;
        }
        else{
            cout << "Case #" << i << ": POSSIBLE" << endl;
            vector<pair<int,int>>moves;
            map<pair<int,int>,int>start_point;
            while(moves.size()!=r*c){
                memset(visited,0,sizeof(visited));
                moves.clear();
                int lastf = -1, lasts = -1;
                int count = 0;
                int first = -1;
                while(count!=r*c){
                    //cout<<"count = "<<count<<endl;
                    vector<pair<int,int>> vals;
                    
                    if(lastf==-1 && lasts==-1){
                        for(int j=0;j<r;j++){
                            for(int k=0;k<c;k++){
                                vals.push_back(make_pair(j,k));
                            }
                        }
                    }
                    else{
                        for(int j=0;j<r;j++){
                            for(int k=0;k<c;k++){
                                //cout<<visited[j][k]<<"\t"<<j<<"\t"<<k<<"\t"<<lastf<<"\t"<<lasts<<endl;
                                if(!visited[j][k] && j!=lastf && k!=lasts && j-k!=lastf-lasts && j+k!=lastf+lasts)
                                    vals.push_back(make_pair(j,k));
                                    
                                //cout<<"size of visited = "<<vals.size()<<endl;
                            }
                        }
                    }
                    
                    if(vals.size()==0){
                        //cout<<"Breaked"<<endl;
                        break;
                    }
                    
                    int x = rand()%vals.size();
                    
                    if(first==-1){
                        
                        while(start_point[make_pair(vals[x].first,vals[x].second)]){
                            x = rand()%vals.size();    
                        }
                        
                        first = x;
                        start_point[make_pair(vals[x].first,vals[x].second)] = 1;
                    }
                    moves.push_back(make_pair(vals[x].first,vals[x].second));
                    lastf = vals[x].first;
                    lasts = vals[x].second;
                    visited[lastf][lasts] = 1;
                    count++;
                }
            }
            //cout<<"---------------------------"<<endl;
            //cout<<"size = "<<moves.size()<<endl;
            for(int j=0;j<moves.size();j++){
                cout<<moves[j].first+1<<"\t"<<moves[j].second+1<<endl;
            }
            
        }
    }
}
