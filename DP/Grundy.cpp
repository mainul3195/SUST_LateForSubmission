int Grundy(int n){ if (n <= 2) return 0;
if (dp[n] != -1)return dp[n];vector<int>vis(1005, 0);
for (int i = 1 ; i < n ; i++){ if (n - i != i)
{vis[(Grundy(n - i)^Grundy(i))] = 1;}}int p = 0;
while(vis[p]) p++;return dp[n] = p;}//pile divided into two unequal pile
