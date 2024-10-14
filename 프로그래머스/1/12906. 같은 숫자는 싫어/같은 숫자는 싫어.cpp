#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
     vector<int> answer;
 std::stack<int> mStack;
 std::queue<int> mQueue;

 for (int i = 0;i < arr.size();i++)
 {
     if (mStack.size() == 0)
     {
         mStack.push(arr[i]);
         mQueue.push(arr[i]);
     }
     if (mStack.top() == arr[i])
         continue;
     else
     {
         mStack.push(arr[i]);
         mQueue.push(arr[i]);
     }
 }
  
 while (mQueue.size()>0)
 {
     int value = mQueue.front();
     answer.push_back(value);
     mQueue.pop();
 }

 return answer;
}