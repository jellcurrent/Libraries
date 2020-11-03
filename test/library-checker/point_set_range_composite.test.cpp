#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <cstdio>

#include "data_structure/segment_tree/basic.hpp"
#include "modulus/modint.hpp"

int main() {
  using mint = workspace::modint<998244353>;
  int n, q;
  scanf("%d%d", &n, &q);
  struct mono {
    mint c = 1, d;
    mono operator+(const mono& rhs) { return {rhs.c * c, rhs.c * d + rhs.d}; }
    mint eval(mint x) const { return c * x + d; }
  };
  segment_tree<mono> seg(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    seg[i] = {a, b};
  }
  for (int t, a, b, c; q--;) {
    scanf("%d%d%d%d", &t, &a, &b, &c);
    if (t) {
      printf("%d\n", seg.fold(a, b).eval(c));
    } else {
      seg[a] = {b, c};
    }
  }
}
