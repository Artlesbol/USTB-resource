
// ConsoleApplication1.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
//#include "pch.h"
#include <iostream>
#include"stdlib.h"
#include"string.h"

using namespace std;
int getastring(char *a);
int putanswer(int a);



int getastring(char *flagstring)//��ȡ�Ӵ����Ӵ��ĳ��ִ���
{
	int flaglength, fatherlength, sonlength, count = 0;
	flaglength = strlen(flagstring);
	char* fatherstring = (char*)malloc(sizeof(char*) * flaglength);
	char* sonstring = (char*)malloc(sizeof(char*) * flaglength);
	int i = 0, j = 0;
	do
	{
		*(fatherstring + i) = *(flagstring + i);
		i++;
	} while (*(flagstring + i) != ' '); *(fatherstring + i) = '\0'; i++;
	do
	{
		*(sonstring + j) = *(flagstring + i);
		i++; j++;
	} while (*(flagstring + i) != '\0'); *(sonstring + j) = '\0';
	fatherlength = strlen(fatherstring);
	sonlength = strlen(sonstring);
	for (i = 0; i < fatherlength; i++)
	{
		int k = 0;//����ÿ���ַ���



		
		do
		{
			
			if (*(sonstring + k) == '\0' || *(fatherstring + i + k)=='\0')
			{
				break;
			}
			k++;
		} while (*(fatherstring + i + k) == *(sonstring + k));
		
		if (k == (sonlength))
		{
			count++;
		}


	}
	free(sonstring);
	free(fatherstring);
	return count;
}

int putanswer(int a)//�����
{
	std::cout << a << std::endl;
	return 0;
}
int main()
{
	int strLen = 5;
	char ch;
	char* str = (char*)malloc(sizeof(char*) * strLen);
	int count = 0;
	do
	{
		std::cin.get(ch);
		count++;
		if (count >= strLen)
		{
			str = (char*)realloc(str, sizeof(char*) * (++strLen));
		}
		*(str + count - 1) = ch;

	} while (ch != '\n');
	*(str + count-1) = '\0';//�����ַ���
	putanswer(getastring(str));
	free(str);
	return 0;
}
// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�


