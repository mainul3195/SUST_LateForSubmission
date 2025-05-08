vector<int>node[10003];int lowtime[10003],intime[10003],vis[10003];
set<int>cut_vertex; int timer;
void IS_CUTPOINT(int x){cut_vertex.insert(x);}
void dfs(int p, int parent){intime[p]=lowtime[p]=timer;
timer++;int children=0;vis[p]=1;for(int child:node[p]){
if(child==parent) continue;if(vis[child]){
lowtime[p]=min(lowtime[p], intime[child]); // node - child is a back edge
}else{// node -  child is a forward edge 
dfs(child,p);if(lowtime[child] >= intime[p] && parent!=-1)
IS_CUTPOINT(p);lowtime[p] = min(lowtime[p] , lowtime[child]);
children++;}}if(parent == -1 && children>1)//for root
IS_CUTPOINT(p);}
