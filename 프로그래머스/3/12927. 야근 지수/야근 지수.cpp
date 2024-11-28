#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> queue;
    for (int i = 0; i < works.size(); i++)
    {
        queue.push(works[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int top = queue.top() - 1;
        if(top<0)
            top = 0;
        queue.pop();
        queue.push(top);
    }

    while (!queue.empty())
    {
        int top = queue.top();
        queue.pop();
        answer += (top * top);
    }
    return answer;
}