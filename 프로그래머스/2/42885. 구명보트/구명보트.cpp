#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int first = 0;
    int last = people.size() - 1;
    sort(people.begin(), people.end());

    while (first <= last)
    {
        if (people[first] + people[last] <= limit) {
            first++;
        }
        answer++;
        last--;
    }
    return answer;
}