剑指 Offer 25 合并两个排序的链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
        if(l1==NULL)//空链表处理
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        ListNode* head=new ListNode(0);//申请头节点
        ListNode* res=head;//指向头节点的指针
        while(l1!=NULL && l2!=NULL)//循环条件
        {
            if(l1->val > l2->val)
            {
               res->next=l2;//连接
               res=res->next;//z指向新连接的
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
            res->next=l2;//把剩下的连接上
        }
        if(l2==NULL)
        {
            res->next=l1;
        }
        return head->next;//不需要头节点
}

