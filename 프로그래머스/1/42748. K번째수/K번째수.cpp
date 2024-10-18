#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

for (int i = 0; i < commands.size(); i++)
{
	int first, second, K;
	for (int j = 0; j < commands[i].size(); j++)
	{
		if (j == 0)
		{
			first = commands[i][j] - 1;
		}
		else if (j == 1)
		{
			second = commands[i][j];
		}
		else if (j == 2)
		{
			K = commands[i][j]-1;
		}
	}
	vector<int> buffer(array.begin() + first, array.begin() + second);
	sort(buffer.begin(),buffer.end());
	answer.push_back(buffer[K]);
}
return answer;
}