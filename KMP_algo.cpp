class Solution {
public:
    // KMP algo
    vector<int> LPS(string &s) {
        int n = s.length();
        vector<int> pi(n,0);
        for(int i=1;i<n;i++) {
            int j = pi[i-1];
            while(j>0 && s[i]!=s[j]) {
                j = pi[j-1];
            }
            if(s[i]==s[j]) {
                j++;
            }   
            pi[i] = j;
        }
        return pi;
    }
    int strStr(string haystack, string needle) {
        int ans = -1;
        vector<int> lps = LPS(needle);
        int i = 0, j = 0;
        while(i<haystack.length()) {
            if(haystack[i]==needle[j]) {
                i++;
                j++;
            }else {
                if(j==0) {
                    i++;
                }else {
                    j = lps[j-1];
                }
            }
            if(j==needle.length()) {
                return i-needle.length();
            }
        }
        return ans;
    }
};