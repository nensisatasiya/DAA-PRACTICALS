
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int cost[10][10];

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int path[10];

    for(int i = 0; i < n; i++)
        path[i] = i;

    int mincost = 999999;

    do
    {
        int total = 0;

        for(int i = 0; i < n - 1; i++)
        {
            total += cost[path[i]][path[i + 1]];
        }

        total += cost[path[n - 1]][path[0]];

        if(total < mincost)
            mincost = total;

    } while(next_permutation(path + 1, path + n));

    cout << "\nMinimum Travel Cost = " << mincost;

    return 0;
}
