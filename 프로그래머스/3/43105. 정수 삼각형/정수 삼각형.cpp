#include <string>
#include <vector>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][0] + triangle[i][0];
            }
            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j-1] + triangle[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j-1],dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    int last_row = triangle.size() - 1;
    for (int i = 0; i <= last_row; i++)
    {
        answer = max(answer, dp[last_row][i]);
    }
    return answer;
}