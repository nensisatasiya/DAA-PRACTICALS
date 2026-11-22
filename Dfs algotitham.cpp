
#include <iostream>
using namespace std;

int graph[20][20], visited[20] = {0};
int n;

void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges:\n";

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
