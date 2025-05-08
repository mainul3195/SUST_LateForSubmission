vector<bool>prime(N, true);vector<int>vec ;
void seive() { prime[0] = false;prime[1] = false ;
for (int i = 2; i * i < N; i++) {if (prime[i]) {
for (int j = i * i; j < N; j += i) {prime[j] = false ;}}}
for (int i = 2; i < N; i++) if (prime[i])vec.push_back(i);}
void pro() { int n; cin >> n ; int ans = 1 ;
for (auto it : vec) { if (it * it > n)break ;
if (n % it == 0) { int cnt = 1 ; while (n % it == 0) {
n /= it ; cnt++ ;}ans *= cnt ;}}if (n > 1) ans *= 2 ; 
cout << ans - 1 << endl;}//// Segmented Sieve
void pro() { int n, m;cin >> n >> m; bool ara[m - n + 1] ;
memset(ara, true, sizeof(ara)); for (auto it : sve){ if (it * it > m)break; 
int fmpl = (n + it - 1) / it; fmpl *= it ;int strt = max(fmpl, it * it); 
for (int j = strt;  j <= m; j += it) { ara[j - n] = false ;}}
if (n == 1)ara[0] = false ;for (int i = n; i <= m; i++)if (ara[i - n]) cout << i << endl;}
