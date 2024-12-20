class Solution {
public:
    // Z - function
    vector<int> calculateZ(const string &input) {
        int n = input.length();
        vector<int> Z(n);
        int left = 0, right = 0;
        for (int k = 1; k < n; k++) {
            if (k > right) {
                left = right = k;
                while (right < n && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                int k1 = k - left;
                if (Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else {
                    left = k;
                    while (right < n && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }
    int strStr(string haystack, string needle) {
        int m = needle.length();
        needle += '$';
        needle += haystack;
        vector<int> zTable = calculateZ(needle);
        for(int i=0;i<needle.length();i++) {
            if(zTable[i]==m) {
                return i-m-1;
            }
        }
        return -1;
    }
};