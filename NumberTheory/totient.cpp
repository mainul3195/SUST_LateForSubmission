#include<bits/stdc++.h>using namespace std ;
const double pi = 2 * acos (0.0) ;const int N=5000006 ;
const int INF=INT_MAX;const int mod=1000000007 ;
vector<int>phi(N,0) ;void totient_seive(){
for(int i=1; i<N; i++)phi[i]=i;for(int i=2; i<N; i++){
if(phi[i]==i) { for(int j=i; j<N; j+=i) {
phi[j]= ( phi[j] - (phi[j]/i) ) ;}}}}
//FOR ANY SINGLE NUMBER ___ CALCULTAING THE VALUE OF PHI USING SQRT COMPLEXITY
const int N=1000009 ;const int INF=INT_MAX ;const int mod=1000000007 ;
int sqrt_phi(int n){ int ans=n ; for(int i=2; i*i<=n; i++){
if(n%i==0){while(n%i==0)n/=i ;ans-=(ans/i) ;}} 
if(n>1) ans-=(ans/n) ;return ans ;}
//CALCULATING PHI VALUE USING SUM OF PHI....
//SUM OF TOTAIENT VALUE FOR ALL DIVISOR OF N IS EQUAL TO N
// PHI(10)+PHI(5)+PHI(2)+PHI(1)
//= 4 + 4 + 1 + 1 
// 10
const int N=10000007 ;const int INF=INT_MAX;const int mod=1000000007 ;
vector<int>phi(N,0) ;void calcphi(){phi[0]=0 ;phi[1]=1 ;
for(int i=2; i<N; i++) phi[i]=i-1 ; 
//(loop er modde 1 divisor hisabe ani nai.....tai 1 er contribution bad)
for(int i=2; i<N; i++){ for(int j=2*i; j<N; j+=i) {phi[j]-=phi[i] ;}}}


