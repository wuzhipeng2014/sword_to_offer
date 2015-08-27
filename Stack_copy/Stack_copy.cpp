// Stack_copy.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stack>
#include <iostream>
using namespace std;


struct node
{
	node(int d = 0) :data(d), pleft(0), pright(0){}
	int data;
	node* pleft;
	node* pright;
};
node* createBT()
{
	node* root = new node(1);
	node* n2 = new node(2);
	node* n3 = new node(3);
	node* n4 = new node(4);
	node* n5 = new node(5);
	node* n6 = new node(6);
	node* n7 = new node(7);
	node* n8 = new node(8);
	node* n9 = new node(9);
	root->pleft = n2;
	root->pright = n3;
	n2->pleft = n4;
	n2->pright = n5;
	n3->pleft = n6;
	n3->pright = n7;
	n4->pleft = n8;
	n4->pright = n9;
	return root;

}

void printstack(stack<int> s)
{
	stack<int> tmp = s;
	while (!tmp.empty())
	{
		cout << tmp.top() << " ";
		tmp.pop();
	}
	cout << endl;
}

//��ջ������Ԫ�صĺ�
int sumofstack(stack<int> s)
{
	int sum = 0;
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	return sum;
}

//����ǰ�������˳��
//��ӡ�Ӹ���㵽����Ҷ�ڵ��·��(����·���͵��ڸ���ֵ��·��)
void printpath(node * root,int n)
{
	static	stack<int> paths;
	if (root == NULL)
	{
		return;
	}
	paths.push(root->data);
	if (root->pleft == NULL&&root->pright == NULL)
	{
		if (sumofstack(paths)==n)
		{
			printstack(paths);
		}
	
		/*paths.pop();*/
	}

	printpath(root->pleft,n);
	printpath(root->pright,n);
	paths.pop();

}



int _tmain(int argc, _TCHAR* argv[])
{

#pragma region //stack�ĸ���
	//stack<int> is;
	//for (size_t i = 0; i < 10; i++)
	//{
	//	is.push(i);
	//}
	//stack<int> is2 = is;
	//while (!is.empty())
	//{
	//	cout << is.top() << " ";
	//	is.pop();
	//}
	//cout << endl;
	//while (!is2.empty())
	//{
	//	cout << is2.top()<<" ";
	//	is2.pop();
	//}
#pragma endregion

#pragma region //��ӡ������������·��
	node* root = createBT();
	printpath(root,10);
#pragma endregion
	return 0;
}

