ɾ���ظ�����
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        {
            return NULL;//ע���ж��쳣
        }
        ListNode* low=head;
        ListNode* fast=head->next;
        while(fast!=NULL)
        {
            if(low->val==fast->val)
            {
                low->next=fast->next;
                fast=fast->next;
            }
            else
            {
               low=low->next;
            }
        }
        return head;
    }

