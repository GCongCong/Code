 //��ָ Offer 24 ��ת����
 ��һ���Լ�����α�ڵ�ķ�ת
  ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* H =new ListNode(0);//α�ڵ�
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
����������ͷ���ķ�ת
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


