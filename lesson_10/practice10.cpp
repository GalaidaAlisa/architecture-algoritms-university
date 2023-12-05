#include <iostream>
#include <climits>

using namespace std;
#define SIZE 6

// функція виводу
void solution(int distances[SIZE]) {
    cout << "Vertex \t Distance\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << "\t\t" << distances[i] << endl;
    }
}

// шукаємо вершину, з мінімальним шляхом, яку ще не відвідали
int min_distance(int distances[SIZE], bool visited[SIZE]) {  
    int min_distance = INT_MAX;
    int min_index;
    for (int i = 0; i < SIZE; i++) {
        if (!visited[i] && distances[i] < min_distance) {
            min_distance = distances[i];
            min_index = i;
        }
    }
    return min_index;
}

// реалізація функції Дейкстри
void dijkstra(int graph[SIZE][SIZE], int source) {
    int distances[SIZE];
    bool visited[SIZE];

    for (int i = 0; i < SIZE; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    distances[source] = 0;

    for (int i = 0; i < SIZE - 1; i++) {
        int vertex = min_distance(distances, visited);  
        visited[vertex] = true;

        for (int u = 0; u < SIZE; u++) {
            if (!visited[u] && graph[vertex][u] && distances[vertex] != INT_MAX && 
                distances[vertex] + graph[vertex][u] < distances[u]) {
                distances[u] = distances[vertex] + graph[vertex][u];
            }
        }
    }

    solution(distances);
}


int main() {
    int graph[SIZE][SIZE] = { {0, 3, 7, 0, 0, 0},
                              {1, 0, 2, 0, 0, 1},
                              {0, 1, 0, 2, 4, 0},
                              {0, 0, 0, 0, 1, 5},
                              {0, 0, 1, 0, 0, 3},
                              {0, 0, 0, 2, 0, 0} };

    dijkstra(graph, 0);
    
    int graph1[SIZE][SIZE] = { {0, 1, 4, 0, 0, 0},
                               {1, 0, 4, 2, 7, 0},
                               {4, 4, 0, 3, 5, 0},
                               {0, 2, 3, 0, 4, 6},
                               {0, 7, 5, 4, 0, 7},
                               {0, 0, 0, 6, 7, 0} };
    dijkstra(graph1, 5);
    return 0;
}
