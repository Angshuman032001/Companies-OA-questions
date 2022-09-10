```cpp
#include "bits/stdc++.h"
#define int long long

using namespace std;

template <class T> struct SegTree {
    int n; vector <T> tree;
    const T unit = 0; 
    
    T merge(T a, T b) { return (a + b); } 
    
    SegTree(int _n) { n = _n; tree.assign(4 * n, unit); }
    
    void _update(int i, int l, int r, int idx, T val) {
        if(l == r) {
            tree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(mid < idx) _update(2 * i + 1, mid + 1, r, idx, val);
        else _update(2 * i, l, mid, idx, val);
        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    T _query(int i, int l, int r, int rx, int ry) {
        if(r < rx || ry < l) return unit;
        if(rx <= l && r <= ry) return tree[i];
        int mid = (l + r) / 2;
        return merge(_query(2 * i, l, mid, rx, ry), _query(2 * i + 1, mid + 1, r, rx, ry));
    }

    void update(int idx, T val) { _update(1, 1, n, idx, val); }

    T query(int l, int r) { return _query(1, 1, n, l, r); }
};


int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<int>v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];
    SegTree<int> normalSum(n), rangeSum(n);
    for(int i = 1; i <= n; i++){
        normalSum.update(i, v[i]);
        rangeSum.update(i, i * 1ll * v[i]);
    }

    int q; cin>>q;
    int m; cin>>m;

    while(q--){
        int type, l, r; cin>>type>>l>>r;
        if(type == 1){
            normalSum.update(l, r);
            rangeSum.update(l, l * r);
        }
        else{
            int prevIndex = l - 1;
            int sum = normalSum.query(l, r);
            int ans = rangeSum.query(l, r);
            sum = sum * 1ll * prevIndex;
            ans -= sum;
            cout<<ans<<"\n";
        }
    }

}
```
