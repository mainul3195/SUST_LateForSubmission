ll Next_smaller[N + 2];ll Prev_smaller[N + 2];
void NEXTSMALLER(){stack<int>st;
for (int i = 1; i <= n; i++){if (st.empty()){st.push(i);}
else{while (!st.empty() && a[st.top()] > a[i]){Next_smaller[st.top()] = i;st.pop();}st.push(i);}}
while (!st.empty()){Next_smaller[st.top()] = n + 1;st.pop();}}
void PREVSMALLER(){stack<int>st;
for (int i = n; i >= 1; i--){if (st.empty()){st.push(i);}
else{while (!st.empty() && a[st.top()] > a[i]){Prev_smaller[st.top()] = i;st.pop();}st.push(i);}}
while (!st.empty()){Prev_smaller[st.top()] = 0;st.pop();}}
//priority_queue<int,vector<int>, greater<int> >pq;
