class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int count=1;
        int currmax=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=currmax){
                count++;
                currmax=nums[i];
            }
            if(count==3){
                return currmax;
            }
        }
     return nums[0];

    }
    
};