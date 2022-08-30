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
#include <stack>        // std::stack
#include <queue>        // std::queue

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

//====================翻转二叉树========================

// 前序遍历翻转二叉树
//----------------------LeetCode Submit--------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
      TreeNode* mirrorTree(TreeNode* root) {            

            if(root == nullptr)
            {
                  return nullptr;
            }

            stack<TreeNode*> st;
            st.push(root);
                  
            TreeNode* node = root;

            while((node->right || node->left) && !st.empty()){
                  // 调换该节点的两个子节点
                  TreeNode* node = st.top();
                  st.pop();
                  TreeNode* tmpnode = nullptr;
                  tmpnode = node->left;
                  node->left = node->right;
                  node->right = tmpnode;

                  if(node->right != nullptr)
                        st.push(node->right);
                  if(node->left != nullptr)
                        st.push(node->left);
                  
            }

            return root;
      }
};

// 中序遍历翻转二叉树
//------------------V0-----------------------
class solution{
public:
      TreeNode* InOrderTraversal(TreeNode* root){

            if(root == nullptr)
            {
                  return nullptr;
            }

            stack<TreeNode*> st;

            TreeNode* cur = root;
            
            while(cur != nullptr || !st.empty()){
                  if(cur != nullptr)
                  {
                        st.push(cur);
                        cur = cur->left;

                  }else{
                        cur = st.top();
                        st.pop();
                        TreeNode* tmpnode = nullptr;
                        tmpnode = cur->left;
                        cur->left = cur->right;
                        cur->right = tmpnode;

                        cur = cur->right;                      
                  }                                
                  
            }

            return root;
      }
}

//---------------------V1 not finished-------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr)
        {
            return nullptr;
        }

        stack<TreeNode*> st;

        TreeNode* cur = root;
        
        while(cur != nullptr || !st.empty()){
            if(!(cur->left == nullptr && cur->right == nullptr))
            // if(cur->left != nullptr)
            {
                st.push(cur);
                if((cur->left != nullptr) && (!(cur->left->left == nullptr && cur->left->right == nullptr)))
                    cur = cur->left;
                else{
                    cur->left = nullptr;
                }

            }else if(cur->right != nullptr){
                cur = st.top();
                st.pop();
                TreeNode* tmpnode = nullptr;
                tmpnode = cur->left;
                cur->left = cur->right;
                cur->right = tmpnode;

                if(cur->left)
                    cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                TreeNode* tmpnode = nullptr;
                tmpnode = cur->left;
                cur->left = cur->right;
                cur->right = tmpnode;

                if(cur->left)
                    cur = cur->left;
            }
        }
        return root;
    }
};

//---------------------V2 not finished-------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr)
        {
            return nullptr;
        }

        stack<TreeNode*> st;

        TreeNode* cur = root;
        bool isstop = false;
        
        while(cur != nullptr || !st.empty()){
            if(!(cur->left == nullptr && cur->right == nullptr) && isstop == false)
            // if(cur->left != nullptr)
            {
                st.push(cur);
                if((cur->left != nullptr) && (!(cur->left->left == nullptr && cur->left->right == nullptr)))
                {
                    cur = cur->left;
                    isstop = false;
                }
                else{
                    // cur->left = nullptr;
                    isstop = true;
                }

            }else if(cur->right != nullptr){
                cur = st.top();
                st.pop();
                TreeNode* tmpnode = nullptr;
                tmpnode = cur->left;
                cur->left = cur->right;
                cur->right = tmpnode;

                // if(cur->left)
                //     cur = cur->left;
                if((cur->left != nullptr) && (!(cur->left->left == nullptr && cur->left->right == nullptr)))
                {
                    cur = cur->left;
                    isstop = false;
                }
                else{
                    // cur->left = nullptr;
                    isstop = true;
                }
            // }else{
            //     cur = st.top();
            //     st.pop();
            //     TreeNode* tmpnode = nullptr;
            //     tmpnode = cur->left;
            //     cur->left = cur->right;
            //     cur->right = tmpnode;

            //     if(cur->left)
            //         cur = cur->left;
            }
        }
        return root;
    }
};

// 层序遍历
//---------------submit-------
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
                        TreeNode* tmpnode = nullptr;
                        tmpnode = node->left;
                        node->left = node->right;
                        node->right = tmpnode;

                        if(node->left) que.push(node->left);
                        if(node->right) que.push(node->right);
                  }
                  result.push_back(vec);
            }
            return result;
      }
};