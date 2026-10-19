class Solution {
public:
    void nextPermutation(vector<int>& n) {
        // next_permutation(n.begin(), n.end());
        int v = INT_MIN, idx = -1;
        for (int i = n.size() - 1; i >= 0; i--) {
            if (n[i] < v) {
                idx = i;
                v = n[i];
                break;
            }
            v = max(v, n[i]);
        }
        if (idx == -1) {
            sort(n.begin(), n.end());
            return;
        }
        int v1 = INT_MAX, idx1 = 0;
        for (int i = idx; i < n.size(); i++) {
            if (n[i] > v) {
                v1 = min(v1, n[i]);
                idx1 = i;
            }
        }
        swap(n[idx], n[idx1]);
        sort(n.begin() + idx + 1, n.end());
    }
};