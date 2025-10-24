#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> dijkstra(int src, vector<vector<pair<int, int>>>& g) {
    vector<int> dist(g.size(), INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for (auto nei : g[node]) {
            int v = nei.first;
            int weight = nei.second;
            if (dist[node] + weight < dist[v]) {                
                dist[v] = dist[node] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
int main() {
    vector<vector<pair<int, int>>> g(23); // 1 based indexing of the adjacency list
    g[0]= {};
    g[1] = {{2, 1}, {11, 1}};
    g[2] = {{1, 1}, {3, 1}, {21, 1}};
    g[3] = {{2, 1}, {4, 1}, {8, 2}};
    g[4] = {{3, 1}, {5, 1}};
    g[5] = {{4, 1}, {6, 2}, {7, 1}, {22, 1}};
    g[6] = {{5, 2}, {7, 2}};
    g[7] = {{5, 1}, {6, 2}, {8, 1}};
    g[8] = {{3, 2}, {7, 1}, {9, 1}};
    g[9] = {{8, 1}, {10, 1}, {19, 2}};
    g[10] = {{9, 1}, {11, 1}, {18, 2}};
    g[11] = {{1, 1}, {10, 1}, {12, 2}, {17, 1}};
    g[12] = {{11, 2}, {13, 2}};
    g[13] = {{12, 2}, {14, 2}, {21, 1}};
    g[14] = {{13, 2}, {15, 1}, {16, 1}, {20, 1}};
    g[15] = {{14, 1}};
    g[16] = {{14, 1}, {17,  2}};
    g[17] = {{11, 1}, {16, 2}, {18, 2}};
    g[18] = {{10, 2}, {17, 2}, {19, 2}};
    g[19] = {{9, 2}, {18, 2}};
    g[20] = {{14, 1}, {21, 2}};
    g[21] = {{2, 1}, {13, 1}, {20, 2}, {22, 2}};
    g[22] = {{5, 1}, {21, 2}};   

    vector<int> distances;
    int source = 1;
    distances = dijkstra(source, g);
    cout << "Vertex Distance from Source (0):\n";
    for (int i = 1; i < distances.size(); i++) {
        cout << "Vertex " << i << " : " << distances[i] << "\n";
    }
    vector<int> question = {6, 8, 9, 15, 16, 22};
    for(int q : question){
        cout << "Distance from " << source << " to " << q << " is " << distances[q] << "\n";
    }
    return 0;
}             