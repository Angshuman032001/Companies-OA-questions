// https://leetcode.com/problems/get-the-maximum-score/
const int mod = 1e9 + 7;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        
        long long aSum = 0, bSum = 0, ans = 0;
        
        while(i < n && j < m){
            
            if(nums1[i] < nums2[j]){
                aSum += nums1[i++];
            }
            else if(nums2[j] < nums1[i]){
                bSum += nums2[j++];
            }
            else{
                ans += max(aSum, bSum) + nums1[i];
                i++, j++;
                aSum = 0, bSum = 0;
            }
        }
        
        while(i < n) aSum += nums1[i++];
        while(j < m) bSum += nums2[j++];
        
        ans += max(aSum, bSum);
        
        ans %= mod;
        
        return ans;
    }
};
