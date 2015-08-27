// ispoporderright.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool ispoporderright(char* instr, char* outstr)
{
	stack<char> s;
	char* pin, *pout;
	pin = instr;
	pout = outstr;
	while (*pin!='\0'&&*pout!='\0')
	{
		if (s.empty()||s.top()!=*pout)
		{
			s.push(*pin);
			pin++;
		}
		else 
		{
			while (*pout!='\0'&&!s.empty()&&s.top()==*pout)
			{
				s.pop();
				pout++;
			}
		}
	}

	while (!s.empty()&&*pout!='\0'&&s.top()==*pout)
	{
		s.pop();
		pout++;
	}
	if (*pout=='\0'&&*pin=='\0'&&s.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* pin = "1234";
	char* pout = "3214";
	bool re = ispoporderright(pin,pout);
	cout << re << endl;
	return 0;
}

