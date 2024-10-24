#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;

queue<pair<int,int>> _queue;
vector<vector<int>> visited(100,vector<int>(100,false));
vector<vector<int>> table(100, vector<int>(100, 0));

_queue.push({ 0,0 });
visited[0][0] = true;
table[0][0] = 1;

int n = maps.size();
int m = maps[0].size();

pair<int, int> currentPos;

while (!_queue.empty())
{
    currentPos = _queue.front();
    _queue.pop();
    

    int dx = currentPos.first;
    int dy = currentPos.second;
    

    if ((dx + 1 < n ) && (maps[dx + 1][dy] == 1) && (visited[dx + 1][dy] == false)) {
        _queue.push({ dx + 1,dy });
        visited[dx + 1][dy] = true;
        table[dx + 1][dy] = table[currentPos.first][currentPos.second] + 1;
    }

    if ((dy + 1 < m) && (maps[dx][dy + 1] == 1) && (visited[dx][dy + 1] == false)) {
        _queue.push({ dx,dy + 1 });
        visited[dx][dy+1] = true;
        table[dx][dy+1] = table[currentPos.first][currentPos.second] + 1;
    }

    if ((dx-1>=0) && (maps[dx - 1][dy] == 1) && (visited[dx - 1][dy] == false)) {
        _queue.push({ dx-1,dy});
        visited[dx - 1][dy] = true;
        table[dx - 1][dy] = table[currentPos.first][currentPos.second] + 1;
    }

    if ((dy - 1 >= 0) && (maps[dx][dy - 1] == 1) && (visited[dx][dy - 1] == false)) {
        _queue.push({ dx,dy-1 });
        visited[dx][dy-1] = true;
        table[dx][dy-1] = table[currentPos.first][currentPos.second] + 1;
    }
}



return table[n-1][m-1]> 0 ? table[n - 1][m - 1] : -1;
}