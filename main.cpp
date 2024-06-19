#include <iostream>

class Solution {
public:
    bool isBipartite(int graph[][100], int n) {
        int colors[100];
        for (int i = 0; i < n; i++) {
            colors[i] = 0;
        }

        int queue[100];
        for (int start = 0; start < n; start++) {
            if (colors[start] == 0) {
                colors[start] = 1;
                int front = 0, rear = 0;
                queue[rear++] = start;

                while (front != rear) {
                    int u = queue[front++];
                    for (int i = 0; graph[u][i] != -1; i++) {
                        int v = graph[u][i];
                        if (colors[v] == 0) {
                            colors[v] = -colors[u];
                            queue[rear++] = v;
                        } else if (colors[v] == colors[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    int graph1[4][100] = {{1,2,3,-1},{0,2,-1},{0,1,3,-1},{0,2,-1}};
    int graph2[4][100] = {{1,3,-1},{0,2,-1},{1,3,-1},{0,2,-1}};

    std::cout << "Graph 1 is bipartite: " << solution.isBipartite(graph1, 4) << std::endl;
    std::cout << "Graph 2 is bipartite: " << solution.isBipartite(graph2, 4) << std::endl;
    
    return 0;
}
