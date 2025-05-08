#include<bits/stdc++.h>using namespace std;
struct nd{long long sum;nd *left;nd *right;nd(long long data){sum=data;}
nd(nd l,nd r){sum=l.sum+r.sum;left=&l;right=&r;}};
int n;vector<nd>states;
nd build(int start,int end){
if(start==end)return nd(0);int mid=(start+end)/2;return nd(build(start,mid),build(mid+1,end));}
nd update(nd root,int start,int end,int pos,int val){if(start==end)return nd(val);
int mid=(start+end)/2;return pos<=mid?nd(update(*root.left,start,mid,pos,val),*root.right):nd(*root.left,update(*root.right,mid+1,end,pos,val));}
void solve(){cin>>n;states.push_back(build(0,n-1));states.push_back(update(states.back(),0,n-1,4,3));return;}
int main(){ios_base::sync_with_stdio(0);cin.tie(0);solve();return 0;}
