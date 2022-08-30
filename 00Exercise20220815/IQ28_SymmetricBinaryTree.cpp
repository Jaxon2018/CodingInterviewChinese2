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

