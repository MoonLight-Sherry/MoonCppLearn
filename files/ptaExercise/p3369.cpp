#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
  int lc, rc, p, v, size, ctr;

  inline int& child(int _v) { return (_v <= v) ? lc : rc; }

  inline int& which(int b) { return b ? rc : lc; }
};

struct SplayTree {
  Node node[100010];
  int l, root;

  inline int create_node(int p, int v) {
    ++l;
    node[l].p = p;
    node[l].v = v;
    node[l].lc = 0;
    node[l].rc = 0;
    node[l].size = 1;
    node[l].ctr = 1;
    return l;
  }

  inline void del_node(int n) {
    node[n].p = 0;
    node[n].v = 0;
    node[n].lc = 0;
    node[n].rc = 0;
    node[n].size = 0;
    node[n].ctr = 0;
  }

  inline bool relation(int n) {
    return n == node[node[n].p].rc;
  }

  inline void rotate(int n) {
    int p = node[n].p, m = relation(n);
    node[p].which(m) = node[n].which(!m);
    if (node[n].which(!m)) {
      node[node[n].which(!m)].p = p;
    }
    node[n].p = node[p].p;
    if (p == root) {
      root = n;
    } else {
      node[node[p].p].child(node[p].v) = n;
    }
    node[n].which(!m) = p;
    node[p].p = n;
    node[p].size = node[node[p].lc].size + node[node[p].rc].size + node[p].ctr;
    node[n].size = node[node[n].lc].size + node[node[n].rc].size + node[n].ctr;
  }

  void splay(int n, int p = 0) {
    while (node[n].p != p) {
      if (node[node[n].p].p != p) {
        if (relation(n) == relation(node[n].p)) {
          rotate(node[n].p);
        } else {
          rotate(n);
        }
      }
      rotate(n);
    }
  }

  int find(int v) {
    int n = root;
    while (node[n].v != v && node[n].child(v)) {
      n = node[n].child(v);
    }
    splay(n);
    return n;
  }

  inline int rank(int v) {
    int n = find(v);
    return node[node[n].lc].size + 1;
  }

  int kth(int k) {
    if (k > node[root].size) { return -1; }
    int n = root;
    while (!(node[node[n].lc].size + 1 <= k && node[node[n].lc].size + node[n].ctr >= k)) {
      if (node[node[n].lc].size + 1 > k) {
        n = node[n].lc;
      } else {
        k -= node[node[n].lc].size + node[n].ctr;
        n = node[n].rc;
      }
    }
    splay(n);
    return node[n].v;
  }

  int prev(int v) {
    int n = find(v);
    if (node[root].v < v) { return root; }
    if (!node[n].lc) return 0;
    n = node[n].lc;
    while (node[n].rc) {
      n = node[n].rc;
    }
    return n;
  }

  int succ(int v) {
    int n = find(v);
    if (node[root].v > v) { return root; }
    if (!node[n].rc) return 0;
    n = node[n].rc;
    while (node[n].lc) {
      n = node[n].lc;
    }
    return n;
  }

  inline void insert(int v) {
    int n = root, p = 0;
    while (n && node[n].v != v) {
      p = n;
      n = node[n].child(v);
    }
    if (n) {
      node[n].ctr++;
    } else {
      n = create_node(p, v);
      if (p) {
        node[p].child(v) = n;
      } else {
        root = n;
      }
    }
    splay(n);
  }

  void del(int v) {
    int n = find(v), p = prev(v), s = succ(v);
    splay(p);
    splay(s, p);
    node[s].size--;
    if (node[n].ctr > 1) {
      node[n].ctr--;
      node[n].size--;
    } else {
      node[s].lc = 0;
      del_node(n);
    }
  }
};

int n;
SplayTree t;

int main() {
  scanf("%d", &n);
  t.insert(0x80000000);
  t.insert(0x7fffffff);
  for (int i = 1; i <= n; i++) {
    int cmd, x;
    scanf("%d %d", &cmd, &x);
    switch (cmd) {
    case 1: t.insert(x); break;
    case 2: t.del(x); break;
    case 3: printf("%d\n", t.rank(x) - 1); break;
    case 4: printf("%d\n", t.kth(x + 1)); break;
    case 5: printf("%d\n", t.node[t.prev(x)].v); break;
    case 6: printf("%d\n", t.node[t.succ(x)].v); break;
    }
  }
  return 0;
}