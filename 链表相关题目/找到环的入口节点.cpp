找到环的入口节点（重要）
 ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode* low=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            low=low->next;
            fast=fast->next->next;
            if(low==fast)
            {
                break;
            }
        }
        if(low==NULL)
        {
            return NULL;
        }
        fast=head;
        while(low!=NULL)
        {
            if(fast==low)
            {
                return low;
            }
            low=low->next;
            fast=fast->next;
        }
        return NULL;
    }

