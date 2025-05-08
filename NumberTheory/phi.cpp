// for n<=1e6 by nloglogn 
void phi(int n){vector<int>phi(n+1) ;
for(int i = 0; i <= n; i++)phi[i] = i;for(int i = 2; i <=n; i++){
if(phi[i] == i){for(int j = i; j <= n; j += i){
phi[j] -= phi[j]/i ;}}}}
// for single number by sqrt(n)
int phi(int n){int res = n ;for(int i = 2; i * i <= n ; i++){
if(n % i == 0){while(n % i == 0) n /= i ;res -= res / i ;}}
if(n > 1) res -= res / n ;return res ;}
