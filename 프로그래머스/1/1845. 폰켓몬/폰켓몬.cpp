#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
std::unordered_map<int, int> map = {};

for (int i = 0;i < nums.size();i++)
{
    map.insert({ nums[i],nums[i] });
}
int size = nums.size()/2;
int map_size = map.size();

if (size < map_size)
{
    map_size = size;
}

return map_size;
}