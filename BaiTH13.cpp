#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// ??nh ngh?a c?u trúc ??nh trong ?? th?
struct Vertex {
    int id;             // ID c?a ??nh
    int distance;       // Kho?ng cách t? ??nh b?t ??u ??n ??nh này
};

// Hàm so sánh hai ??nh d?a trên kho?ng cách
struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance;
    }
};

// Hàm tìm ???ng ?i ng?n nh?t t? ??nh b?t ??u ??n t?t c? các ??nh còn l?i
void shortestPath(vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();

    // Kh?i t?o m?t vector l?u kho?ng cách t? ??nh b?t ??u ??n t?t c? các ??nh
    vector<int> distances(numVertices, numeric_limits<int>::max());

    // ??t kho?ng cách t? ??nh b?t ??u ??n chính nó là 0
    distances[start] = 0;

    // T?o m?t hàng ??i ?u tiên ?? l?u tr? các ??nh và kho?ng cách t??ng ?ng
    priority_queue<Vertex, vector<Vertex>, CompareVertex> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        // L?y ??nh có kho?ng cách nh? nh?t t? hàng ??i
        Vertex current = pq.top();
        pq.pop();

        int currId = current.id;
        int currDistance = current.distance;

        // Ki?m tra xem ??nh này có ph?i là ??nh t?t nh?t hay không
        // (t?c là ?ã tìm ???c ???ng ?i ng?n nh?t t? ??nh b?t ??u ??n nó ch?a)
        if (currDistance > distances[currId]) {
            continue;
        }

        // Duy?t qua t?t c? các ??nh k? c?a ??nh hi?n t?i
        for (int i = 0; i < numVertices; i++) {
            // N?u có ???ng ?i t? ??nh hi?n t?i ??n ??nh k? i
            // và ???ng ?i này ng?n h?n ???ng ?i hi?n t?i ??n ??nh i
            if (graph[currId][i] != 0 && currDistance + graph[currId][i] < distances[i]) {
                // C?p nh?t kho?ng cách
                distances[i] = currDistance + graph[currId][i];
                // Thêm ??nh k? vào hàng ??i
                pq.push({i, distances[i]});
            }
        }
    }

    // In ra kho?ng cách t? ??nh b?t ??u ??n t?t c? các ??nh
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

    // Nh?p ma tr?n ?? th? t? ng??i dùng
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

