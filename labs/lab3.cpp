class TreeNode {
    public:
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
};