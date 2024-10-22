#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> graph(n+1); 
    
    //counter를 위한 배열, 노드 번호(index), 깊이(value)
    vector<int> counts(n+1, 0); //0으로 초기화
    
    //visited 배열
    vector<bool> visited(n+1, false);
    
    //BFS를 위한 큐
    queue<int> queue;
    
    
    // 인접 양방향 리스트 기반 그래프 생성
    for (int i = 0; i < edge.size(); i++ ) {
        //양방향그래프라, 시작점과 끝점을 번갈아가며 연결.
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue.push(1); // 시작점
    visited[1] = true;
    
    //BFS
    while(!(queue).empty()) {
        int node = queue.front();
        queue.pop();
        
        // 큐에서 꺼낸 노드에 연결된 모든 노드들을 for문 돌기
        for (int i = 0; i < graph[node].size(); i++) {
            
            int nodeLinkedToNode = graph[node][i];
            //방문 검사
            if (!visited[nodeLinkedToNode]) {
                // 최대거리를 알아야하기에 거리 증가, 너비 우선 탐색이기에 높이가 보장
                int currentCount = counts[node] + 1; //상위노드 깊이 + 1
                
                //방문 확인;
                visited[nodeLinkedToNode] = true;
                
                //방문 후 카운트(깊이) 기록;
                counts[nodeLinkedToNode] = currentCount;
                
                //현재 노드에서 연결된 노드에 연결된 점들을 확인 할 수 있게 큐에 push
                queue.push(nodeLinkedToNode);
            }
        }
    }
    
    //깊이가 깊은 순으로 정렬;
    sort(counts.begin(), counts.end(), greater<int>());
    for (auto cnt : counts) {
        //가장 깊은 count[0]의 깊이보다 얕다면 탈출;
        if (counts[0] != cnt) break;
        
        //답 개수 기록
        answer++;
    }


return answer;  
}