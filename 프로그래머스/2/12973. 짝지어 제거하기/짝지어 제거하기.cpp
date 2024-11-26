#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
      stack<char> s_buffer;
s_buffer.push(s[0]);

for (int i = 1; i < s.size(); i++)
{
	if (s_buffer.empty())
	{
		s_buffer.push(s[i]);
	}
	else {
		// 서로 다르다 , 삭제 x
		if (s_buffer.top() != s[i]) {
			s_buffer.push(s[i]);
		}
		// 서로 같다 , 삭제 O , 푸쉬 x
		else {
			s_buffer.pop();
		}
	}
}
if (s_buffer.empty()) 
	return 1;
else
	return 0;
}