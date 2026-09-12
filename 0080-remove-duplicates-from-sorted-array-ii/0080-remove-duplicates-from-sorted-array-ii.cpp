class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        for (int i=0;i<n-2;i++){
            if(nums[i]==nums[i+2]){
                for(int j=i+2;j<n-1;j++){
                    nums[j]=nums[j+1];
                }
                n--;
                i--;
            }
        }
        return n;
        
    }
};