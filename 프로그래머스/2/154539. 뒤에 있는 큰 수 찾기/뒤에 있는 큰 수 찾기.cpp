#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
std::stack<int> s;

for (int i = 0; i < numbers.size(); i++)
{
	while (!s.empty() && numbers[s.top()] < numbers[i]) {
		answer[s.top()] = numbers[i];
		s.pop(); // 처리한 인덱스를 스택에서 제거
	}
	s.push(i); // 현재 인덱스를 스택에 추가
}

return answer;
}