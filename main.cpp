#include <iostream>

class Solution {
public:
    // Método para verificar si el grafo es bipartito
    bool isBipartite(int graph[][100], int n) {
        int colors[100]; // Almacena el color asignado a cada nodo
        for (int i = 0; i < n; i++) {
            colors[i] = 0; // Inicializa todos los nodos sin color
        }

        // Implementación de BFS para verificar la bipartiticidad
        for (int start = 0; start < n; start++) {
            if (colors[start] == 0) { // Si el nodo no ha sido coloreado
                colors[start] = 1; // Asigna el primer color
                int queue[100], front = 0, rear = 0;
                queue[rear++] = start; // Encola el nodo inicial

                while (front != rear) { // Mientras la cola no esté vacía
                    int u = queue[front++]; // Desencola un nodo

                    for (int i = 0; graph[u][i] != -1; i++) {
                        int v = graph[u][i]; // Obtiene un nodo adyacente
                        if (colors[v] == 0) { // Si el nodo adyacente no tiene color
                            colors[v] = -colors[u]; // Asigna el color opuesto
                            queue[rear++] = v; // Encola el nodo
                        } else if (colors[v] == colors[u]) { // Si dos nodos adyacentes tienen el mismo color
                            return false; // No es bipartito
                        }
                    }
                }
            }
        }

        return true; // El grafo es bipartito
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
