// decimal_26radix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <time.h>

using namespace std;

//将10进制数转换为26进制的数
void decimal_26radix(int x,stack<char>& is)
{
	
	
	while (x>0)
	{
		int remainder = x % 26;
		is.push(char(remainder+'A'));
		x = x / 26;
	}
	
}

//输出1到最大的n位数之间的所有数字
//n表示最大的数字的位数
void print_nbits_max(int n)
{

	time_t begin, duration;
	string max_num(n, '9');
	string output_str(n,'0');
	int len = 0;
	int carry = 0;
	begin = clock();
	while (strcmp(max_num.c_str(),output_str.c_str()))
	{
		carry = 1;
		len = strlen(output_str.c_str());
		for (size_t i = 0; i < len&&carry==1; i++)
		{
			if (output_str[len - 1 - i] + 1>'9')
			{
				carry = 1;
				output_str[len - 1 - i] = '0';
			}
			else
			{
				carry = 0;
				output_str[len - 1 - i] += 1;
			}
		}
		//输出的时候，可以考虑将字符串前面的0去掉
		int k = 0;
		while (k<len)
		{
			if (output_str[k] != '0')
			{
				cout << &output_str[k] << " ";
				break;
			}
			k++;
				
			
		}
		//cout << output_str << " ";

	}
	cout << endl;
	cout << "运行时间为";
	duration = clock() - begin;
	cout << "duration= " << duration << endl;
}

struct node
{
	node(int value=0):data(value),pleft(0),pright(0){}
	int data;
	node * pleft;
	node * pright;

};

//判断一个子树是否和另外一个子树相同
bool issubtreecomman(node* root1, node* root2)
{
	if (root1==NULL)
	{
		return false;
	}
	if (root2==NULL)
	{
		return true;
	}
	if (root1->data!=root2->data)
	{
		return false;
	}

	return (issubtreecomman(root1->pleft,root2->pleft)&&issubtreecomman(root1->pright,root2->pright));


}

//判断一个子树(root2)结构是否是另外一个子树(root1)的子树
bool issubtree(node* root1, node* root2)
{
	bool result = false;
	if (root1!=NULL&&root2!=NULL)
	{
		if (root1->data == root2->data)
		{
			result= issubtreecomman(root1,root2);
		}
		if (!result)
		{
			result = issubtreecomman(root1->pleft,root2->pright);
		}
		if (!result)
		{
			result = issubtreecomman(root1->pright,root2->pright);
		}
		return	result;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
#pragma region //将十进制数转换为26进制
	//int x = 30;
	//stack<char> is;
	//decimal_26radix(x,is);
	//while (!is.empty())
	//{
	//	cout << is.top();
	//	is.pop();
	//}
	//cout << endl;
#pragma endregion

#pragma region //
	/*int a = -12;
	 int b = (unsigned int)a;
	 if (a<0)
	 {
		 b = unsigned int(-a);
	 }
	cout << b << endl;*/

#pragma endregion

#pragma region //打印1到n位的数之间的所有数字
	/*string str(3,'9');
	cout<<str << endl;*/
	print_nbits_max(4);
	cout << endl;
#pragma endregion
	return 0;
}

