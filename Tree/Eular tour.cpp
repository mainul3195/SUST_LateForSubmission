vector<int>node[N];int Intime[N], Outtime[N], Level[N] , a[N];
int timer = 1;int n, q;void EulerTour(int p, int par, int d){
Intime[p] = timer++; Level[p] = d; for (auto i : node[p]){if (i == par)
continue;EulerTour(i, p, Level[p] + 1);} Outtime[p] = timer;    
//if timer++ then intime[u] to intime[v] can be find path query
}struct BIT {} T[2];void Solve(){ cin >> n >> q;
for (int i = 1 ; i <= n ; i++) cin >> a[i];
for (int i = 1 ; i < n ; i++){ int u, v; cin >> u >> v;
node[u].push_back(v); node[v].push_back(u);}EulerTour(1, 0, 0);
for (int i = 1 ; i <= n ; i++){T[Level[i] % 2].upd(Intime[i], Intime[i], a[i]);
T[!(Level[i] % 2)].upd(Intime[i], Intime[i], 0);}while (q--){ int type;
cin >> type; if (type == 1){ ll x, val; cin >> x >> val;
T[Level[x] % 2].upd(Intime[x], Outtime[x]-1, val);
T[!(Level[x] % 2)].upd(Intime[x], Outtime[x]-1, -val);} else {ll x;
cin >> x; cout << T[Level[x] % 2].query(Intime[x], Intime[x]) << endl;}}}
