#include "pch.h"
#include <sstream> 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h> 
#include <regex>
#include <Windows.h>
#include<Shlwapi.h>
#pragma comment(lib,"Shlwapi.lib") 


using namespace std;

class Book;
struct Numx;


/*�鱾��*/
class Book
{
public:
	string name;//����
	string contact;//�������
	long int pages[4000];//���ҳ��
	long int chapter[500];//����½�����
	void Named(string names);//Ϊ�Ȿ������
	void readTxt(string file);//��ȡ�������
	
};
struct Numx//�����
{
	int book;//��Ӧ�ľ�����Ŀ
	int local;//��Ӧ�ľ���λ��
};
/*Ϊ�Ȿ������*/
void Book::Named(string names)
{
	name = names;
}
/*��ȡ�Ȿ������ݣ��½ڣ�ҳ��*/
void Book::readTxt(string file)
{
	int i = 0;
	bool flag1=false;
	//���鱾���ݴ浽contact��
	fstream infile;
	infile.open(file.data(), ios::in);
	char c[2];	
	while (!infile.eof())
	{
		c[1] = '\0';
		infile.read(c, 1);
		if (c[0] == '\n')//�����������ǻس�ʱ��flag=�棬���ڶ�ȡ��һ���ַ�ʱ���߳�����һ���ַ�ʱ�س�
		{
			flag1 = true;
		}
		if (flag1 == true)
		{
			if (c[0] >= '0' && c[0] <= '9')//�����һ���ַ��ǻس���������ַ���0-9֮�䣬��ôһ����ҳ��
			{
				c[0] = '@';
				flag1 = false;
			}
			else if(c[0] !='\n')
			{
				flag1 = false;
			}
		}
		contact += c[0];
	}
	
	infile.close();

	//�������½ڶ�Ӧ�ľ���λ�ô浽chapter

	size_t fi = contact.find("Chapter", 0);
	if (fi == contact.npos)
	{
		fi = contact.find("CHAPTER", 0);
		while (fi != contact.npos)
		{
			chapter[i++] = fi;
			fi = contact.find("CHAPTER", fi + 1);
		}
	}
	else
	{
		while (fi != contact.npos)
		{
			chapter[i++] = fi;
			fi = contact.find("Chapter", fi + 1);
		}
	}
	
	//������ҳ���Ӧ�ľ���λ�ô浽pages
	size_t fi1 = contact.find("@", 0);
	i = 0;
	while (fi1 != contact.npos)
	{
		pages[i++] = fi1;
		fi1 = contact.find("@", fi1 + 1);
	}

}

string TCHAR2STRING(TCHAR *STR)
{
	int iLen = WideCharToMultiByte(CP_ACP, 0,STR, -1, NULL, 0, NULL, NULL);
	char* chRtn = new char[iLen * sizeof(char)];
	WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);
	std::string str(chRtn);
	delete chRtn;
	return str;
}
Numx numx[16000];//����һ����������������ָ����map�Ķ�ά���飬��map�Ķ�ά������һ����Ŵ���]
long int map[8][2000];//ÿһ������Ҫ�����ĵ��ʾ����λ��
int cha[8][2000];//ÿһ����Ҫ�����ĵ������ھ�����½�
int pag[8][2000];//ÿһ����Ҫ�����ĵ������ھ����ҳ��
const void Search(const Book *book)
{
	int i = 0, j = 0, k = 0, m = 0;//jΪ�½ڵ�����������mΪҳ���������������֤�½���ҳ��һֱ��ǰ����ȡ��һ�����ʱ�����
	
	int outnum;
	
	string finding, midf;//finding���������ݣ�midf���������ݣ�finding=�ո�+midf
	int begintime, endtime;//���ڴ�����������ʱ��

	/*������������*/
	system("cls");
	cout << "�ɹ����ع�������ϵ�д���" << endl << endl;
	cout << "������Ҫ�����ĵ��ʣ�" << endl;
	cin >> midf;
	finding += midf;
	begintime = clock();//ȡ������ʼʱ��

	/*���б��ʽ������*/
	cout << setiosflags(ios::left) << setw(10) << "��ţ�"
		<< setw(15) << "����/������"
		<< setw(10) << "ҳ�룺"
		<< setw(10) << "�½ڣ�"
		<< "������" << endl;

	/*��������finding*/
	k = 0;
	for (int l = 0; l < 8; l++)//8���鰤������
	{
		i = 0; j = 0; m = 0;

		size_t fi = book[l].contact.find(finding, 0);//�������ľ���λ�ã�size_t������
		while (fi != book[l].contact.npos)
		{

			map[l][i] = fi;//��map�����������ľ���λ��
			while (1)//Ѱ�Ҹ�λ�ö�Ӧ���½�
			{
				if (fi > book[l].chapter[j] && fi < book[l].chapter[j + 1])
					break;
				j++;
			}

			cha[l][i] = j;//�����λ�ö�Ӧ���½�
			while (1)//Ѱ�Ҹ�λ�ö�Ӧ���½�
			{
				if (fi > book[l].pages[m] && fi < book[l].pages[m + 1])
					break;
				m++;
			}

			pag[l][i] = m;//�����λ�ö�Ӧ���½�
			numx[k].book = l;//ÿ����������Ӧ�ľ���map���
			numx[k].local = i;//ÿ����������Ӧ�ľ���map���

			/*���б�ĸ�ʽ������*/
			if (k < 10)
			{
				cout << setiosflags(ios::left) << setw(10) << k
					<< setw(15) << midf
					<< setw(10) << pag[l][i]
					<< setw(10) << cha[l][i]
					<< book[l].name << endl;
			}

			i++; k++;//����
			fi = book[l].contact.find(finding, fi + 1);
		}



	}
	endtime = clock();//ȡ��������ʱ��

	

	if (k == 0)
	{
		cout << "�޽��(����-2�����µĵ���)" << endl;
		cin >> outnum;
		if (outnum == -2)
		{
			Search(book);
		}
	}
	else
	{
		cout << "Running Time��" << endtime - begintime << "ms" << endl;
		cout << "ֻ��ʾǰ10��" << endl;
		cout << "�ܹ���:" << k - 1 << "��" << endl;
		/*����������*/
		do
		{
			cout << endl << "������Ҫ�鿴����ţ�������ʾ�������ڵľ��ӡ�(��-1�˳�,-2�����µĵ���)" << endl;
			cin >> outnum;
			if (outnum > k - 1)
			{
				cout << "�������Ų�����" << endl;
				continue;
			}
			if (outnum == -1)
				break;
			if (outnum == -2)
			{
				Search(book);
			}
			else
			{
				/*��ʾfinding������100������,���磺book[1].contact[map[1][0]]*/
				int firstlocal, endlocal;
				firstlocal = book[numx[outnum].book].contact.find_last_of('.', map[numx[outnum].book][numx[outnum].local]);
				endlocal = book[numx[outnum].book].contact.find_first_of('.', map[numx[outnum].book][numx[outnum].local]);

				for (i = firstlocal + 1; i < endlocal + 1; i++)
					cout << book[numx[outnum].book].contact[i];
				cout << endl << endl;
			}
		} while (true);
	}
}

