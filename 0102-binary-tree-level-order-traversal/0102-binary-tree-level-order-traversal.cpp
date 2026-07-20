class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int q_size = q.size();
            vector<int> level;

            while (q_size--) {
                TreeNode* front = q.front();
                level.push_back(front->val);
                q.pop();

                if (front->left)
                    q.push(front->left);

                if (front->right)
                    q.push(front->right);
            }

            result.push_back(level);
        }

        return result;
    }
};