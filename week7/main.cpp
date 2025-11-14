
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void sortAdj() {
        for (auto &list : adj) {
            sort(list.begin(), list.end());
        }
    }

    void printGraph() {
        cout << "Danh sach ke:" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int v : adj[i]) cout << v << " ";
            cout << endl;
        }
    }

    // DFS cải tiến
    void DFS(int start) {
        cout << "DFS: ";
        vector<bool> visited(V, false);
        stack<int> st;

        st.push(start);

        while (!st.empty()) {
            int v = st.top();
            st.pop();

            if (!visited[v]) {
                visited[v] = true;
                cout << v << " ";

                // Để duyệt từ nhỏ → lớn, phải push ngược
                for (int i = adj[v].size() - 1; i >= 0; i--) {
                    int u = adj[v][i];
                    if (!visited[u]) st.push(u);
                }
            }
        }
        cout << endl;
    }

    // BFS tối ưu
    void BFS(int start) {
        cout << "BFS: ";
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        cout << endl;
    }
};


int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.sortAdj();
    g.printGraph();

    cout << "------------------" << endl;
    g.DFS(0);

    cout << "------------------" << endl;
    g.BFS(0);

    return 0;
}
