判断链表是否有环
bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
        {
            return false;
        }
        ListNode* low = head;
        ListNode* fast = head->next;
        while (fast!=NULL && fast->next != NULL)
        {
            if(low == fast)
            {
                return true;
            }
            low=low->next;
            fast=fast->next->next;
        }
        return false;
    }

