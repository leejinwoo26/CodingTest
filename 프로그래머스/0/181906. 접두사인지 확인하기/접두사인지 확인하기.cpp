#include <string>
#include <vector>

using namespace std;

bool check(char a, char b)
{
    if (a == b)
        return true;
    else
        return false;
}

int solution(string my_string, string is_prefix) {
    int answer = 0;
    bool isPrefix = true;
    if (is_prefix.size() > my_string.size())
        return 0;

    for (int i = 0; i < is_prefix.size(); i++)
    {
        if (!check(is_prefix[i], my_string[i]))
        {
            isPrefix = false;
        }
    }
    


    return isPrefix ? 1 : 0;
}