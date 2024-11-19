#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getBinary(int a)
{
	string buffer;
	string reversed;
	while (a > 0)
	{
		int s = a % 2;
		buffer += to_string(s);
		a /= 2;
	}

	for (int i = buffer.size()-1; i >= 0; i--)
	{
		reversed += buffer[i];
	}

	return reversed;
}




vector<int> solution(string s) 
{
	vector<int> answer;
	string buffer = s;
	int cnt = 0;
	int zero_cnt = 0;



	while (true)
	{
		//버퍼 사이즈가 1이고 버퍼의 첫번째가 1이면 중지
		if (buffer.size() == 1 && buffer[0] == '1')
		{
			answer.push_back(cnt);
			answer.push_back(zero_cnt);
			return answer;
		}

		//0 제거
		for (int i = 0; i < buffer.size();)
		{
			if (buffer[i] == '0') {
				buffer.erase(buffer.begin() + i);
				zero_cnt++;
				continue;
			}
			i++;
		}
		//사이즈 측정
		int size = buffer.size();

		//이진 문자열 가져옴
		string last = getBinary(size);
		//버퍼 클리어 후
		buffer.clear();
		//버퍼 덮어씌움
		buffer = last;
		cnt++;
	}
}