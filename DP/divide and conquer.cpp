mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Left = 1, Right = 0;ll cost(ll l, ll r) {while (Right < r)Add(++Right);
while (Left > l)Add(--Left);while (Left < l)Remove(Left++);while (Right > r)
Remove(Right--);return Totsum;}ll dp[2][N];
void compute(int group, int l, int r, int optl, int optr) {if (l > r)return ;
int mid = (l + r) / 2;dp[group & 1][mid] = LLONG_MAX;int optnow = optl;
for (int k = optl ; k <= min(mid, optr) ; k++) {ll ret = dp[!(group & 1)][k] + cost(k + 1, mid);
if (ret < dp[group & 1][mid]) {dp[group & 1][mid] = ret;optnow = k;}}
compute(group, l, mid - 1, optl, optnow);compute(group, mid + 1, r, optnow, optr);}
void Solve() {cin >> n >> k;for (int i = 1 ; i <= n ; i++) {cin >> a[i];}
for (int i = 1 ; i <= n ; i++) {dp[1 & 1][i] = cost(1, i);}for (int i = 2 ; i <= k ; i++) {
compute(i, 1, n, 1, n);}cout << dp[k & 1][n] << endl;}
