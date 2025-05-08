int n,q;vector<int>node[N];int a[N];
struct SegmentTree {
    vector<int>tree;vector<int>lazy;vector<int>aa;
    SegmentTree() {tree.resize(4*N);lazy.resize(4*N);aa.resize(4*N);}
    void build(int node,int b,int e) {if(b==e){tree[node]=0;lazy[node]=-1;return;}int mid=(b+e)>>1;build(2*node,b,mid);build(2*node+1,mid+1,e);lazy[node]=-1;tree[node]=max(tree[2*node],tree[2*node+1]);}
    void push(int node,int b,int e) {tree[node]=lazy[node];if(b!=e){lazy[2*node]=lazy[2*node+1]=lazy[node];}lazy[node]=-1;}
    void update(int node,int b,int e,int l,int r,int x) {if(lazy[node]!=-1)push(node,b,e);if(l>e||r<b)return;if(l<=b&&r>=e){tree[node]=x;if(b!=e){lazy[2*node]=lazy[2*node+1]=x;}lazy[node]=-1;return;}int mid=(b+e)>>1;update(2*node,b,mid,l,r,x);update(2*node+1,mid+1,e,l,r,x);tree[node]=max(tree[2*node],tree[2*node+1]);}
    int query(int node,int b,int e,int l,int r) {if(lazy[node]!=-1)push(node,b,e);if(l>e||r<b)return 0;if(l<=b&&r>=e){return tree[node];}int mid=(b+e)>>1;return max(query(2*node,b,mid,l,r),query(2*node+1,mid+1,e,l,r));}
};
SegmentTree st;int par[N][LG+1],dep[N],sz[N];
void dfs(int u,int p=0){par[u][0]=p;dep[u]=dep[p]+1;sz[u]=1;for(int i=1;i<=LG;i++){par[u][i]=par[par[u][i-1]][i-1];}for(auto v:node[u]){if(v==p)continue;dfs(v,u);sz[u]+=sz[v];}}
int lca(int u,int v){if(dep[u]<dep[v])swap(u,v);for(int k=LG;k>=0;k--)if(dep[par[u][k]]>=dep[v])u=par[u][k];if(u==v)return u;for(int k=LG;k>=0;k--)if(par[u][k]!=par[v][k])u=par[u][k],v=par[v][k];return par[u][0];}
int intime[N],head[N];int timer=1;
void decompose(int p,int parent,int Head_node){intime[p]=timer++;head[p]=Head_node;st.update(1,1,n,intime[p],intime[p],a[p]);int heavysize=-1,heavychild=-1;for(auto i:node[p]){if(i!=parent){if(sz[i]>heavysize)heavysize=sz[i],heavychild=i;}}if(heavychild==-1)return;decompose(heavychild,p,Head_node);for(auto i:node[p]){if(i==heavychild||i==parent)continue;decompose(i,p,i);}}
int maxnode(int u,int v){int ans=0;while(head[u]!=head[v]){if(dep[head[u]]>dep[head[v]])swap(u,v);ans=max(ans,st.query(1,1,n,intime[head[v]],intime[v]));v=par[head[v]][0];}if(dep[u]>dep[v])swap(u,v);ans=max(ans,st.query(1,1,n,intime[u],intime[v]));return ans;}
void Solve(){cin>>n>>q;for(int i=1;i<=n;i++){cin>>a[i];}st.build(1,1,n);for(int i=1;i<n;i++){int u,v;cin>>u>>v;node[u].push_back(v);node[v].push_back(u);}dfs(1);decompose(1,0,1);while(q--){int type;cin>>type;if(type==1){int u,x;cin>>u>>x;st.update(1,1,n,intime[u],intime[u],x);}else{int u,v;cin>>u>>v;int l=lca(u,v);cout<<max(maxnode(l,u),maxnode(l,v))<<" ";}}}
