#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int target = n - m;  // We want to reach this many apples remaining
    
    // DP array: E[k] = expected days to reach target from k apples
    vector<double> dp(n + 1, 0.0);
    
    // Base case: already at target
    dp[target] = 0.0;
    
    // Fill DP from target+1 to n
    for (int k = target + 1; k <= n; k++) {
        double expected = 1.0;  // Current day
        
        // Sum expectations for all possible moves
        double sum = 0.0;
        for (int i = 1; i <= k - target; i++) {
            sum += dp[k - i];
        }
        
        expected += sum / k;
        dp[k] = expected;
    }
    
    // Output result with 2 decimal places
    cout << fixed << setprecision(2) << dp[n] << endl;
    
    return 0;
}