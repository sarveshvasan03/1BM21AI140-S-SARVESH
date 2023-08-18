#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

void dfsTopologicalSort(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& node, std::unordered_set<std::string>& visited, std::stack<std::string>& result) {
    visited.insert(node);

    for (const std::string& neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfsTopologicalSort(graph, neighbor, visited, result);
        }
    }

    result.push(node);
}

std::vector<std::string> topologicalSort(std::unordered_map<std::string, std::vector<std::string>>& graph) {
    std::unordered_set<std::string> visited;
    std::stack<std::string> result;

    for (const auto& entry : graph) {
        const std::string& node = entry.first;
        if (visited.find(node) == visited.end()) {
            dfsTopologicalSort(graph, node, visited, result);
        }
    }

    std::vector<std::string> orderedVertices;
    while (!result.empty()) {
        orderedVertices.push_back(result.top());
        result.pop();
    }

    return orderedVertices;
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"C", "D"}},
        {"C", {"D"}},
        {"D", {}}
    };

    std::vector<std::string> orderedVertices = topologicalSort(graph);

    std::cout << "Topological Ordering: ";
    for (const std::string& vertex : orderedVertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}
