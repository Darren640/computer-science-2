class TreeNode {
    private:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class solution {
    public:
        int countLeaves(TreeNode* root)
        {
            if(root == nullptr)
            {
                return 0;
            }
         if(root->left == nullptr && root->right == nullptr)
            {
                return 1;
            }
            else
            {
                return countLeaves(root->left) + countLeaves(root->right);
            }
        }
        int height(TreeNode* root)
        {
            if(root == nullptr)
            {
                return 0;
            }
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        }
};