int main()
{
	int i = 0,j=0,k=0,m=0;//jΪ�½ڵ�����������mΪҳ���������������֤�½���ҳ��һֱ��ǰ����ȡ��һ�����ʱ�����
	long int map[8][2000];//ÿһ������Ҫ�����ĵ��ʾ����λ��
	int cha[8][2000];//ÿһ����Ҫ�����ĵ������ھ�����½�
	int pag[8][2000];//ÿһ����Ҫ�����ĵ������ھ����ҳ��
	int begintime, endtime;//���ڴ�����������ʱ��
	Book book[8];//����7����
	Numx numx[10000];//����һ����������������ָ����map�Ķ�ά���飬��map�Ķ�ά������һ����Ŵ���
	string finding,midf;//finding���������ݣ�midf���������ݣ�finding=�ո�+midf
	
	cout << "������Ŀ��..." << endl;
	
	/*ȡ����Ŀ¼*/
	const int nBufSize = 512;
	TCHAR chBuf[nBufSize];
	ZeroMemory(chBuf, nBufSize);
	GetModuleFileName(NULL, chBuf, nBufSize);
	TCHAR* lpStrPath = chBuf;
	PathRemoveFileSpec(lpStrPath);
	string mid;
	mid = TCHAR2STRING(lpStrPath);


	/*����8���飬�˱����������Ŀ¼��*/
	book[0].Named("J.K. Rowling - HP 0 - Harry Potter Prequel");
	cout << mid + "\\1537835839070042080.txt" << endl;
	book[0].readTxt(mid+"\\1537835839070042080.txt");
	book[1].Named("HP7--Harry_Potter_and_the_Deathly_Hallows_Book_7_");
	cout << mid + "\\1537835838814021493.txt" << endl;
	book[1].readTxt(mid + "\\1537835838814021493.txt");
	book[2].Named("J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban");
	cout << mid + "\\1537835840376093816.txt" << endl;
	book[2].readTxt(mid + "\\1537835840376093816.txt");
	book[3].Named("HP2--Harry_Potter_and_the_Chamber_of_Secrets_Book_2_");
	cout << mid + "\\1537835838730035402.txt" << endl;
	book[3].readTxt(mid + "\\1537835838730035402.txt");
	book[4].Named("J.K. Rowling - Quidditch Through the Ages");
	cout << mid + "\\1537835855727087219.txt" << endl;
	book[4].readTxt(mid + "\\1537835855727087219.txt");
	book[5].Named("J.K. Rowling - The Tales of Beedle the Bard");
	cout << mid + "\\1537835857250083215.txt" << endl;
	book[5].readTxt(mid + "\\1537835857250083215.txt");
	book[6].Named("J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince");
	cout << mid + "\\1537835858108007396.txt" << endl;
	book[6].readTxt(mid + "\\1537835858108007396.txt");
	book[7].Named("J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire");
	cout << mid + "\\1537835854839084779.txt" << endl;
	book[7].readTxt(mid + "\\1537835854839084779.txt");
	
	Search(book);
	return 0;
}