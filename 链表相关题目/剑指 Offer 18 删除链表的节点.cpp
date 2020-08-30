剑指 Offer 18 删除链表的节点
（一）设置伪头节点的删除
 ListNode* deleteNode(ListNode* head, int val) {
        ListNode* H=new ListNode(0);//伪头结点
        H->next=head;
        if(head == NULL)
        {
            return head;
        }
        ListNode* p=H;
        ListNode* q=head;
        bool flag=false;
        while(q!=NULL)
        {
            if(q->val == val)
            {
                flag=true;
                break;
            }
            q=q->next;
            p=p->next;
        }
        if(flag)
        {
            p->next=q->next;
            q->next=NULL;
            return H->next;
        }
       return NULL;
    }
（二）不带头结点的删除
ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL)
        {
            return head;

        }
        if(head->val == val)
        {
            return head->next;
        }
        ListNode* p=head;
        ListNode* q=head->next;
        bool flag=false;
        while(q!=NULL)
        {
            if(q->val == val)
            {
                flag=true;
                break;
            }
            q=q->next;
            p=p->next;
        }
        if(flag)
        {
            p->next=q->next;
            q->next=NULL;
            return head;
        }
       return NULL;
    }

