#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  bool newWord = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') {
            newWord = true;
        }
        else if (newWord) {
            // 단어의 첫 글자를 대문자로 변환
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= 32;
            }
            newWord = false;
        }
        else {
            // 단어의 첫 글자가 아닐 때는 소문자로 변환
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
    }

    return s;
}