struct ListNode{
      int m_nValue;
      ListNode* m_pNext;
}

// primary solution
ListNode* MeetingNode(ListNode* pHead)
{
      if(pHead == nullptr)
      {
            return nullptr;
      }

      ListNode* pSlow = pHead->m_pNext;
      if(pSlow == nullptr)
      {
            return  nullptr;
      }

      ListNode* pFast = pSlow->m_pNext;
      while(pFast != nullptr && pSlow != nullptr)
      {
            if(pFast == pSlow)
            {
                  return pFast;
            }

            pSlow = pSlow->m_pNext;

            pFast = pFast->m_nNext;
            if(pFast != nullptr)
            {
                  pFast = pFast->m_nNext;
            }
      }

      return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
      ListNode* meetingnode = MeetingNode(pHead);
      if(meetingnode == nullptr)
      {
            return nullptr;
      }

      // 得到环中节点的数目
      int nodes_number = 1;
      ListNode* pNode1 = meetingnode;
      while(pNode1->m_pNext != meetingnode)
      {
            pNode1 = pNode1->m_pNext;
            ++nodes_number;
      }

      // 先移动pNode1，次数为环中节点的数目
      pNode1 = pHead;
      for(int i = 0; i < nodes_number; i++)
      {
            pNode1 = pNode1->m_pNext;
      }

      // 再移动pNode1和pNode2, 找到环入口节点
      ListNode* pNode2 = pHead;
      while(pNode1 != pNode2)
      {
            pNode1 = pNode1->m_pNext;
            pNode2 = pNode2->m_pNext;
      }

      return pNode2;
}

