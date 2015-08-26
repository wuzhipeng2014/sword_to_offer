// decimal_26radix.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <time.h>

using namespace std;

//��10������ת��Ϊ26���Ƶ���
void decimal_26radix(int x,stack<char>& is)
{
	
	
	while (x>0)
	{
		int remainder = x % 26;
		is.push(char(remainder+'A'));
		x = x / 26;
	}
	
}

//���1������nλ��֮�����������
//n��ʾ�������ֵ�λ��
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
		//�����ʱ�򣬿��Կ��ǽ��ַ���ǰ���0ȥ��
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
	cout << "����ʱ��Ϊ";
	duration = clock() - begin;
	cout << "duration= " << duration << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
#pragma region //��ʮ������ת��Ϊ26����
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

#pragma region //��ӡ1��nλ����֮�����������
	/*string str(3,'9');
	cout<<str << endl;*/
	print_nbits_max(4);
	cout << endl;
#pragma endregion
	return 0;
}

