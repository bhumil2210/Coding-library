class KMP{

    void computeLPS(vector<int>&lps, string pat){
        int len = 0;
        int i = 1;
        int m = pat.size();
        lps[0]=0;
        while(i<m){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            } else {
                if(len!=0){
                    len = lps[len-1];
                } else {
                    lps[i]=0;
                    i++;
                }
            }
        }

    }

    void KMP(string text, string pat){
        int n = text.size();
        int m = pat.size();
        vector<int>lps(m,-1);
        computeLPS(lps,pat);

        int i=0,j=0;
        while(i<n){
            if(text[i]==pat[j]){
                i++;
                j++;
            }

            if(j==m){
                cout << "pattern found at" << i-j << "\n";
                j = lps[j-1];
            } else if(i<n && text[i]!=pat[j]){
                if(j!=0){
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }
    }

};