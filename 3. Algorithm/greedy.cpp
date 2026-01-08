/*
그리디 알고리즘(Greedy Algorithm)
    탐욕법, 욕심쟁이 알고리즘으로도 불립니다.
    매 선택에서 지금 이 순간 당장 최적인 답을 선택하여 적합한 결과를 도출하는 알고리즘입니다.
    항상 그런 것은 아니지만, 프로그래밍 문제를 풀 때 제약조건이 많다면 의외로 그리디로 풀리는 경우가 많습니다.
*/
#include <iostream>
#include <queue>
#include <limits>

#define MAX_SIZE 5

int Dijkstra(std::vector<std::pair<int, int>> _graph[], int _start, int _end) // 예시용 다익스트라 알고리즘
{
    int min[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        min[i] = std::numeric_limits<int>::max();
    }
    min[_start] = 0;
    
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ _start, 0 });
    while (!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if (min[current] < distance) { continue; }
        for (int i = 0; i < _graph[current].size(); i++)
        {
            int next = _graph[current][i].first;
            int next_distance = distance + _graph[current][i].second;

            if (next_distance < min[next])
            {
                min[next] = next_distance;
                pq.push({ next, -next_distance });
            }
        }
    }

    return min[_end];
}

int main()
{
    std::vector<std::pair<int, int>> graph[MAX_SIZE];

    graph[0].push_back({ 1, 1 });
    graph[0].push_back({ 2, 4 });
    graph[1].push_back({ 2, 2 });
    graph[1].push_back({ 3, 5 });
    graph[2].push_back({ 3, 1 });

    std::cout << "0번 노드에서 3번 노드까지의 최소 비용: " << Dijkstra(graph, 0, 3) << std::endl;

    return 0;
}