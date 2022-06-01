//#include"pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

struct memNode {
	int start;  //�ڴ����ʼλ��
	int end;  //�ڴ����ֹλ�ã�������
	int hand; //�����
	bool operator<(memNode &b)
	{
		return start < b.start;
	}
};

list<memNode> empty;//�յ��ڴ������
list<memNode> used; //�ѷ����ڴ�����
int MaxMem;
int handle = 0;

int mynew(int maxsize, int size)
{
	//�ڿ���������Ѱ�ҿ����ڴ��
	for (list<memNode>::iterator i = empty.begin(); i != empty.end(); i++)
	{
		if (i->end - i->start + 1 > size)//���ÿ��п���������ڴ棬���ÿ�ָ������Ĳ��ּ���used�����¸ÿ�ʣ�¿��е���ʼλ��
		{
			handle++;
			memNode m;
			m.start = i->start;
			m.end = i->start + size - 1;
			m.hand = handle;
			used.push_back(m);
			i->start = i->start + size;
			return handle;
		}
		else if (i->end - i->start + 1 == size)//���ÿ��п���������ڴ棬���ÿ����used����empty��ɾȥ�ÿ�
		{
			handle++;
			memNode m;
			m.start = i->start;
			m.end = i->end;
			m.hand = handle;
			used.push_back(m);
			empty.erase(i);
			return handle;
		}
	}
	return false;  //�Ҳ������ʵĿ��п������ʧ��
}
bool del(int handle)//�ͷ��ڴ��
{
	bool res = false;
	for (list<memNode>::iterator i = used.begin(); i != used.end(); i++) //���ݾ����used�в����ڴ�
	{
		if (i->hand == handle)
		{
			res = true;
			for (list<memNode>::iterator ie = empty.begin(); ie != empty.end(); ie++)//��ΪҪ���ÿ鷵�ص������ڴ������У�ͬʱÿ�η�����п�ʱ��ҪС��ַ���ȣ�����ҪѰ�Һ��ʵĲ���λ�ã�����used��ɾ���ÿ�
			{
				//���ÿ����ÿ�����empty�е�ĳ�����п���β�����������empty�иÿ��п����ʼ����ֹλ��
				if (ie->end + 1 == i->start)
				{
					ie->end = i->end;
					used.erase(i);
					return true;
				}
				if (i->end + 1 == ie->start)
				{
					ie->start = i->start;
					used.erase(i);
					return true;
				}
				//�ҵ���һ����ʼ��ַ���ڸ��ͷ��ڴ�����ֹ��ַ�Ŀ��п飬���ÿ���뵽��ǰ�档
				if (i->end + 1 < ie->start)
				{
					memNode m;
					m.start = i->start;
					m.end = i->end;
					m.hand = 0;
					used.erase(i);
					empty.insert(ie, m);
					return true;
				}
			}
			//�����������������ֱ����emptyĩβ����
			memNode m;
			m.start = i->start;
			m.end = i->end;
			m.hand = 0;
			empty.push_back(m);
			used.erase(i);
			return true;
		}
	}
	return res;
}
void def()
{
	used.sort();//��Ҫ�ӵ͵�ַ��ʼǨ�ƣ������ȶ�used��������
	int count = 1;//��¼��ǰused��ʹ�õ���λ��
	for (list<memNode>::iterator i = used.begin(); i != used.end(); i++)//����used���ڴ��ĵ�ַ������͵�ַ��Ǩ��
	{
		i->end = i->end - i->start + count;
		i->start = count;
		count = i->end + 1;
	}
	//empty�����п��п�ϲ������Խ�����գ�����count������ڴ��ַ�ĵ�ַ��
	empty.clear();
	memNode m;
	m.start = count;
	m.end = MaxMem;
	m.hand = 0;
	empty.push_back(m);
}
int main()
{
	int T;
	cin >> T >> MaxMem;
	memNode m;
	m.start = 1;
	m.end = MaxMem;
	empty.push_back(m);
	for (int i = 0; i < T; i++)
	{
		string order;
		int size;
		cin >> order;
		if (order.compare("new") == 0)
		{
			cin >> size;
			int res = mynew(MaxMem, size);
			if (res == 0)
				cout << "NULL" << endl;
			else
				cout << res << endl;
		}
		else if (order.compare("del") == 0)
		{
			cin >> size;
			bool res = del(size);
			if (!res)
				cout << "ILLEGAL_OPERATION" << endl;
		}
		else if (order.compare("def") == 0)
			def();
	}
	return 0;
}

