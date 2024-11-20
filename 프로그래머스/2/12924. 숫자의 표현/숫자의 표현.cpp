#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        int result = 0;
        int num = i;
        while (true)
        {
            if (result > n) break;
            else if (result == n) {
                //cout << "처음 숫자는 : " << i << endl;
                answer++;
                break;
            }
            result += num;
            num++;
        }
    }
return answer;  
}