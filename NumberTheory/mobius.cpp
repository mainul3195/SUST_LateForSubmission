void mobius() {mob[1] = 1;for (int i = 2; i < N; i++){
mob[i]--;for (int j = i + i; j < N; j += i) {mob[j] -= mob[i];}}}
