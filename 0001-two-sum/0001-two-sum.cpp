class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        int n =nums.size();
        for (int i=0;i<n;i++){
            int num=nums[i];
            int required= target-num;
            if(mpp.find(required)!=mpp.end()){
                return {mpp[required],i};
            }
            mpp[num]=i;
        }
        return{-1,-1};

        

    } 
};
    