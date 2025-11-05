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

// 1. Program meminta input jumlah vertex (V) dan edge (E).
//    Vertex adalah titik/node, sedangkan edge adalah hubungan antar node.

// 2. Program membangun graph berbasis adjacency list menggunakan vector 2 dimensi:
//       graph[u].push_back(v);
//       graph[v].push_back(u);
//    Artinya graph bersifat tidak terarah.

// 3. Input S (node awal infeksi) dan K (hari ke berapa infeksi ingin diketahui).

// 4. Array 'visited' digunakan untuk menyimpan hari kapan setiap node terinfeksi.
//    Nilai awal -1 artinya belum terinfeksi.

// 5. Node awal (S) diset terinfeksi pada hari 0, lalu dimasukkan ke queue.

// 6. Program menggunakan BFS (Breadth First Search) untuk menyebarkan infeksi:
//    - BFS sangat cocok karena menyebar lapisan per lapisan.
//    - Setiap node tetangga yang belum terinfeksi akan tercatat:
//         visited[tetangga] = visited[node] + 1
//      Artinya, tetangga terinfeksi 1 hari setelah node sumber.

// 7. BFS dijalankan sampai queue kosong, artinya semua node yang mungkin terinfeksi sudah diketahui.

// 8. Setelah BFS selesai, program mencari semua node yang tepat berada di hari K:
//         if (visited[i] == K)
//             hasil.push_back(i);

// 9. Jika tidak ada node dengan hari infeksi K, tampilkan "(TIDAK ADA)".

// 10. Jika ada, hasil diurutkan agar output rapi lalu dicetak.

// 11. Program selesai menampilkan node mana saja yang terinfeksi tepat pada hari K.
