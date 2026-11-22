
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[20][20] = {0};

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

    int start, visited[20] = {0};
    queue<int> q;

    cout << "Enter starting vertex: ";
    cin >> start;

    visited[start] = 1;
    q.push(start);

    cout << "BFS Traversal: ";

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for(int i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    return 0;
}
