ll n, q;vector<ll>node[N];ll a[N];
struct SegmentTree { vector<ll> tree;
vector<ll> lazy; vector<ll> aa; SegmentTree() {
tree.resize(4 * N); lazy.resize(4 * N); aa.resize(4 * N);}
void build(ll node, ll b, ll e) { if (b == e) {
tree[node] = 0; lazy[node] = -1;return;}
ll mid = (b + e) >> 1; build(2 * node, b, mid);
build(2 * node + 1, mid + 1, e); lazy[node] = -1;
tree[node] = tree[2 * node] + tree[2 * node + 1];}
void push(ll node, ll b, ll e) { tree[node] = (e - b + 1) * lazy[node];
if (b != e) { lazy[2 * node] = lazy[2 * node + 1] = lazy[node];}
lazy[node] = -1;} void update(ll node, ll b, ll e, ll l, ll r, ll x) {
if (lazy[node] != -1) push(node, b, e); if (l > e || r < b) return;
if (l <= b && r >= e) { tree[node] =  (e - b + 1) * x;
if (b != e) { lazy[2 * node] = lazy[2 * node + 1] = x; }
lazy[node] = -1;return;}ll mid = (b + e) >> 1;
update(2 * node, b, mid, l, r, x); update(2 * node + 1, mid + 1, e, l, r, x);
tree[node] = tree[2 * node] + tree[2 * node + 1];}
ll query(ll node, ll b, ll e, ll l, ll r) { if (lazy[node] != -1)
push(node, b, e); if (l > e || r < b) return 0; if (l <= b && r >= e) {return tree[node];}ll mid = (b + e) >> 1;
    return query(2 * node, b, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
  }
};SegmentTree st;ll par[N][LG + 1], dep[N], sz[N];void dfs(int u, int p = 0){
par[u][0] = p;dep[u] = dep[p] + 1;sz[u] = 1;for (int i = 1; i <= LG; i++){
par[u][i] = par[par[u][i - 1]][i - 1];}for (auto v : node[u]){
if (v == p) continue;dfs(v, u);sz[u] += sz[v];}}
int lca(int u, int v){
  // ache already}
int intime[N], head[N];int timer = 1;map<ll, ll>alledge[N];
void decompose(int p, int parent, int Head_node){intime[p] = timer++;
head[p] = Head_node;st.update(1, 1, n, intime[p], intime[p], alledge[parent][p]);
int heavysize = -1, heavychild = -1;for (auto i : node[p]){if (i != parent){
if (sz[i] > heavysize)heavysize = sz[i], heavychild = i;}}if (heavychild == -1)
return ; decompose(heavychild, p, Head_node);for (auto i : node[p]){
if (i == heavychild || i == parent)continue;decompose(i, p, i);}}
ll sumpath(int u, int v){ll ans = 0;
//cout << "here " << u << " " << v << endl;
if (u == v) return 0; while (head[u] != head[v]){ if (dep[head[u]] > dep[head[v]])
swap(u, v); ans += st.query(1, 1, n, intime[head[v]], intime[v]);v = par[head[v]][0];}
if (dep[u] > dep[v])swap(u, v);if (u != v)ans +=  st.query(1, 1, n, intime[u] + 1, intime[v]);
return ans;}void reset(int n){for (int i = 0 ; i <= n ; i++){
intime[i] = head[i] = dep[i] = sz[i] = 0;a[i] = 0;node[i].clear();
timer = 1;alledge[i].clear();}}void Solve(){cin >> n;//reset(n);
st.build(1, 1, n);vector<pair<int, int> > edge;for (int i = 1 ; i < n ; i++){
ll u, v, w;cin >> u >> v >> w;alledge[u][v] = w;alledge[v][u] = w;node[u].push_back(v);
node[v].push_back(u);edge.push_back({u, v});}dfs(1);decompose(1, 0, 1);int q;
cin >> q;while (q--){int type;cin >> type;if (type == 1){
ll id, x;cin >> id >> x;id--;int p = edge[id].f;int q = edge[id].s;
if (dep[p] > dep[q]) swap(p, q);st.update(1, 1, n, intime[q], intime[q], x);
alledge[p][q] = x;alledge[q][p] = x}else{int u, v;cin >> u >> v;
int l = lca(u, v);if (u == v){cout << 0 << endl;continue;}
if (l == u || l == v){if (dep[u] > dep[v]) swap(u, v); cout << sumpath(u, v) << endl;}
else{cout << sumpath(l, u) + sumpath(l, v) << endl;}}}}
