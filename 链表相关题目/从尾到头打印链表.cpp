��ָ Offer 06 ��β��ͷ��ӡ����

//1.����ջ
vector<int> printListFromTailToHead(ListNode* head)
{
	vector<int> ar;  
	stack <int> stk;
	while(head!=NULL)
	{
		stk.push(head->val);
		head=head->next;
	}
	while(!stk.empty())
	{
		ar.push_back(stk.top());//top�õ�ջ��Ԫ��
		stk.pop();//popɾ��
	}
	return ar;
}


