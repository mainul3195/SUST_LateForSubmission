const ll N = 1e7 + 7;bool isPrime[N];vector < ll > p;
void lin_sieve () {ll i;for (i = 2; i < N; i++) {
if (!isPrime[i]) p.push_back (i);for (ll j : p) {
if (i * j >= N) break;isPrime[i * j] = 1;if (i % j == 0) break;}}}
