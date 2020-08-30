剑指 Offer 52 两个链表的第一个公共节点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode* A=headA;
        ListNode* B=headB;
        while(A!=B)
        {
           A = A == NULL? headB : A->next;
           B = B == NULL? headA : B->next;
        }
        return A;
    }

