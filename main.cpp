#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> setA, setB;
        vector<bool> visited(n, false);
        queue<int> q;

        for (int start = 0; start < n; start++) {
            if (!visited[start]) {
                q.push(start);
                setA.push_back(start); // Inicialmente, colocamos el nodo de inicio en el conjunto A

                while (!q.empty()) {
                    int current = q.front(); q.pop();

                    // Determinar en qué conjunto está el nodo actual
                    bool inSetA = find(setA.begin(), setA.end(), current) != setA.end();

                    for (int adj : graph[current]) {
                        if (!visited[adj]) {
                            visited[adj] = true;
                            q.push(adj);
                            // Agregar el nodo adjacente al conjunto opuesto
                            if (inSetA) {
                                setB.push_back(adj);
                            } else {
                                setA.push_back(adj);
                            }
                        } else {
                            // Verificar si el nodo adyacente está en el mismo conjunto
                            if ((inSetA && find(setA.begin(), setA.end(), adj) != setA.end()) ||
                                (!inSetA && find(setB.begin(), setB.end(), adj) != setB.end())) {
                                return false; // No es bipartito
                            }
                        }
                    }
                }
            }
        }
        return true; // Es bipartito
    }
};

int main() {
    Solution solution;
    vector<vector<int>> graph1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    vector<vector<int>> graph2 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

    cout << "Graph 
