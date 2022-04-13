//https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>rightMin(n);
        for(int i = n - 1;i>=0;i--){
            rightMin[i] = min(arr[i], (i + 1 < n ? rightMin[i + 1] : INT_MAX));
        }
        int leftMax = 0, ans = 0;
        for(int i = 0;i<n - 1;i++){
            leftMax = max(leftMax, arr[i]);
            if(leftMax <= rightMin[i + 1]) ans++;
        }
        return ans + 1;
    }
};
