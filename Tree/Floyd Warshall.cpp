ll vis[504][504];void warshall(ll n){
for (int k = 1; k <= n; k++){for (int i = 1; i <= n; i++)
{for (int j = 1; j <= n; j++){
dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);}}}}
