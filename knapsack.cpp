
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;
    int weight[101], profit[101];
    int dp[101][101] = {0};

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights: ";
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    cout << "Enter profits: ";
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i] <= w) {
                dp[i][w] = max(
                    profit[i] + dp[i - 1][w - weight[i]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum profit: " << dp[n][capacity] << endl;

    return 0;
}
