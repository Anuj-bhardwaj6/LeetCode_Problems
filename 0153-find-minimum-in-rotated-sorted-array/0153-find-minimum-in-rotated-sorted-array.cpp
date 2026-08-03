class Solution {
public:
    int findMin(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
        return nums[i];
        }
        
        return 0;
    }
};