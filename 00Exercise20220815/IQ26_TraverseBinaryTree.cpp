struct TreeNode{
      int m_nvalue;
      TreeNode* m_pleft;
      TreeNode* m_pright;
      TreeNode():m_nvalue(0), m_pleft(nullptr), m_pright(nullptr){}
      TreeNode(int x):m_nvalue(x), m_pleft(nullptr), m_pright(nullptr){}
      TreeNode(int x, TreeNode* left, TreeNode* right):m_nvalue(x), m_pleft(left), m_pright(right){}
}

#include <algorithm>    // std::reverse
#include <vector>       // std::vector

// 前序遍历
class solution{
public:
      vector<int> PreOrderTraversal(TreeNode* root){
            stack<TreeNode*> st;
            vector<int> result;
            if(root == nullptr)
            {
                  return result;
            }

            // TreeNode* 
            st.push(root);
            while(!st.empty()){
                  TreeNode* node = st.top();
                  st.pop();
                  result.push_back(node->m_nvalue);
                  if(node->m_pright != nullptr)
                        st.push(node->m_pright);
                  if(node->m_pleft != nullptr)
                        st.push(node->m_pleft);
                  
            }

            return result;
      }
}

// 后序遍历
class solution{
public:
      vector<int> LastOrderTraversal(TreeNode* root){
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
                  result.push_back(node->m_nvalue);
                  if(node->m_pleft != nullptr)
                        st.push(node->m_pleft);
                  if(node->m_pright != nullptr)
                        st.push(node->m_pright);                 
                  
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
            if(root == nullptr)
            {
                  return result;
            }

            TreeNode* cur = root;
            
            while(cur != nullptr || !st.empty()){
                  if(cur != nullptr)
                  {
                        // st.push(cur->m_nvalue); 修改如下
                        st.push(cur);
                        cur = cur->m_pleft;

                  }else{
                        cur = st.top();
                        st.pop();
                        result.push_back(cur->m_nvalue);
                        cur = cur->m_pright;                      
                  }                                
                  
            }

            return result;
      }
}

// 层序遍历
//--------------标准答案---------------
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int> > result;

        if(root == nullptr)
        {
            return result;
        }               
        
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};