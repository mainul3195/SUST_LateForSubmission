struct XorBasis { vector<ll> basis;
ll N = 0, tmp = 0; void add(ll x) {
N++; tmp |= x;for (auto &i : basis) x = min(x, x ^ i);if (!x) return;
for (auto &i : basis) if ((i ^ x) < i) i ^= x;basis.push_back(x);
sort(basis.begin(), basis.end());}
ll size() {return (ll)basis.size();
}void clear() {N = 0; tmp = 0;basis.clear();
}bool possible(ll x) {for (auto &i : basis) x = min(x, x ^ i);
return !x;}ll maxxor(ll x = 0) {for (auto &i : basis) x = max(x, x ^ i);
return x;}ll minxor(ll x = 0) {
for (auto &i : basis) x = min(x, x ^ i);
return x;}ll cntxor(ll x) {if (!possible(x)) return 0LL;//return (1LL<<(N-size()));
ll ans = 1LL;for (int i = 0; i < N - size(); i++)ans = (ans * 2) % MOD;
return ans;}ll sumOfAll() {ll ans = tmp * (1LL << (N - 1));
return ans;}ll kth(ll k) {ll sz = size();if (k > (1LL << sz)) return -1;
k--; ll ans = 0;for (ll i = 0; i < sz; i++) if (k >> i & 1) ans ^= basis[i];
return ans;}} xb;
