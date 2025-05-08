void SOS_DP(){for(int i = 0; i<(1<<N); ++i)F[i] = A[i];
for(int i = 0;i < N; ++i)for(int mask = 0; mask < (1<<N); ++mask){
if(mask & (1<<i))F[mask] += F[mask^(1<<i)];}}
//Istiak
const ll MLOG = 20; const ll MAXN = (1 << MLOG); ll dp[sz + 10], fre[sz + 10], mp[sz + 10];
// forward1: Propagates values from subsets to their supersets
void forward1() { for (int bit = 0; bit < MLOG; ++bit) { for (int i = 0; i < MAXN; ++i) { if (i & (1 << bit)) { dp[i] += dp[i ^ (1 << bit)]; } } } }
// backward1: Reverses the effect of forward1 by removing contributions from supersets.This is used when dp[i] contains info about all subsets of i, and we want to isolate the info for only i.
void backward1() { for (int bit = 0; bit < MLOG; ++bit) { for (int i = MAXN - 1; i >= 0; --i) { if (i & (1 << bit)) { dp[i] -= dp[i ^ (1 << bit)]; } } } }
// forward2: Propagates values from supersets to their subsets
void forward2() { for (int bit = 0; bit < MLOG; ++bit) { for (int i = MAXN - 1; i >= 0; --i) { if (i & (1 << bit)) { dp[i ^ (1 << bit)] += dp[i]; } } } }
// backward2: Reverses the effect of forward2 by removing contributions from subsets.This is used when dp[i] contains info about all supersets of i, and we want to isolate the info for only i.
void backward2() { for (int bit = 0; bit < MLOG; ++bit) { for (int i = 0; i < MAXN; ++i) { if (i & (1 << bit)) { dp[i ^ (1 << bit)] -= dp[i]; } } } }
memset(dp, 0, sizeof(dp)); memset(fre, 0, sizeof(fre)); memset(mp, 0, sizeof(mp));
