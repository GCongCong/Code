��ָ Offer 25 �ϲ��������������
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
        if(l1==NULL)//��������
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        ListNode* head=new ListNode(0);//����ͷ�ڵ�
        ListNode* res=head;//ָ��ͷ�ڵ��ָ��
        while(l1!=NULL && l2!=NULL)//ѭ������
        {
            if(l1->val > l2->val)
            {
               res->next=l2;//����
               res=res->next;//zָ�������ӵ�
               l2=l2->next;
            }
            else
            {
                res->next=l1;
                res=res->next;
                l1=l1->next;
            }   
        }
        if(l1==NULL)
        {
            res->next=l2;//��ʣ�µ�������
        }
        if(l2==NULL)
        {
            res->next=l1;
        }
        return head->next;//����Ҫͷ�ڵ�
}

