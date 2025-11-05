#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int V, E;
    cout << "Jumlah vertex dan edge: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int S, K;
    cout << "Node Awal dan Hari Terinfeksi: ";
    cin >> S >> K;

    vector<int> visited(V, -1);
    queue<int> q;

    visited[S] = 0;
    q.push(S);

    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int tetangga : graph[node]){
            if(visited[tetangga] == -1){
                visited[tetangga] = visited[node] + 1;
                q.push(tetangga);
            }
        }
    }

    vector<int> hasil;
    for(int i=0; i<V; i++){
        if(visited[i] == K){
            hasil.push_back(i);
        }
    }

    cout << "Node terinfeksi: ";
    if(hasil.empty()){
        cout << "(TIDAK ADA)";
    } else {
        sort(hasil.begin(), hasil.end());
        for(int h : hasil) cout << h << " ";
    }
    cout << endl;

    return 0;
}