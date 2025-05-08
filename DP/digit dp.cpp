const int N=20;int a[N];
ll dp[N][11][2][2];   // digit dp te amar number generate hoy emne : 0, 01, 02, 03, 04, 05.....066,0667
ll getsum(int pos, int dig,  int n, bool ok, bool other){if(pos>n){return 1;}
ll &R = dp[pos][dig][ok][other];if(R!=-1)return R;int maxdigit = 9;if(!ok)
maxdigit = a[pos];ll res=0;for(int i=0 ; i<=maxdigit ; i++){if(dig == i && other)
continue;if(i>0)other=1;if(i<maxdigit || ok)res+=getsum(pos+1, i, n, true, other);else
res+=getsum(pos+1, i, n, false, other);}return R = res;}void Solve(){string l, r;
cin>>l>>r;int n = r.size();r='*'+r;for(int i=0 ; i<=n ; i++){a[i]=r[i]-'0';}  
memset(dp, -1, sizeof(dp));ll sumr = getsum(1, -1 , n, 0, 0);}
