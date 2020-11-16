#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <cstdio>

#include "src/data_structure/convex_hull_trick/Li_Chao_tree.hpp"

int main() {
  using i64 = int64_t;
  int n, q;
  scanf("%d%d", &n, &q);
  Li_Chao_tree<i64> cht(-1e9, 1e9);
  while (n--) {
    int l, r, a;
    i64 b;
    scanf("%d%d%d%lld", &l, &r, &a, &b);
    cht.insert(a, b, l, r);
  }
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t) {
      int p;
      scanf("%d", &p);
      i64 ans = cht.get(p);
      if (ans == std::numeric_limits<i64>::max())
        puts("INFINITY");
      else
        printf("%lld\n", ans);
    } else {
      int l, r, a;
      i64 b;
      scanf("%d%d%d%lld", &l, &r, &a, &b);
      cht.insert(a, b, l, r);
    }
  }
}
