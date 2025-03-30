/*
코사라주 알고리즘(Kosaraju's Algorithm)
    그래프에 강한 연결 요소를 찾는 알고리즘입니다.
*/
#include "../Graph.hpp"
#include <iostream>
#include <set>
#include <stack>

template <typename T>
void FillStack(const unsigned node, const Graph<T> g, std::set<unsigned>& visited, std::stack<unsigned>& s)
{
    visited.insert(node);

    for (auto& e : g.GetEdges(node))
    {
        if (visited.find(e.dst) ==  visited.end())
        {
            FillStack(e.dst, g, visited, s);
        }
    }

    s.push(node);
}

template <typename T>
void CollectConnectedComponents(const unsigned node, const Graph<T> g, std::set<unsigned>& visited, std::vector<unsigned>& component)
{
    visited.insert(node);
    component.push_back(node);

    for (auto& e : g.GetEdges(node))
    {
        if (visited.find(e.dst) == visited.end())
        {
            CollectConnectedComponents(e.dst, g, visited, component);
        }
    }
}

template <typename T>
Graph<T> Transpose(Graph<T> g)
{
    Graph<T> transpose(g.GetVertices());

    for (auto& e : g.GetEdges())
    {
        transpose.AddEdge(Edge<T>{ e.dst, e.src, e.weight });
    }

    return transpose;
}

template <typename T>
std::vector<std::vector<unsigned>> Kosaraju(Graph<T> g)
{
    std::set<unsigned> visited;
    std::stack<unsigned> s;

    for (auto& e : g.GetEdges())
    {
        if (visited.find(e.src) == visited.end())
        {
            FillStack(e.src, g, visited, s);
        }
    }

    Graph<T> transpose_g = Transpose(g);
    visited.clear();
    std::vector<std::vector<unsigned>> connected_components;

    while (!s.empty())
    {
        unsigned node = s.top();
        s.pop();

        if (visited.find(node) == visited.end())
        {
            std::vector<unsigned> component;

            CollectConnectedComponents(node, transpose_g, visited, component);
            connected_components.push_back(component);
        }
    }

    return connected_components;
}

int main()
{
    Graph<int> G(9);

    std::vector<Edge<int>> edge_map
    {
        { 0, 1, 0 },
        { 0, 3, 0 },
        { 1, 2, 0 },
        { 1, 4, 0 },
        { 2, 3, 0 },
        { 2, 5, 0 },
        { 3, 7, 0 },
        { 4, 2, 0 },
        { 5, 4, 0 },
        { 5, 6, 0 },
        { 6, 2, 0 },
        { 6, 7, 0 },
        { 7, 8, 0 },
        { 8, 3, 0 }
    };

    for (auto& e : edge_map)
    {
        G.AddEdge(Edge<int>{ e.src + 1, e.dst + 1, e.weight });
    }

    std::vector<std::vector<unsigned>> connected_components;
    connected_components = Kosaraju(G);

    std::cout << "강한 연결 요소 개수: " << connected_components.size() << std::endl;
    for (std::size_t i = 0; i < connected_components.size(); i++)
    {
        std::cout << "[" << i + 1 << "] ";
        for (auto& node : connected_components[i])
            std::cout << " " << node;
        std::cout << std::endl;
    }

    return 0;
}
