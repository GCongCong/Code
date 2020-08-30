剑指 Offer 06 从尾到头打印链表

//1.利用栈
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
		ar.push_back(stk.top());//top得到栈顶元素
		stk.pop();//pop删除
	}
	return ar;
}


