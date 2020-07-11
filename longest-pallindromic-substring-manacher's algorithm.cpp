//************************  longest-palindromic-substring (manacher's algo)  ****************************

//https://leetcode.com/problems/longest-palindromic-substring/solution/

//https://www.youtube.com/watch?v=nbTSfrEfo6M

//https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/


class Solution {
public:
    
    string new_str(string old){
        
        string new_st = "@";
        for(int i=0;i<old.size();i++){
            new_st+="#"+old.substr(i,1);
        }
        
        new_st+="#$";
        
        return new_st;
        
    }
    
    string longestPalindrome(string s) {
     
        string pal;
        string backup = s;
        
        if(s.size()>0){

            string s = new_str(s);
        
            int n = s.size();
            int res[n];
            int c=0;
            int r=0;

            for(int i=0;i<n-1;i++){
                int mirror = 2*c - i;

                if(i<r){
                    res[i] = min(r-i,res[mirror]);
                }

                while(s[i+res[i]+1]==s[i-res[i]-1]){
                    res[i]++;
                }

                if(i+res[i]>r){
                    c = i;
                    r = i+res[i];
                }

            }
            
            int index;
            int max_size = 0;
            for(int i=0;i<n;i++){
                if(res[i]>max_size){
                    max_size = res[i];
                    index = i;
                }
            }
            
            pal = backup.substr((index-max_size)/2,max_size);

        }
        
        return pal;
              
    }
};
