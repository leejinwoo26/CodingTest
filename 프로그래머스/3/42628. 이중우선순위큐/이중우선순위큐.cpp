#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    set<int, greater<int>> _set;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "D 1") {
            if (!_set.empty()) {
                auto iter = _set.begin();
                _set.erase(iter);
            }
        }
        else if (operations[i] == "D -1") {
            if (!_set.empty()) {
                auto iter = _set.end();
                _set.erase(--iter);
            }
        }
        else
        {
            string s_value = operations[i].substr(2);
            int value = stoi(s_value);
            _set.insert(value);
        }
    }

    if (_set.empty()) {
        return vector<int>{ 0,0 };
    }
    else {
        auto top_iter = _set.begin();
        auto bottom_iter = --_set.end();
        return vector<int>{*top_iter, * bottom_iter};
    }
}