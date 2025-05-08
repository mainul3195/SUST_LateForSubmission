int n,m;
int parent[MAX],Rank[MAX];
void Init(int n){for(int i=0 ;i<=n ;i++)Rank[i]=1,parent[i]=i;}
int Find_parent(int v) {if (v == parent[v]) {return v;}return parent[v] = Find_parent(parent[v]);}
void Union(int a, int b) {
a = Find_parent(a);b = Find_parent(b);if (a != b) {if (Rank[a] > Rank[b]) {swap (a, b);}parent[a] = b;Rank[b] += Rank[a];}}
