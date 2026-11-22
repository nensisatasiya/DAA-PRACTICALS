
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

int parent[10];

int find(int x)
{
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[20];

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges, edges + e, compare);

    for(int i = 0; i < n; i++)
        parent[i] = i;

    int mincost = 0, count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for(int i = 0; i < e && count < n - 1; i++)
    {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if(u != v)
        {
            cout << edges[i].u << " - " << edges[i].v
                 << " : " << edges[i].w << endl;

            mincost += edges[i].w;
            parent[u] = v;
            count++;
        }
    }

    if(count != n - 1)
        cout << "Minimum Spanning Tree is not possible";
    else
        cout << "\nMinimum Cost = " << mincost;

    return 0;
}
