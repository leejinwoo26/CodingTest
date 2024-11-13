#include <string>
#include <vector>

using namespace std;

string solution(string s) {
   bool first = true;

for (int i = 0; i < s.size(); i++)
{
    if (s[i] == ' ') {
        // 공백일 경우 다음 문자를 단어의 첫 글자로 인식
        first = true;
    }
    else if (first) {
        // 단어의 첫 글자는 대문자로
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
        first = false;
    }
    else {
        // 첫 글자가 아니면 소문자로
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
}
return s;
}