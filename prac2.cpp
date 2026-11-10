#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int n = a.size();
    int m = b.size();
    int p = c.size();
    int q = d.size();
    int r = e.size();
    int dp[12][12][12][12][12] = {};
    // Build 5D DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= p; k++) {
                for (int l = 1; l <= q; l++) {
                    for (int t = 1; t <= r; t++) {
                        if (a[i-1] == b[j-1] &&
                            b[j-1] == c[k-1] &&
                            c[k-1] == d[l-1] &&
                            d[l-1] == e[t-1]) {
                            dp[i][j][k][l][t] =
                                1 + dp[i-1][j-1][k-1][l-1][t-1];
                        }
                        else {
                            dp[i][j][k][l][t] = max({
                                dp[i-1][j][k][l][t],
                                dp[i][j-1][k][l][t],
                                dp[i][j][k-1][l][t],
                                dp[i][j][k][l-1][t],
                                dp[i][j][k][l][t-1]
                            });
                        }
                    }
                }
            }
        }
    }

    // Backtracking to print LCS
    string ans = "";
    int i = n, j = m, k = p, l = q, t = r;
    while (i > 0 && j > 0 && k > 0 && l > 0 && t > 0) {
        if (a[i-1] == b[j-1] &&
            b[j-1] == c[k-1] &&
            c[k-1] == d[l-1] &&
            d[l-1] == e[t-1]) {
            ans += a[i-1];
            i--;
            j--;
            k--;
            l--;
            t--;
        }
        else {
            int mx = max({
                dp[i-1][j][k][l][t],
                dp[i][j-1][k][l][t],
                dp[i][j][k-1][l][t],
                dp[i][j][k][l-1][t],
                dp[i][j][k][l][t-1]
            });

            if (dp[i-1][j][k][l][t] == mx)
                i--;
            else if (dp[i][j-1][k][l][t] == mx)
                j--;
            else if (dp[i][j][k-1][l][t] == mx)
                k--;
            else if (dp[i][j][k][l-1][t] == mx)
                l--;
            else
                t--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << "LCS Length: " << dp[n][m][p][q][r] << endl;
    cout << "LCS: " << ans << endl;

    return 0;
}
