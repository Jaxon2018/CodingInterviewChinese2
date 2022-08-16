struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int x):m_nValue(x), m_pNext(nullptr){}
}

void AddToTail(ListNode** pHead, int value)
{
    // ListNode* pNew = new ListNode(value);
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;

    if(*pHead == nullptr)
    {
        *pHead = pNew;
    }else{
        ListNode* pNode = *pHead;

        while(pNode->m_pNext != nullptr)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;// add ListNode
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;
    
    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }else{
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
        {
            pNode = pNode->m_pNext;
        }

        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;// delete ListNode
        }
    }

    if(pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

//--------------------------------------
struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int x):m_nValue(x), m_pNext(nullptr){}
}

void ReverseList(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;
    
    if((*pHead)->m_pNext == nullptr)
    {
        return;
    }else{
        ListNode* pNode = *pHead;
        ListNode* pTmpNode = nullptr;
        while(pNode->m_pNext != nullptr)
        {
            pTmpNode = pNode;
            pNode = pNode->m_pNext;
            pTmpNode == pNode->m_pNext;
        }
        ListNode* pTmpNode = nullptr;
        *pHead = pNode; //change the position of head node
    }    
}

//Carl Answer myown
void ReverseList(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;
    
    if((*pHead)->m_pNext == nullptr)
    {
        return;
    }else{
        ListNode* cur = *pHead;
        ListNode* pre = nullptr;
        ListNode* pTmpNode = nullptr;
        while(cur->m_pNext != nullptr)
        {
            pTmpNode = cur;            
            cur = cur->m_pNext;
            pTmpNode->m_pNext = pre; // reverse
            pre = pTmpNode;
        }
        ListNode* pTmpNode = nullptr;
        *pHead = cur; //change the position of head node
    }    
}


//-------------------------------
//LeetCode Submit
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
    
        if((head)->next == nullptr)
        {
            return head;
        }else{
            ListNode* cur = head;
            ListNode* pre = nullptr;
            ListNode* pTmpNode = nullptr;
            // while(cur->next != nullptr)    少了最后一个节点的翻转
            while(cur != nullptr)
            {
                pTmpNode = cur;            
                cur = cur->next;
                pTmpNode->next = pre; // reverse
                pre = pTmpNode;
            }
            // pTmpNode = nullptr;
            // head = cur; //change the position of head node
            head = pre;
            return head;
        }
        // return head;
    }
};

//Carl STD Answer
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
            // pre = cur;  it is before cur = temp;
            
        }
        return pre;
    }
};

//====================================
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }

}