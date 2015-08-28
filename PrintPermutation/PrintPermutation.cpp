// PrintPermutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

stack<char> stk;

void printstk(stack<char> stk)
{
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
	cout << endl;
}

void printpermutation(char* str, int size)
{
	char* pcur = str;
	if (str==NULL||*str=='\0'||size<1)
	{
		//cout << endl;
		return;
	}
	int len = strlen(str);
	if (len<size)
	{
		return;
	}
	
	if (size==1)
	{
		//cout << *pcur << endl;
		stk.push(*pcur);
		printstk(stk);
		stk.pop();
		printpermutation(++pcur, 1);
	}
	if (size>1)
	{
		//cout << *pcur;
		stk.push(*pcur);
		pcur++;
		printpermutation(pcur,size-1);
		stk.pop();
		if (size<=len-1)
		{
			printpermutation(pcur, size);
		}
		
	}

}

//打印字符串所有可能的组合（例如：abc的组合有 a,b,c,ab,bc,ac,abc,bc和cb是一个组合）
void printpermutation(char* str)
{
	if (str==NULL||*str=='\0')
	{
		return;
	}
	int len = strlen(str);
	for (size_t size = 1; size <= len; size++)
	{
		printpermutation(str, size);
	}
	

}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[] = "abcdef";
	printpermutation(str);
	return 0;
}

