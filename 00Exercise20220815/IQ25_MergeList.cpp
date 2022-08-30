struct ListNode{
      int m_nValue;
      ListNode* m_pNext;
      ListNode():m_nValue(0), m_pNext(nullptr){}
      ListNode(int x):m_nValue(x), m_pNext(nullptr){}
      ListNode(int x, ListNode* next):m_nValue(x), m_pNext(next){}
}


// my own first solution
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
      if(pHead1 == nullptr || pHead2 == nullptr)
      {
            return nullptr;
      }

      if(*pHead1 == nullptr && *pHead2 != nullptr)
      {
            return pHead2;
      }else if(*pHead1 != nullptr && *pHead2 == nullptr){
            return pHead1;
      }else if(*pHead1 == nullptr && *pHead2 == nullptr){
            return pHead2;
      }

      ListNode* cur1 = pHead1;
      ListNode* pTmp1 = nullptr;
      ListNode* cur2 = pHead2;
      ListNode* pTmp2 = nullptr; 
      ListNode* cur = nullptr;
      
      while(cur1->m_pNext && cur2->m_pNext)
      {
            if(cur1->m_nValue < cur2->m_nValue)
            {
                  pTmp1 = cur1->m_pNext;
                  cur1->m_pNext = cur2;
                  cur1 = pTmp1;

                  cur = cur2;
                  cur = changeNode(cur, cur1);
            }else if(cur1->m_nValue > cur2->m_nValue){
                  pTmp2 = cur2->m_pNext;
                  cur2->m_pNext = cur1;
                  cur2 = pTmp2;

                  cur = cur1;
                  cur = changeNode(cur, cur2);
            }else if(cur1->m_pNext->m_nValue < cur2->m_pNext->m_nValue){
                  pTmp2 = cur2->m_pNext;
                  cur2->m_pNext = cur1;
                  cur2 = pTmp2; 

                  cur1 = cur1->m_pNext;

                  cur = cur1;
                  cur = changeNode(cur, cur2);
            }else if(cur1->m_pNext->m_nValue > cur2->m_pNext->m_nValue){
                  pTmp1 = cur1->m_pNext;
                  cur1->m_pNext = cur2;
                  cur1 = pTmp1;
                  
                  cur2 = cur2->m_pNext;

                  cur = cur2;
                  cur = changeNode(cur, cur1);
            }
      }




}

// pNode1为新链表处理的当前节点, pNode2为另一个链表的当前处理节点
// 返回新链表新的当前节点
ListNode* changeNode(ListNode* pNode1, ListNode* pNode2)
{
      if(pNode1->m_pNext == nullptr)
      {
            pNode1->m_pNext = pNode2;
            pNode1 = nullptr;

            return pNode2;
      }

      if(pNode1->m_pNext->m_nValue > pNode2->m_nValue)
      {
            ListNode* pTmp1 = pNode1->m_pNext;
            pNode1->m_pNext = pNode2;
            pNode1 = pTmp1;

            return pNode2;

      }else if(pNode1->m_pNext->m_nValue <= pNode2->m_nValue){
            pNode1 = pNode1->m_pNext;

            return pNode1;
      }

}

// 主要的程序设计关键点都想到了：两个链表第一个元素比较，然后递归；鲁棒性分析；

//-------------------------------
// 参考答案的递归的循环表达代码？





