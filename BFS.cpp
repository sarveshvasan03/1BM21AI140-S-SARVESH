#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
#include <unordered_map>

void bfs(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start_node) {
    std::unordered_set<std::string> visited;
    std::queue<std::string> queue;

    queue.push(start_node);

    while (!queue.empty()) {
        std::string current_node = queue.front();
        queue.pop();

        if (visited.find(current_node) == visited.end()) {
            visited.insert(current_node);
            std::cout << current_node << " ";

            for (const std::string& neighbor : graph[current_node]) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor);
                }
            }
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

    std::string start_node = "A";

    std::cout << "BFS traversal starting from " << start_node << ": ";
    bfs(graph, start_node);
    std::cout << std::endl;

    return 0;
}
