// Permutation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

static int countnum = 1;

//��������еݹ���õĺ�����str��ʾ������ַ���
//start��ʾ�˴ε���Ҫ��������ַ���
//len��ʾ�˴δ�����ַ����ĳ���
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

//����һ���ַ�����������ַ����������ַ���ȫ����������
void permutation(char* str)
{
	if (str!=NULL&&*str!='\0')
	{
		int len = strlen(str);

		permutation(str,0,len);//�������صĺ���
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//char str[] = "";
	char* str=0;
	permutation(str);
	return 0;
}

