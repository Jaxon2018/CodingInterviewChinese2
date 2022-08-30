struct ListNode{
      int m_nValue;
      ListNode* m_pNext;
      ListNode():m_nValue(0), m_pNext(nullptr){}
      ListNode(int x):m_nValue(x), m_pNext(nullptr){}
      ListNode(int x, ListNode* next):m_nValue(x), m_pNext(next){}
}

// 结合Carl参考答案的自己的答案：大的逻辑架构清晰，翻转遍历链表的逻辑清晰
class Solution{
public:
      ListNode* reverseList(ListNode* head){
            if(head == nullptr)
            {
                  return head;
            }

            if(head->m_pNext == nullptr)
            {
                  return head;
            }else{
                  ListNode* cur = head;
                  ListNode* pre = nullptr;
                  ListNode* pTmp = nullptr;

                  while(cur)
                  {
                        pTmp = cur->m_pNext;
                        cur->m_pNext = pre;
                        pre = cur;
                        cur = pTmp;
                  }
                  return pre;
            }
      }
}

//-------------------剑指OfferV2参考答案-------------
#include <cstdio>
#include "..\Utilities\List.h"

ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;
    while(pNode != nullptr)
    {
        ListNode* pNext = pNode->m_pNext;

        if(pNext == nullptr)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;

        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}





