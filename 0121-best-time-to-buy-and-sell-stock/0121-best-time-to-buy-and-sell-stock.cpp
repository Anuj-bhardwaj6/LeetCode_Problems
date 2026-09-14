class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int minp = prices[0];
        int profit =0;
        for (int i=0;i<n;i++){
            minp=min(minp,prices[i]);
            profit=max(profit,prices[i]-minp);
        }
        return profit;
    }
    
};