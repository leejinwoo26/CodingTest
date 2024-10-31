#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> nums;

    size_t _point;
    for (int i = 0; i < s.size();)
    {
        stoi(s, &_point);
        nums.push_back(stoi(s));
        s.erase(i, _point);
    }

    int max = -210000000; 
    int min = 210000000;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);

    return answer;
}