//#include "pch.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution 
{
public:      
	int longestValidParentheses(string s)

	{
	
		stack<int> ss;          
		int max = 0;                        
		for( int i= 0; i< s.size() ; i++)
		{	              
			if( s[i] == ')' && !ss.empty() && s[ss.top()] == '(')
				//�����ǰԪ��Ϊ��������ջ�ڲ��ǿյģ�ͬʱջ��Ԫ����(����ô
			{                  
				ss.pop();//��()��ջ                 
				if( ss.empty())    //�����ջ��ջ���ˣ���ô����i��0��ʼ�����Գ���+1               
					max = i+1;                  
				else               //�����ջ��ջ��û��          
					if( i - ss.top() > max)      //�����ǰԪ��λ�ü�ȥջ��Ԫ��λ�ñ����ֵ��                   
						max = i - ss.top();      //��ô���ֵ�����������      
			}             
			else//�����ǰԪ��Ϊ������ջ�ǿյģ��������Ԫ����ջ
				ss.push(i);         
		}          
	return max;   
	}  
};  
int main()
{
	string str;
	stack<int> ack;
	Solution a;
	cin >> str;
	cout << a.longestValidParentheses(str);
	return 0;
}
