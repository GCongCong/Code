剑指 Offer 35 复杂链表的复制
（一）哈希表
 Node* copyRandomList(Node* head) {
 		if(head==NULL)
 		{
 			return NULL;
 		}
        Node* p=head;
        map<Node*,Node*>res;
        while(p!=NULL)//建立映射关系
        {
            Node* temp=new Node(p->val);
            res[p]=temp;
            p=p->next;
        }
        p=head;
        while(p!=NULL)//next指针和random指针的处理
        {
            res[p]->next=res[p->next];
            res[p]->random=res[p->random];
            p=p->next;
        }
        return res[head];
    }

（二）原地复制
Node* copyRandomList(Node* head) {
        if(head==NULL)
        {
            return NULL;
        }
        Node* p=head;
        while(p!=NULL)//放到旧结点的后面
        {
            Node* temp=new Node(p->val);
            temp->next=p->next;
            p->next=temp;
            p=p->next->next;
        }
        p=head;
        while(p!=NULL)//设置random指针
        {
            if(p->random!=NULL)
            {
                p->next->random=p->random->next;//新节点的random指针指向旧结点的random的next
            }
            p=p->next->next;
        }
        p=head;
        Node* newhead=new Node(0);
        Node* res=newhead;
        while(p!=NULL)//分离链表
        {
           Node* temp=p->next;
           res->next=temp;
           p->next=temp->next;
           p=p->next;
           res=res->next;
        }
        return newhead->next;
    }

