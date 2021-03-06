// Stack_copy.cpp : 定义控制台应用程序的入口点。
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

//打印栈中的元素
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

//求栈中所有元素的和
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

//根据前序遍历的顺序，
//打印从跟结点到所有叶节点的路径(所有路径和等于给定值的路径)
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


typedef pair<node*, node*> head_rear;
//将二叉搜索树转换为排序的双向链表
head_rear convert_searchtree2list(node* root)
{
	head_rear rtn;
	node* p = 0;
	head_rear pre = make_pair(p,p);;
	head_rear post = make_pair(p,p);
	if (root==NULL)
	{
		
		return make_pair(p, p);
	}
	if (root->pleft==NULL)
	{

		pre.first = root;
		pre.second = root;
		/*root->pleft =root;*/

	}
	else
	{
		pre = convert_searchtree2list(root->pleft);
		root->pleft = pre.second;
		if (pre.second)
		{
			pre.second->pright = root;
		}
		
	}

	if (root->pright==NULL)
	{
		post.first = root;
		post.second = root;
		/*root->pright = root;*/
	}
	else
	{
		post = convert_searchtree2list(root->pright);
		root->pright = post.first;
		if (post.first)
		{
			post.first->pleft = root;
		}
		
	}

#pragma region
	/*if (root->pleft)
	{
		 pre= convert_searchtree2list(root->pleft);
		root->pleft = pre.second;
		pre.second->pright = root;
	}
	if (root->pright)
	{
		 post = convert_searchtree2list(root->pright);
		root->pright = post.first;
		post.first->pleft = root;
	}*/
#pragma endregion
	return make_pair(pre.first,post.second);
	/*if (pre.first||post.second)
	{
		return make_pair(pre.first, post.second);
	}
	else
	{
		return rtn;
	}*/
	
}

//构建一个二叉的搜索树
node* creat_searchtree()
{
	node* n1 = new node(20);
	node* n2 = new node(10);
	node* n3 = new node(30);
	node* n4 = new node(5);
	node* n5 = new node(15);
	node* n6 = new node(25);
	node* n7 = new node(35);
	n1->pleft = n2;
	n1->pright = n3;
	n2->pleft = n4;
	n2->pright = n5;
	n3->pleft = n6;
	n3->pright = n7;
	return n1;
}

node* creat_st()
{
	node* n1 = new node(20);
	node* n2 = new node(10);
	node* n3 = new node(30);
	node* n4 = new node(5);
	node* n5 = new node(15);
	node* n6 = new node(25);
	node* n7 = new node(35);
	n1->pleft = n2;
	n2->pleft = n5;
	n5->pleft = n4;
	return n1;
}


//打印链表中的数据
void printlist(node* root)
{
	node* pcur = root;
	while (pcur)
	{
		cout << pcur->data << " ";
		pcur = pcur->pright;
	}
	cout << endl;

}

void printlist_reverse(node* root)
{
	node* pcur = root;
	while (pcur->pright)
	{
		pcur = pcur->pright;
	}
	while (pcur)
	{
		cout << pcur->data << " ";
		pcur = pcur->pleft;
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

#pragma region //stack的复制
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

#pragma region //打印二叉树的所有路径
	/*node* root = createBT();
	printpath(root,10);*/
#pragma endregion

#pragma region //将排序二叉树转换为排序的双向链表
	//node* root = creat_searchtree();
	node* root = creat_st();
	head_rear re= convert_searchtree2list(root);
	printlist(re.first);
	//printlist(re.second);
	printlist_reverse(re.first);

	
#pragma endregion
	return 0;
}

