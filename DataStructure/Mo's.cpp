const int mod = 1e9 + 7;const int N = 5e5 + 6;const int BLOCK_SIZE = 500;
struct Query {
int l, r, idx,  lc, type;
bool operator<(const Query &y) const {
// Current query x is being compared with other query y
int x_block = l / BLOCK_SIZE;int y_block = y.l / BLOCK_SIZE;
// If x and y both lie in the same block, sort in non decreasing order of endpoint
if (x_block == y_block)return r < y.r;
// x and y lie in different blocks
return x_block < y_block;}};
ll nc3(ll x){if (x < 3)return 0;return (x * (x - 1) * (x - 2)) / 6;}
int a[N];ll last[N];ll freq[N];ll res;
void Add(int i){int x = a[i];res -= last[x];freq[x]++;last[x] = nc3(freq[x]);res += last[x];}
void Remove(int i){int x = a[i];res -= last[x];freq[x]--;last[x] = nc3(freq[x]);res += last[x];}
void Solve(){
int n, q;cin >> n >> q;
for (int i = 1 ; i <= n ; i++){cin >> a[i];}
vector<Query>queries;ll ans[q + 1];
for (int i = 1 ; i <= q ; i++){int l, r;cin >> l >> r;queries.push_back({l, r, i});}
sort(queries.begin(), queries.end());
int Left = 1, Right = 0;
for (auto i : queries){int l = i.l;int r = i.r;int id = i.idx;
while (Right < r)Add(++Right);
while (Left > l)Add(--Left);
while (Left < l)Remove(Left++);
while (Right > r)Remove(Right--);
ans[i.idx] = res;}
for (int i = 1 ; i <= q ; i++)cout << ans[i] << endl;}
//number of triple(l, r) a[i] = a[j] = a[k]
