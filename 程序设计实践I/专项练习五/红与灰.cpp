/*
�����
*/

//#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;//n��m��
	
	/*
	��̬�����ά����
	*/
	char **gamemap,**recordmap;
	gamemap = new char*[n];
	recordmap = new char*[n];
	for (int i = 0; i <  n; i++)
	{
		gamemap[i] = new char[m];
		recordmap[i] = new char[m];
	}

	//�����ͼ����¼��ͼ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> gamemap[i][j];
			recordmap[i][j] = 0;
			if (gamemap[i][j] == '@')
			{
				recordmap[i][j] = 1;
			}
			
		}
	}
	
	/*
	˼·��
		ѭ��ɨ���ͼ����ʼ����(@)��λ��,�ڼ�¼��ͼ��Ϊ1
		��һ��ɨ���ͼ������ڼ�¼��ͼ�Ϸ���1����ô����Ϸ��ͼ�Ķ�Ӧλ��ɨ�踽�����ĸ�����
		����л�ɫ����(.),��ô�ڼ�¼��ͼ�Ͻ���Щ��ɫ���ӵ�λ�ö����1
		�ڶ���ɨ���ͼ�������ҵ�1������Ϸ��ͼ���жϸ����Ļ�ɫ���ӣ��оͱ��Ϊ1��
		����
		ֱ��n*m��ɨ�������������ܵ��������λ�ö��ѳɹ����Ϊ1.
	*/
	for (int k = 0; k < n*m; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (recordmap[i][j] == 1)
				{
					if (i - 1 >= 0)
					{
						if (gamemap[i - 1][j] == '.')
							recordmap[i - 1][j] = 1;
					}
					if (i + 1 < n)
					{
						if (gamemap[i + 1][j] == '.')
							recordmap[i + 1][j] = 1;
					}
					if (j - 1 >= 0)
					{
						if (gamemap[i][j - 1] == '.')
							recordmap[i][j - 1] = 1;
					}

					if (j + 1 < m)
					{
						if (gamemap[i][j + 1] == '.')
							recordmap[i][j + 1] = 1;
					}
				}

			}
		}

	}
	//��¼1�ĸ���
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (recordmap[i][j] == 1)
			{
				max++;
			}

		}
	}

	//���1������
	cout << max;


	/*
	�ͷŶ�ά����
	*/
	for (int i = 0; i < n; i++)
	{
		delete[]gamemap[i];
		delete[]recordmap[i];
	}
	delete[]gamemap;
	delete[]recordmap;
	return 0;
}

