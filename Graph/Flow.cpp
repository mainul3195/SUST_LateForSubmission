lli n, m; vector<set<lli>> roads; vector<vector<lli>> adjm; vector<lli> parents;
lli bfs(lli s, lli t){
fill(parents.begin(), parents.end(), -1); parents[s] = -2;
queue<pair<lli, lli>> q; q.push({s, LLONG_MAX});
while (!q.empty()){ lli ind = q.front().first; lli flow = q.front().second; q.pop();
for (lli cind: roads[ind]){ if (parents[cind] == -1 && adjm[ind][cind] > 0){
 parents[cind] = ind; if (cind == t) return min(flow, adjm[ind][cind]);
 q.push({cind, min(adjm[ind][cind], flow)});}}} return 0; }
lli getFlow(){
lli totflow = 0, nflow;
while (nflow = bfs(0, n - 1)){ totflow += nflow; lli ind = n - 1;
while (ind != 0){ adjm[ind][parents[ind]] += nflow;
  adjm[parents[ind]][ind] -= nflow; ind = parents[ind];
}}
return totflow;
}
