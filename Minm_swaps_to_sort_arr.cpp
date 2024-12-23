

class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<pair<int,int>> num;
        for(int i=0;i<n;i++) {
            num.push_back({arr[i],i});
        }
        sort(num.begin(),num.end());
        int swaps = 0;
        for(int i=0;i<n;i++) {
            if(num[i].second==i) continue;
            else {
                swap(num[i],num[num[i].second]);
                swaps++;
                i--;
            }
        }
        return swaps;
    }
};