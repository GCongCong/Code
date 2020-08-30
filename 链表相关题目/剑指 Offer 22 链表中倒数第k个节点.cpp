剑指 Offer 22 链表中倒数第k个节点
ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* A=head;
        ListNode* B=head;
        for(int i=0;i<k;i++)
        {
            A=A->next;
        }
        while(A!=NULL)
        {
            A=A->next;
            B=B->next;
        }
        return B;
    }

