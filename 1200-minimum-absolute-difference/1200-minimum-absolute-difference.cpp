class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
};