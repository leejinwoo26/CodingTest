#include <string>
#include <vector>

using namespace std;


int solution(int n) {
     if (n <= 1) return n;

 int a = 0, b = 1, c = 0;
 for (int i = 2;i <= n;i++) {
     c = (a + b) % 1234567;
     a = b;
     b = c;
 }
 return c;
}