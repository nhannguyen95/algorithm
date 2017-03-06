#include <iostream>
#include <cstring>
using namespace std;

string s;
int dp[1005][1005];

int solve(int i, int j) {
    if (i > j) return 0;
    if (dp[i][j] != 0) return dp[i][j];
    if (i == j) return (dp[i][j] = 1);
    if (j-i==1) return (s[i]==s[j]) ? dp[i][j]=2 : dp[i][j] = 1;

    if (s[i] == s[j]) return dp[i][j] = 2 + solve(i+1,j-1);
    return dp[i][j] = max(solve(i,j-1),solve(i+1,j));
}

int main() {
    
    int T; cin >> T; cin.ignore(1);
    while(T--) {
        getline(cin, s);
        memset(dp, 0, sizeof(dp));
        cout << solve(0, s.size()-1) << '\n';
    }
    
    return 0;
}
