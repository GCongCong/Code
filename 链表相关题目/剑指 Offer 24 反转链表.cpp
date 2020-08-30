 //剑指 Offer 24 反转链表
 （一）自己定义伪节点的反转
  ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* H =new ListNode(0);//伪节点
        H->next=NULL;
        ListNode* p=head;
        while(p!=NULL)
        {
            ListNode* q=p->next;
            p->next=H->next;
            H->next=p;
            p=q;
        }
        return H->next;
    }
（二）不带头结点的反转
 ListNode* reverseList(ListNode* head) {
        if(head== NULL|| head->next ==NULL )
        {
            return head;
        }
        ListNode* p=head;
        head=NULL;
        ListNode* q=p;
       // ListNode* tmp=NULL;
        while(p!=NULL)
        {
            q=p->next;
            p->next=head;
            head=p;
            p=q;
        }
        return head;

    }


