/*
��Ʋ�ʵ�ֿγ���
*/

//#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Course//����γ���
{
private:
	
public:
	int coursenum;//�γ̺�
	string coursename;//�γ���
	int courseforenum;//���޿εĿγ̺�
	Course() {};
	Course(string name, int forecourse)//���캯��
	{
		coursename = name;
		courseforenum = forecourse;
	}
	~Course() {};//��������

	int getcoursename(string name)//��ÿγ���
	{
		coursename = name;
		return 0;
	}
	int getcoursenum(int num)//��ÿγ̺�
	{
		coursenum=num;
		return 0;
	}
	int gercourseforenum(int num)//������޿εĿγ̺�
	{
		courseforenum = num;
		return 0;
	}
	int putcourseforenum()//������޿εĿγ̺�
	{
		return courseforenum;
	}
};

int main()
{
	Course school[255];//����һ���γ�����
	int allcourse = 0,coursefornum=-1;//����γ�����=0���γ����޿�Ĭ��-1
	string function;//����ӿ�
	string coursename;//����γ���
	int coursenum, temporarynum=-1;
	do
	{
		
		cin>>function;
		if (function.compare("c") == 0)//�ӿ�Ϊcʱ��Ϊ�γ����鸳ֵ
		{
			cin >> coursename >> coursefornum;
			school[allcourse].getcoursename(coursename);
			school[allcourse].gercourseforenum(coursefornum);
			school[allcourse].getcoursenum(allcourse++);
		}
		if (function.compare("s") == 0)//�ӿ�Ϊsʱ��չʾ���пγ�
		{
			
			for (int i = 0; i <= allcourse-1; i++)
			{
				cout << "Course " << i << "-" << school[i].coursename << " has prerequisites: ";
				if (school[i].courseforenum != -1)
				{
					temporarynum = school[i].putcourseforenum();
					do
					{
						cout << school[temporarynum].coursename<<" ";
						temporarynum = school[temporarynum].putcourseforenum();
					} while (temporarynum != -1);
					cout << endl;
				}
				else cout << "none"<<endl;
			}
			function = "y";
		}
		if (function.compare("e") == 0)//�ӿ�Ϊeʱ���˳�����
		{
			break;
		}
	} while (true);
	
	return 0;
}

