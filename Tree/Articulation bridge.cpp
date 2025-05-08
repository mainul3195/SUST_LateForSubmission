vector<int>node[10003];int lowtime[10003],intime[10003],vis[10003];
vector<pair<int,int>>edge;int timer;
void dfs(int p, int parent){intime[p]=lowtime[p]=timer;timer++;
vis[p]=1;for(int child:node[p]){if(child==parent)continue;
if(vis[child]){lowtime[p]=min(lowtime[p], intime[child]); // node - child is a back edge
}else{// node -  child is a forward edge 
dfs(child,p);if(lowtime[child] > intime[p])edge.push_back({p , child});
lowtime[p] = min(lowtime[p] , lowtime[child]);}}}
