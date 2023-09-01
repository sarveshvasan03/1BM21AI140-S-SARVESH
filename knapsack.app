#include <iostream>

using namespace std;

int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n];
    int values[n];

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int W;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int max_value = knapsack(W, weights, values, n);

    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
