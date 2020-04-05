#include<bits/stdc++.h>
using namespace std;

vector<int>pattern;
// Function to print the contents of the given array
int select_patt(int out[], int n,int m)
{
	int i;
	if(n==m){
        for (i = 0; i < n; i++)
		    printf("%d ", out[i]);
		    
	    printf("\n");	    
	    
	    map<int,int> freq;
	    int flag=0;
	    
	    for(int i=0;i<n;i++){
	        freq[out[i]]++;
	        
	        if(freq[out[i]]>n-2){
	            cout<<"Nai chalega"<<endl;
	            flag=0;
	            break;
	        }
	        else{
	            flag=1;
	        }
	    }
	    cout<<"flag = "<<flag<<endl;
	    if(flag==1){
	        cout<<"here"<<endl;
        	for(int j=0;j<n;j++){
                pattern.push_back(out[j]);
            }
            
            return 1;
	    }
	    else{
	        
	        return 0;
	    }
	    
	}
	return 0;

}

// Recursive function to print all combination of numbers from i to n
// having sum n. index denotes the next free slot in output array out
void recur(int i, int k, int out[], int index,int n)
{
	// if sum becomes n, print the combination
	if (k == 0){
	    if(select_patt(out,index,n)==1){
	        return;
	    }
	    
	    
	}

	int j;

	// start from previous element in the combination till n
	for (j = i; j <= k; j++)
	{
		// place current element at current index
		out[index] = j;

		// recur with reduced sum
		recur(j, k - j, out, index + 1,n);
	}
	
	return;
}

// main function
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin>>n>>k;
        int out[k];
        pattern.clear();
        recur(1,k,out,0,n);
        
        for(int i=0;i<pattern.size();i++){
            cout<<pattern[i];
        }
        cout<<endl;
    }

	return 0;
}