��ָ Offer 22 �����е�����k���ڵ�
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

