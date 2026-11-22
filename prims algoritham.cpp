
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    int visited[10] = {0};
    visited[0] = 1;

    int edges = 0, mincost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while(edges < n - 1)
    {
        int min = 999;
        int a = -1, b = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << a << " - " << b << " : " << min << endl;

        mincost += min;
        visited[b] = 1;
        edges++;
    }

    cout << "\nMinimum Cost = " << mincost;

    return 0;
}
