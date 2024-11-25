#include <string>
#include <vector>

using namespace std;

int dp[100002];

int solution(int n) {
    int answer = 0;
    dp[1] = 1;

    //다이나믹 프로그래밍
    for (int i = 2;i <= n;i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1234567;
    }
    return dp[n];
}