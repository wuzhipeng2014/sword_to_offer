// Permutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

static int countnum = 1;

//输出过程中递归调用的函数，str表示输入的字符串
//start表示此次调用要处理的字字符串
//len表示此次处理的字符串的长度
void permutation(char* str, int start, int len)
{
	
	if (len==1)
	{
		cout << countnum++ << " ";
		cout << str << endl;
		return;
	}
	for (size_t i = 0; i < len; i++)
	{
		swap(str[start], str[start + i]);
		permutation(str,start+1,len-1);
		swap(str[start], str[start + i]);

	}

}

//输入一个字符串，输出该字符串中所有字符的全部可能排列
void permutation(char* str)
{
	if (str!=NULL&&*str!='\0')
	{
		int len = strlen(str);

		permutation(str,0,len);//调用重载的函数
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//char str[] = "";
	char* str=0;
	permutation(str);
	return 0;
}

