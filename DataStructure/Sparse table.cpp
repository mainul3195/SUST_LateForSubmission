int Table[N][22], a[N];
void Build(int n){
for (int i = 1 ; i <= n ; i++)Table[i][0] = a[i];
for (int k = 1 ; k < 22 ; k++){
for (int i = 1 ; i + (1 << k) - 1 <= n ; i++)Table[i][k] = min(Table[i][k - 1], Table[i + (1 << (k - 1))][k - 1]);}}
int Query(int l, int r){int k = log2(r - l + 1);return min(Table[l][k], Table[r - (1 << k) + 1][k]);}
