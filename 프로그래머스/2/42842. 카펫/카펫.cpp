#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1; i <= yellow; i++)
    {
        int x1 = 0, y1 = 0;
        int x2 = 0, y2 = 0;
        //나눠질때
        if (yellow % i == 0) {
            x1 = (yellow / i) + 2; 
            y1 = i + 2; 
            x2 = yellow / i;
            y2 = i;
        }
        else {
            continue;
        }
        int brown_cnt = (x1 * y1) - (x2 * y2);

        if (brown_cnt == brown && x1 >= y1) {
            answer.push_back(x1);
            answer.push_back(y1);
        }
    }
    return answer;
}