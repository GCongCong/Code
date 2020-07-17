/*14 2020��3��18 �����ص�
�������б� [x1, y1, x2, y2] ����ʽ��ʾ������ (x1, y1) Ϊ���½ǵ����꣬(x2, y2) �����Ͻǵ����ꡣ
����ཻ�����Ϊ��������������ص�����Ҫ��ȷ���ǣ�ֻ�ڽǻ�߽Ӵ����������β������ص���
�����������Σ��ж������Ƿ��ص������ؽ����
 
ʾ�� 1��
���룺rec1 = [0,0,2,2], rec2 = [1,1,3,3]
�����true
ʾ�� 2��
���룺rec1 = [0,0,1,1], rec2 = [1,0,2,1]
�����false*/
//����˼ά
 bool isRectangleOverlap1(vector<int>& rec1, vector<int>& rec2) 
{
	return !(rec2[2]<=rec1[0]||//left
		rec2[0]>=rec1[2]||//right
		rec2[3]<=rec1[1]||//top
		rec2[1]>=rec1[3]);//botton
}
 //�������
 bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
{
	return (max(rec1[0],rec2[0])<min(rec1[2],rec2[2]))&&
		(max(rec1[1],rec2[1])<min(rec1[3],rec2[3]));
}
 int main()
 {
	 vector<int>a;
	 a.push_back(0);
	 a.push_back(0);
	 a.push_back(1);
	 a.push_back(1);
	 vector<int>b;
	 b.push_back(1);
	 b.push_back(0);
	 b.push_back(2);
	 b.push_back(1);
	 cout<<isRectangleOverlap(a,b);
 }
