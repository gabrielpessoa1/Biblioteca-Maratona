int n, t[2 * ms];

void build() {
  for(int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1]; // Merge
}

void update(int v, int l, int r) {
  for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    if(l&1) t[l++] += v; // Merge
    if(r&1) t[--r] += v; // Merge
  }
}

int query(int p) {
  int res = 0;
  for(p += n; p > 0; p >>= 1) res += t[p]; // Merge
  return res;
}

void push() { // push modifications to leafs
  for(int i = 1; i < n; i++) {
    t[i<<1] += t[i]; // Merge
    t[i<<1|1] += t[i]; // Merge
    t[i] = 0;
  }
}
