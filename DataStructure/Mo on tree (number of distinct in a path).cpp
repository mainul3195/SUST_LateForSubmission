const int mod = 1e9 + 7, LG = 18;const int N = 2e5 + 6;const int BLOCK_SIZE = 450;int a[N];
vector<int>node[N];int starttime[N], endtime[N];int ft[N];int par[N][LG + 1], dep[N], sz[N];int timer = 1;
void dfs(int u, int p = 0){
ft[timer] = u;starttime[u] = timer++;par[u][0] = p;dep[u] = dep[p] + 1;sz[u] = 1;
for (int i = 1; i <= LG; i++){par[u][i] = par[par[u][i - 1]][i - 1];}
for (auto v : node[u]){if (v == p) continue;dfs(v, u);sz[u] += sz[v];}ft[timer] = u;endtime[u] = timer++;}
int lca(int u, int v){ // ache already}
int freq[N];int colour[N];int res;
void operation(int id){
int curnode = ft[id];int c = a[curnode];
if (freq[curnode] == 0){colour[c]++;
if (colour[c] == 1)res++;}
else{colour[c]--;if (colour[c] == 0)res--;}freq[curnode] ^= 1;}
void Solve(){
int n, q;
while (cin >> n >> q){
set<ll>st;map<ll , ll>m;
for (int i = 1 ; i <= n ; i++){cin >> a[i];}int tot = 0;
for (int i = 1 ; i <= n ; i++){if (m[a[i]])a[i] = m[a[i]];else{m[a[i]] = ++tot;a[i] = m[a[i]];}}
for (int i = 1 ; i < n ; i++){int u, v;cin >> u >> v;node[u].push_back(v);node[v].push_back(u);}
dfs(1);ll ans[q + 1];Query queries[q];
for (int i = 0 ; i < q ; i++){int u, v, c;cin >> u >> v;int lc = lca(u, v);
if (dep[u] > dep[v])swap(u, v);
if (lc == u || lc == v)queries[i] = {starttime[u], starttime[v], i + 1, 1, lc, -1};
else queries[i] = {endtime[u], starttime[v], i + 1, 1, lc, 1};}
sort(queries, queries + q);
int Left = 1, Right = 0;
for (auto i : queries){
int l = i.l;int r = i.r;int id = i.idx;int c = i.c;int type = i.type;int lc = i.lc;
while (Right < r)operation(++Right);
while (Left > l)operation(--Left);
while (Left < l)operation(Left++);
while (Right > r)operation(Right--);
if (type == 1){operation(starttime[lc]);}
ans[id] = res;
if (type == 1)operation(starttime[lc]);}
for (int i = 1 ; i <= q ; i++) {cout << ans[i] << endl;}}}
