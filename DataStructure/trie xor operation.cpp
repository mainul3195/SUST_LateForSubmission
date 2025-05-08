int Trie[35 * N][2];int root = 1;int cnt[35 * N];int cur = 1;
void Update(ll x, ll value){int start = root;cnt[start] += value;
for (int i = 32 ; i >= 0 ; i--){bool bit = x & (1LL << i);
if (Trie[start][bit] == 0){Trie[start][bit] = ++cur;}
start = Trie[start][bit];cnt[start] += value;}}
ll MaxQuery(ll x){int start = root;ll ans = 0;
for (int i = 32 ; i >= 0 ; i--){bool bit = x & (1LL << i);
if (Trie[start][1 ^ bit] == 0 || cnt[Trie[start][1 ^ bit]] == 0){ans = ans;}
else {ans += (1LL << i);bit ^= 1;}start = Trie[start][bit];}return ans;}
ll MinQuery(ll x) {int start = root;ll ans = 0;
for (int i = 32 ; i >= 0 ; i--) {bool bit = x & (1LL << i);
if (Trie[start][bit]) {ans = ans;}
else {ans += (1LL << i);bit ^= 1;}start = Trie[start][bit];}return ans;}
