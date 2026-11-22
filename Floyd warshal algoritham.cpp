
#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (use 999 for infinity):\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][k] != 999 && a[k][j] != 999)
                {
                    if(a[i][k] + a[k][j] < a[i][j])
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 999)
                cout << "INF ";
            else
                cout << a[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
