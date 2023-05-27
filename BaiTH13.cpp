#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// ??nh ngh?a c?u tr�c ??nh trong ?? th?
struct Vertex {
    int id;             // ID c?a ??nh
    int distance;       // Kho?ng c�ch t? ??nh b?t ??u ??n ??nh n�y
};

// H�m so s�nh hai ??nh d?a tr�n kho?ng c�ch
struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance;
    }
};

// H�m t�m ???ng ?i ng?n nh?t t? ??nh b?t ??u ??n t?t c? c�c ??nh c�n l?i
void shortestPath(vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();

    // Kh?i t?o m?t vector l?u kho?ng c�ch t? ??nh b?t ??u ??n t?t c? c�c ??nh
    vector<int> distances(numVertices, numeric_limits<int>::max());

    // ??t kho?ng c�ch t? ??nh b?t ??u ??n ch�nh n� l� 0
    distances[start] = 0;

    // T?o m?t h�ng ??i ?u ti�n ?? l?u tr? c�c ??nh v� kho?ng c�ch t??ng ?ng
    priority_queue<Vertex, vector<Vertex>, CompareVertex> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        // L?y ??nh c� kho?ng c�ch nh? nh?t t? h�ng ??i
        Vertex current = pq.top();
        pq.pop();

        int currId = current.id;
        int currDistance = current.distance;

        // Ki?m tra xem ??nh n�y c� ph?i l� ??nh t?t nh?t hay kh�ng
        // (t?c l� ?� t�m ???c ???ng ?i ng?n nh?t t? ??nh b?t ??u ??n n� ch?a)
        if (currDistance > distances[currId]) {
            continue;
        }

        // Duy?t qua t?t c? c�c ??nh k? c?a ??nh hi?n t?i
        for (int i = 0; i < numVertices; i++) {
            // N?u c� ???ng ?i t? ??nh hi?n t?i ??n ??nh k? i
            // v� ???ng ?i n�y ng?n h?n ???ng ?i hi?n t?i ??n ??nh i
            if (graph[currId][i] != 0 && currDistance + graph[currId][i] < distances[i]) {
                // C?p nh?t kho?ng c�ch
                distances[i] = currDistance + graph[currId][i];
                // Th�m ??nh k? v�o h�ng ??i
                pq.push({i, distances[i]});
            }
        }
    }

    // In ra kho?ng c�ch t? ??nh b?t ??u ??n t?t c? c�c ??nh
    for (int i = 0; i < numVertices; i++) {
        cout << "Distance from vertex " << start << " to vertex " << i << " is " << distances[i] << endl;
    }
}

int main() {
    int numVertices, start;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    // T?o ma tr?n ?? th?
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    // Nh?p ma tr?n ?? th? t? ng??i d�ng
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting vertex: ";
    cin >> start;

    shortestPath(graph, start);

    return 0;
}

