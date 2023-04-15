#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pair<long long int,long long int>, null_type,less< pair<long long int,long long int> >, rb_tree_tag,tree_order_statistics_node_update>
#define IOFAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define mod                     10e9 + 7
#define pb                      push_back  
#define mp                      make_pair
#define F                       first
#define S                       second
#define lb                      lower_bound
#define ub                      upper_bound
#define fill0(a)                memset(a,0,sizeof(a))
#define fillneg1(a)             memset(a,-1,sizeof(a))
#define fillbig(a)              memset(a,63,sizeof(a))
#define getSetbits(x)              __builtin_popcount(x)
#define fo(i,n)                 for(int i=0;i<n;i++)
#define print(x)                for(auto it=x.begin();it!=x.end();it++)\
								cout<<*it<<' '; cout<<endl
#define printKeyValue(x)        for(auto it=x.begin();it!=x.end();it++)\
                                cout<<it->first<<' '<<it->second<<endl

typedef unsigned int            uint;
typedef long long               ll;
typedef unsigned long long      ull;
typedef long double             lld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef vector<long long>       vll;
typedef pair<int,int>           pii;
typedef pair<ll,ll>             pll;
typedef vector<pii>             vpii;
typedef vector<pll>             vpll;
typedef vector<bool>            vb;
typedef vector<vb>              vvb;
typedef vector<string>          vs;

void printMatrix(vvi mat){
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void printMap(unordered_map<int,int>&m){
	for(auto it=m.begin();it!=m.end();it++){
		cout << it->first << "\t" << it->second <<"\n";
	}
}

void printMap(map<int,int>&m){
	for(auto it=m.begin();it!=m.end();it++){
		cout << it->first << "\t" << it->second <<"\n";
	}
}

int main(){
    cout<<"Hello\n";
    return 0;

}
