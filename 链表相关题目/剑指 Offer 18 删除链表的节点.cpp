��ָ Offer 18 ɾ������Ľڵ�
��һ������αͷ�ڵ��ɾ��
 ListNode* deleteNode(ListNode* head, int val) {
        ListNode* H=new ListNode(0);//αͷ���
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
����������ͷ����ɾ��
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

