#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    std::unordered_multimap<string, string> u_map;

    for (int i = 0; i < participant.size(); i++)
    {
        u_map.insert({ participant[i],participant[i] });
    }

    for (int i = 0; i < completion.size(); i++)
    {
        auto iter = u_map.find(completion[i]);

        if (iter != u_map.end())
        {
            u_map.erase(iter);
        }
    }

    auto iter = u_map.begin();

    answer = iter->second;

    return answer;
}