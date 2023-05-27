#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX // Giá tr? vô cùng

// ??nh ngh?a m?t c?nh trong ?? th?
struct Edge {
    int destination; // ??nh ?ích
    int weight;      // Tr?ng s? c?a c?nh
};

// ??nh ngh?a ?? th?
typedef vector<vector<Edge>> Graph;

// Hàm tìm ???ng ?i ng?n nh?t t? ??nh ngu?n ??n các ??nh khác
void Dijkstra(const Graph& graph, int source, vector<int>& distance) {
    int numVertices = graph.size();

    // Kh?i t?o m?ng distance ban ??u v?i giá tr? vô cùng
    distance.assign(numVertices, INF);

    // Kh?i t?o hàng ??i ?u tiên ?? l?u tr? các ??nh và kho?ng cách t??ng ?ng
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // ??t kho?ng cách c?a ??nh ngu?n là 0 và ??a nó vào hàng ??i ?u tiên
    distance[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Duy?t qua t?t c? các ??nh k? c?a ??nh hi?n t?i
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // N?u có m?t ???ng ?i ng?n h?n t? ??nh ngu?n ??n v
            if (distance[v] > distance[u] + weight) {
                // C?p nh?t kho?ng cách và ??a ??nh vào hàng ??i ?u tiên
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
}

int main() {
    int numVertices = 5; // S? l??ng ??nh trong ?? th?

    // Kh?i t?o ?? th? v?i s? l??ng ??nh cho tr??c
    Graph graph(numVertices);

    // Thêm các c?nh vào ?? th?
    // Ví d?: ??nh 0 k? v?i ??nh 1 và có tr?ng s? là 2
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({3, 3});
    graph[2].push_back({4, 5});
    graph[3].push_back({4, 2});

    int source = 0; // ??nh ngu?n

    vector<int> distance;
    Dijkstra(graph, source, distance);

    // In ra kho?ng cách ng?n nh?t t? ??nh ngu?n ??n các ??nh khác
    cout << "Khoang cach ngan nhat tu dinh nguon: " << source << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Den dinh " << i << ": " << distance[i] << endl;
    }

    return 0;
}

