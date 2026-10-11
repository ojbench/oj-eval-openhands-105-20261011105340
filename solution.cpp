#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // DP array: E[k] = expected days to eat at least m apples when we have k apples remaining
    vector<double> dp(n + 1, 0.0);
    
    // Fill DP from 0 to n
    for (int k = 0; k <= n; k++) {
        // If we've already eaten at least m apples, no more days needed
        if (n - k >= m) {
            dp[k] = 0.0;
            continue;
        }
        
        // Otherwise, we need to continue eating
        double expected = 1.0;  // Current day
        
        // Sum expectations for all possible moves
        double sum = 0.0;
        for (int i = 1; i <= k; i++) {
            int next_k = max(0, k - i);
            sum += dp[next_k];
        }
        
        expected += sum / k;
        dp[k] = expected;
    }
    
    // Output result with 2 decimal places
    cout << fixed << setprecision(2) << dp[n] << endl;
    
    return 0;
}