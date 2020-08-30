��ָ Offer 52 ��������ĵ�һ�������ڵ�
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

