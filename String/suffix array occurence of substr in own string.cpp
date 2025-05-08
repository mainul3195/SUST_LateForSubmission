int Table[N][20], a[N];void Build(vector<int>lcp){
int n = lcp.size();for (int i = 1 ; i <= n ; i++)
Table[i][0] = lcp[i - 1];for (int k = 1 ; k < 20 ; k++){
for (int i = 1 ; i + (1 << k) - 1 <= n ; i++)
Table[i][k] = min(Table[i][k - 1], Table[i + (1 << (k - 1))][k - 1]);}}
int Query(int l, int r){l++, r++;int k = log2(r - l + 1);
return min(Table[l][k], Table[r - (1 << k) + 1][k]);}
pair<int, int>FindRight(int low, int high, int val) // Find maximum R such that lcp(low, low+1...)>Val and return lcp(low, R)
{int l = low, r = high, mid;int ans = low - 1 ;while (l <= r){
mid = (l + r) / 2;if (Query(low , mid) > val){ans = mid, l = mid + 1;}
else r = mid - 1;}if (ans == low - 1)return {low, -1};
else return {ans + 1, Query(low, ans)};}
void Solve(){string s;cin >> s;SuffixArray ehhe(s);
ll n = s.size();vector<int>p = ehhe.sa;vector<int>lcp;
lcp = ehhe.lcp;Build(lcp);ll ans = 0;
for (int i = 0 ; i < n ; i++){int high = n - 1;int pans = i ? lcp[i - 1] : 0;
int len = n - p[i];while (pans < len){
pair<int, int> pt = FindRight(i, high, pans); // pt = {maximum r such that lcp(i, r)>val, lcp(i, r)}
int right = pt.f;ll templ = right - i + 1;
if (pt.f == i) pt.s = len;ll contr = (pt.s - pans);
ans += (contr * (templ * (templ)));  // len of contr occurs templ times
high = pt.f;pans = pt.s;}}cout << ans << endl;}
// Problem link : https://codeforces.com/contest/802/problem/I
