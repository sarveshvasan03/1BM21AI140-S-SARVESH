#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <unordered_map>

void dfs(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& node, std::unordered_set<std::string>& visited) {
    visited.insert(node);
    std::cout << node << " ";

    for (const std::string& neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
}

void dfsTraversal(std::unordered_map<std::string, std::vector<std::string>>& graph) {
    std::unordered_set<std::string> visited;

    for (const auto& entry : graph) {
        const std::string& node = entry.first;
        if (visited.find(node) == visited.end()) {
            dfs(graph, node, visited);
        }
    }
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"C", "D"}},
        {"C", {"D", "E"}},
        {"D", {"E"}},
        {"E", {"A"}}
    };

    std::cout << "DFS traversal: ";
    dfsTraversal(graph);
    std::cout << std::endl;

    return 0;
}
