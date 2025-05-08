// s = "#" + s; 
struct PaliTree{ #define sz 26 struct node{ int  
lng; int link; int next[sz]; int occ; node(int _ 
lng){ lng = _lng; link = 0; occ = 0; memset(next 
,-1,sizeof(next)); } }; vector<node> tree; strin 
g s; int cur;  PaliTree(){ tree.push_back(node(- 
1)); //img 
tree.push_back(node(0)); //root 
cur = 1; } void clear(){ tree.clear(); tree.push 
_back(node(-1)); //img 
tree.push_back(node(0)); //root 
cur = 1; } int get_id(char c){return c-'a';} int 
get_link(int now,int i){ char c = s[i]; while(1 
){ if(now == 0 or (i-1-tree[now].lng > 0 and s[i -1-tree[now].lng] == c)) break; now = tree[now].
 link; } int id = get_id(c); return (tree[now].ne
 xt[id] == -1)?now:tree[now].next[id]; } void add
 (int i){ char c = s[i]; int id = get_id(c); whil
 e(1){ if(cur == 0 or (i-1-tree[cur].lng > 0 and
 s[i-1-tree[cur].lng] == c)) break; cur = tree[cu
 r].link; } if(cur == 0 and s[i] == s[i-1]) cur =
 1; if(tree[cur].next[id] == -1){ node tmp(tree[ 
cur].lng+2); if(tmp.lng == 1) tmp.link = 1; else 
tmp.link = get_link(tree[cur].link,i); tree.pus 
h_back(tmp); tree[cur].next[id] = tree.size()-1; 
} cur = tree[cur].next[id]; tree[cur].occ++; }  
void calc(){ for(int i = tree.size()-1; i > 1; i --) tree[tree[i].link].occ += tree[i].occ; } };
