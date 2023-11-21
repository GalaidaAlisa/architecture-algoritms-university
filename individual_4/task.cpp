// Джерелом орграфа назвемо вершину, від якої досяжні всі
// інші вершини; стоком — вершину, яку можна досягти від
// інших вершин. Знайти всі джерела та стоки даного орграфа.


#include <iostream>
#include <fstream>

using namespace std;
# define SIZE 9

// перевірка на сток
bool is_stock(int graph[SIZE][SIZE], int vertex) {
    for (int i = 0; i < SIZE; i++) {
        if (i != vertex  && graph[i][vertex] == 0) {
            return false;
        }
    }
    return true;
}

// перевірка на джерело
bool is_source(int graph[SIZE][SIZE], int vertex) {
    for (int i = 0; i < SIZE; i++) {
        if (i != vertex  && graph[vertex][i] == 0) {
            return false;
        }
    }
    return true;
}

// вивід всіх джерел
void all_sources(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (is_source(graph, i)) {
            cout << "Vertex " << i + 1 << " is a source" << endl;
        }
    }
}

// вивід всіх стоків
void all_stocks(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (is_stock(graph, i)) {
            cout << "Vertex " << i + 1 << " is a stock" << endl;
        }
    }
}

// функція збереження графу до текстового файлу
void save_to_file(int graph[SIZE][SIZE]) {
    const char* filename = "graph.txt";

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error while opening file";
        return;
    }
    file << "  ";
    for (int i = 0; i < SIZE; i++) {
        file << i + 1 << " ";
    }
    file << endl;
    for (int i = 0; i < SIZE; i++) {
        file << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            file << graph[i][j] << " ";
        }
        file << endl;
    }
}

int main() {
    int graph[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
     };

    all_sources(graph);
    all_stocks(graph);
    save_to_file(graph);
    return 0;
}
