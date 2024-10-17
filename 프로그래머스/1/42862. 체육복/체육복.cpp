#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
   int answer = 0;
    std::vector<int> buffer(31, 0);

    for (int i = 0; i < buffer.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (reserve[j] == i + 1)
            {
                buffer[i]++;
            }
        }
    }
    for (int i = 0; i < buffer.size(); i++)
    {
        for (int j = 0; j < lost.size(); j++)
        {
            if (lost[j] == i + 1)
            {
                buffer[i]--;
            }
        }
    }
    for (int i = 0; i < buffer.size(); i++)
    {

        if (buffer[i] == 1)
        {
            if (i != 0)
            {
                if (buffer[i - 1] == -1)
                {
                    buffer[i]--;
                    buffer[i - 1]++;
                    continue;
                }
                else if (buffer[i + 1] == -1)
                {
                    buffer[i]--;
                    buffer[i + 1]++;
                    continue;
                }
            }
            else
            {
                if (buffer[i + 1] == -1)
                {
                    buffer[i]--;
                    buffer[i + 1]++;
                    continue;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (buffer[i] >= 0)
        {
            answer++;
        }
    }
    return answer;
}