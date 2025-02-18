#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int lastScore = 0;
    string buffer;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'Z') {
            answer -= lastScore;
            i++;
            continue;
        }
        if (s[i] == ' ') {
            lastScore = stoi(buffer);	
            answer += lastScore;
            buffer.clear();
            continue;
        }
        buffer += s[i];

        if (i == s.size() - 1) {
            lastScore = stoi(buffer);
            answer += lastScore;
        }
    }
    return answer;
}