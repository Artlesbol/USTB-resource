/*
A+B����
*/

//#include "pch.h"
#include <iostream>
#include "string.h"

using namespace std;
/*
���������ַ���
��������ŵ�������
ͬʱλ�õߵ�����λ����ǰ��
*/
int read_str(char *s, int *a)
{
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
	{
		a[i] = s[n - i - 1] - '0';

	}

	return n;
}
/*
�Ƚ����ֵ
*/
int max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}
int main()
{
	char num[2000];
	int a[2000], b[2000],c[2000];
	int n1,n2;
	cin >> num;
	n1 = read_str(num, a);
	cin >> num;
	n2 = read_str(num, b);
	
	for (int i = 0; i < max(n1,n2); ++i)
		c[i] = 0;
	for (int i = 0; i < max(n1, n2); ++i)
		c[i] = a[i] + b[i];

	// ��λ
	for (int i = 0, m = 0; i < max(n1, n2); ++i)
	{
		c[i] += m;
		m = c[i] / 10;
		c[i] %= 10;
	}
	
	int n = max(n1,n2) - 1;
	for (; c[n] == 0; --n);
	for (; n >= 0; --n)
	{
		cout << c[n];
	}

	return 0;
}

