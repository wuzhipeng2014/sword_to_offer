// decimal_26radix.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

void decimal_26radix(int x,stack<char>& is)
{
	
	while (x>0)
	{
		int remainder = x % 26;
		is.push(char(remainder+'A'));
		x = x / 26;
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 30;
	stack<char> is;
	decimal_26radix(x,is);
	while (!is.empty())
	{
		cout << is.top();
		is.pop();
	}
	cout << endl;
	return 0;
}

