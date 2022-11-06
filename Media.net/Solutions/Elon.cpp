#include "bits/stdc++.h"
using namespace std;
#define int long long

#ifdef LOCAL
#include "prettyprint.h"
#else 
#define deb(...)
#endif

const int mod = 1e9 + 7;
int add(int x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int mul(int x, int y) {
  int res = x * y;
  if(res >= mod) res %= mod;
  return res;
}

template<class T>
class _segment_tree_lazy_propagation{
  private:
  int NOP = 0,size;
  std::vector<T> tree;
  std::vector<int> lazy;

  public:
  _segment_tree_lazy_propagation(int size){
    this->size=size;
    tree.resize(4*size),lazy.resize(4*size);
  }
  
  void operation(int &a, int b, int len){
    if(b!=NOP)a=mul(b, len);
  }

  T merge(T left, T right){
    return add(left, right);
  }

  void build(int i, int l, int r){
    if(l==r){
      tree[i]=0;
    }
    else{
      int mid=(l+r)/2;
      build(2*i,l,mid);
      build(2*i+1,mid+1,r);
      tree[i]=merge(tree[2*i],tree[2*i+1]);
    }
  }

  void propagate(int i, int l, int r){
    if(l==r)return;
    int mid=(l+r)/2;
    operation(tree[2*i],lazy[i],mid-l+1);
    operation(tree[2*i+1],lazy[i],r-mid);
    operation(lazy[2*i],lazy[i],1);
    operation(lazy[2*i+1],lazy[i],1);
    lazy[i]=NOP;
  }

  void update(int i, int l, int r, int rx, int ry, int val){
    propagate(i, l, r);
    if(rx<=l && r<=ry){
      operation(tree[i],val,r-l+1);
      operation(lazy[i],val,1);
      return;
    }
    else if(r<rx || l>ry) return;
    else{
      int m = l+(r-l)/2;
      update(2*i, l, m, rx, ry, val);
      update(2*i+1, m+1, r, rx, ry, val);
      tree[i]=merge(tree[2*i],tree[2*i+1]);
    }
  }

  T query(int i, int l, int r, int rx, int ry){
    propagate(i,l,r);
    if(rx<=l && r<=ry) return tree[i];
    else if(r<rx || l>ry){
      return 0;
    } 
    else{
      int m = l+(r-l)/2;
      return merge(query(2*i, l, m, rx, ry), query(2*i+1, m+1, r, rx, ry));
    }
  }

  T traverse(int i, int l, int r, int val){
    if(l==r)return tree[i];
    else{
      int mid=l+(r-l)/2;
      if(tree[2*i]>=val)traverse(2*i,l,mid,val);
      else traverse(2*i+1,mid+1,r,val-tree[2*i]);
    }
  }

  void update(int l, int r, int val){
    update(1,0,size-1,l,r,val);
  }

  T query(int l, int r){
    return query(1,0,size-1,l,r);
  }

  T traverse(int val, int lx){
    return traverse(1,0,size-1,val,lx);
  }

  void build(){
    build(1,0,size-1);
  }
};


void solve() {
  int n; cin >> n;
  vector<int> XJ(n);
  XJ[0] = 1;
  for(int i = 1; i < n; i++) {
    XJ[i] = add(XJ[i - 1], (i - 2 >= 0 ? XJ[i - 2] : 0));
  }
  // after doing mod 1e9 + 7, at most 30 bits can be set in a number
  _segment_tree_lazy_propagation<int> sg(n);
  vector<int> XE(n);
  XE[0] = 1;
  sg.update(0, 0, XE[0]);
  for(int i = 0; i < n; i++) {
    int curr_ways = sg.query(i, i);
    for(int bit = 0; bit < 30; bit++) {
      if(XJ[i] & (1 << bit)) {
        // range update on i + [2^bit, 2^(bit + 1)]
        int l = min(i + (1 << bit), n - 1);
        int r = min(i + (1 << (bit + 1)), n - 1);
        sg.update(l, r, 1 + curr_ways);
      }
    }
  }

  cout << sg.query(0, n - 1)<< "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int tt = 1; tt <= t; tt++) {
    solve();
  }
}
