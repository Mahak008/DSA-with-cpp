// Leetcode -94

// Iterative Approach

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    stack<TreeNode*> st;
    TreeNode* node = root;

    while (true) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}

// Recursive Approach

void inOrder(TreeNode *root, vector<int> &ans) {
  if (root == NULL) {
    return;
  }

  inOrder(root->left, ans);
  ans.push_back(root->data);
  inOrder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> ans;
  inOrder(root, ans);
  return ans;
}

// Input
//          1
//        /   \
//      3       4
//    /  \     /  \
//   5    2   7    6

// Output: 5, 3, 2, 1, 7, 4, 6