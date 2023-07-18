#include <iostream>
#include <vector>
#include <queue>
class Graph {
private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adjList;
public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}
    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }
    std::vector<int> dijkstra(int source) {
        std::vector<int> dist(V, INT_MAX);
        dist[source] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, source));
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(std::make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }
};

int main() {
    int V = 6;
    Graph graph(V);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 5, 6);
    int source = 0;
    std::vector<int> shortestPaths = graph.dijkstra(source);
    std::cout << "Shortest Paths from vertex " << source << ":" << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << "Vertex " << i << ": " << shortestPaths[i] << std::endl;
    }
    return 0;
}
