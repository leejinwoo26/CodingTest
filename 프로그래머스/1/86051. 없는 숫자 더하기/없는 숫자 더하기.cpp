#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
vector<int> nums = { 0,1,2,3,4,5,6,7,8,9 };

for (int i = 0; i < numbers.size(); i++)
{
	for (int j = 0; j < nums.size();)
	{
		if (numbers[i] == nums[j])
		{
			nums.erase(nums.begin()+j);
			continue;
		}
		j++;
	}
}
for (int i = 0; i < nums.size(); i++)
{
	answer += nums[i];
}

return answer;
}