��ָ Offer 35 ��������ĸ���
��һ����ϣ��
 Node* copyRandomList(Node* head) {
 		if(head==NULL)
 		{
 			return NULL;
 		}
        Node* p=head;
        map<Node*,Node*>res;
        while(p!=NULL)//����ӳ���ϵ
        {
            Node* temp=new Node(p->val);
            res[p]=temp;
            p=p->next;
        }
        p=head;
        while(p!=NULL)//nextָ���randomָ��Ĵ���
        {
            res[p]->next=res[p->next];
            res[p]->random=res[p->random];
            p=p->next;
        }
        return res[head];
    }

������ԭ�ظ���
Node* copyRandomList(Node* head) {
        if(head==NULL)
        {
            return NULL;
        }
        Node* p=head;
        while(p!=NULL)//�ŵ��ɽ��ĺ���
        {
            Node* temp=new Node(p->val);
            temp->next=p->next;
            p->next=temp;
            p=p->next->next;
        }
        p=head;
        while(p!=NULL)//����randomָ��
        {
            if(p->random!=NULL)
            {
                p->next->random=p->random->next;//�½ڵ��randomָ��ָ��ɽ���random��next
            }
            p=p->next->next;
        }
        p=head;
        Node* newhead=new Node(0);
        Node* res=newhead;
        while(p!=NULL)//��������
        {
           Node* temp=p->next;
           res->next=temp;
           p->next=temp->next;
           p=p->next;
           res=res->next;
        }
        return newhead->next;
    }

