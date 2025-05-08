priority_queue< pair<ll, ll>, vector<pair<ll , ll> >, greater<pair<ll , ll > > > pq;
int parrent[100003];void dijsktra(ll p){parrent[1] = 1;pq.push({0, p});
dis[p] = 0;ans.push_back(p);while (!pq.empty()){
ll curr_node = pq.top().second;ll curr_dis = pq.top().first;
pq.pop();for ( pair<ll , ll> child : node[curr_node]){
if (child.second + curr_dis < dis[child.first]){
parrent[child.first] = curr_node;dis[child.first] = child.second + curr_dis;
pq.push({dis[child.first], child.first});}}}}
