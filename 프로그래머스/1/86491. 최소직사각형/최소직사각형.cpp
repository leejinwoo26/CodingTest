#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
   int answer = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        sort(sizes[i].begin(), sizes[i].end());
    }

    int max1 = -20000;
    int max2 = -20000;

    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] > max1)
        {
            max1 = sizes[i][0];
        }
        if (sizes[i][1] > max2)
        {
            max2 = sizes[i][1];
        }
    }
    return max1 * max2; 
}