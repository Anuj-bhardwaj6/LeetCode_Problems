class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=*min_element(nums.begin(), nums.end());
         return min;
    }
   
};