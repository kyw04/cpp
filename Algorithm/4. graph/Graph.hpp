/*
그래프 알고리즘()
*/
#include <iostream>
#include <queue>
#include <map>

template <typename T>
struct Edge
{
    unsigned src;
    unsigned dst;
    T weight;
};

template <typename T>
class Graph
{
private:
    unsigned V; // 정점의 개수
    std::vector<Edge<T>> edge_list;

public:
    Graph(unsigned size) : V(size) {  }
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Graph<U> G);
    
    unsigned GetVertices() const { return V; }
    std::vector<Edge<T>>& GetEdges() const { return edge_list; }
    std::vector<Edge<T>> GetEdges(unsigned v) const
    {
        std::vector<Edge<T>> edge_from_v;
        for (auto& e : edge_list)
        {
            if (e.src == v)
            {
                edge_from_v.push_back(e);
            }
        }

        return edge_from_v;
    }

    void AddEdge(Edge<T>&& edge)
    {
        if (edge.src >= 1 && edge.src <= V && edge.dst >= 1 && edge.dst <= V)
        {
            edge_list.push_back(edge);
        }
        else
        {
            std::cerr << "error: 유효 범위를 벗어남!" << std::endl;
        }
    }
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const Graph<U> G)
{
    for (unsigned i = 1; i < G.GetVertices; i++)
    {
        os << i << ":\t";

        auto edges = G.GetEdges(i);
        for (auto& e : edges)
            os << "{" << e.dst << ": " << e.weight << "}, ";
        
        os << std::endl;
    }
}

template <typename T>
Graph<T> GetReferenceGraph()
{
    /*
    
    (1) ------  (5) --- (8)
      \       /  ㅣ    /  \
       \    /    ㅣ  /    \
        (2) ---- (4) --- (6) 
                /         /
              /         /
            (3) ---- (7)
    
    */

    Graph<T> G(9);

    std::map<unsigned, std::vector<unsigned, T>> edge_map;
    edge_map[1] = { { 2, 0 }, { 5, 0 } };
    edge_map[2] = { { 1, 0 }, { 5, 0 }, { 4, 0 } };
    edge_map[3] = { { 4, 0 }, { 7, 0 } };
    edge_map[4] = { { 2, 0 }, { 3, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 } };
    edge_map[5] = { { 1, 0 }, { 2, 0 }, { 4, 0 }, { 8, 0 } };
    edge_map[6] = { { 4, 0 }, { 7, 0 }, { 8, 0 } };
    edge_map[7] = { { 3, 0 }, { 6, 0 } };
    edge_map[8] = { { 4, 0 }, { 5, 0 }, { 6, 0 } };
    
    return G;
}