#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Check(int first)
{
	string a;
	while (first>0)
	{
		if (first % 2 == 0) {
			a += "0";
			first /= 2;
		}
		else
		{
			a += "1";
			first /= 2;
		}
	}
	reverse(a.begin(), a.end());

	int cnt = 0;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '1')
		{
			cnt++;
		}
	}
	return cnt;
}

int solution(int n) {
    int oriSize = Check(n);
    while (true)
    {
        n++;
        int nextSize = Check(n);
        if (oriSize == nextSize)
            break;
    }
    return n;
}