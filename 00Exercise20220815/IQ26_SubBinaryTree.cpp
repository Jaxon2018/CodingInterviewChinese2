struct BinaryTreeNode{
      double m_dValue;
      BinaryTreeNode* m_pLeft;
      BinaryTreeNode* m_pRight;

      BinaryTreeNode():m_dValue(0.0), m_pLeft(nullptr), m_pRight(nullptr){}
      BinaryTreeNode(double x):m_dValue(x), m_pLeft(nullptr), m_pRight(nullptr){}
      BinaryTreeNode(double x, BinaryTreeNode* left, BinaryTreeNode* right):m_dValue(x), m_pLeft(left), m_pRight(right){}
}

// 前序遍历-栈循环
class solution{
public:
      vector<int> PreOrderTraversal(TreeNode* root){
            stack<TreeNode*> st;
            vector<int> result;
            if(root == nullptr)
            {
                  return result;
            }
            st.push(root);
            while(!st.empty()){
                  TreeNode* node = st.top();
                  st.pop();
                  result.push_back(node->val);
                  if(node->right) st.push(node->right);
                  if(node->left) st.push(node->left);
            }
            return result;
      }
}

// 后序遍历
class solution{
public:
      vector<int> PostOrderTraversal(TreeNode* root){
            stack<TreeNode*> st;
            vector<int> result;
            if(root == nullptr)
            {
                  return result;
            }
            
            st.push(root);
            while(!st.empty())
            {
                  TreeNode* node = st.top();
                  st.pop();
                  result.push_back(node->val);
                  if(node->left) 
                        st.push(node->left);
                  if(node->right)
                        st.push(node->right);

            }
            reverse(result.begin(), result.end());
            return result;
      }
}

// 中序遍历
class solution{
public:
      vector<int> InOrderTraversal(TreeNode* root){
            stack<TreeNode*> st;
            vector<int> result;
            TreeNode* cur = root;
            while(cur != nullptr || !st.empty()){
                  if(cur != nullptr){
                        st.push(cur);
                        cur = cur->left;
                  }else{
                        cur = st.top();
                        st.pop();
                        result.push_back(cur->val);
                        cur = cur->right;
                  }
            }
            return result;
            
      }
}







