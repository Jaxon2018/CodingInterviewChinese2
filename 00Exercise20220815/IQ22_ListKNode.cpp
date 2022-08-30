struct ListNode{
      int m_nValue;
      ListNode* m_pNext;
}

// primary solution
ListNode* FindKToTail(ListNode* pListHead, unsigned int k)
{
      ListNode* pAhead = pListHead;
      ListNode* pBehind = nullptr;

      for(unsigned int i = 0; i < k - 1; i++)
      {
            pAhead = pAhead->m_pNext;
      }

      pBehind = pListHead;

      while(pAhead->m_pNext != nullptr)
      {
            pAhead = pAhead->m_pNext;
            pBehind = pBehind->m_pNext;
      }

      return pBehind;

}

// 
ListNode* FindKToTail(ListNode* pListHead, unsigned int k)
{
      // 验证用户输入是否符合要求
      if(pListHead == nullptr || k == 0)
            return nullptr;

      ListNode* pAhead = pListHead;
      ListNode* pBehind = nullptr;

      for(unsigned int i = 0; i < k - 1; i++)
      {
            if(pAhead->m_pNext != nullptr)
            {
                  pAhead = pAhead->m_pNext;
            }
            else{ // 节点数量小于k的情况
                  return nullptr;
            }            
      }

      pBehind = pListHead;

      while(pAhead->m_pNext != nullptr)
      {
            pAhead = pAhead->m_pNext;
            pBehind = pBehind->m_pNext;
      }

      return pBehind;

}