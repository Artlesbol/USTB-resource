// cs.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include <iostream>
using namespace std;

char primeornot(int a)
{
int i;
double b,c;
if (a==0)
	return 'N';
else if (a==1)
	return 'N';
else
{for(i=2;i<a;i++)
{
	b=(double)a/(double)i;
	c=b-(int)b;
	if(c==0)
		return 'N';
	
}
}
return 'Y';
}

int main()
{
int a;
cin>>a;
cout<<primeornot(a)<<endl;
return 0; 
} 

