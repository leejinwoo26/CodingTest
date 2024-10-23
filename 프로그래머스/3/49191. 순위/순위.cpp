#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
  int answer = 0;
//인접 그래프 만들기
vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

//그래프에 이긴정보 등록
for (auto x : results)
{
    graph[x[0]][x[1]] = true;
}

//거치는 지점
for (int k = 1; k <= n; k++)
{
    //시작 지점
    for (int i = 1; i <= n; i++)
    {
        //도착 지점
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][k] && graph[k][j])
            {
                graph[i][j] = true;
            }
        }
    }
}

for (int i = 1; i <= n; i++)
{
    int cnt = 0;
    for (int j = 1; j <= n; j++)
    {
        if (graph[i][j] || graph[j][i])
            cnt++;
    }
    if (cnt == n - 1)
        answer++;
}


return answer;
}