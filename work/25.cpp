#include <bits/stdc++.h>
using namespace std;
template<typename T>struct SegTree{T e=0;int N;vector<T>v;SegTree(int N):N(N),
v(N<<1,e){};T operator[](int i){return v[i+N];}void build(vector<T>A){for(
int i=0;i<N;i++)v[i+N]=A[i];for(int i=N-1;i>=0;i--)bind(v[i],v[i<<1],v[i<<1|1]);}
void set(int i,T x){v[i+=N]=x;while(i>>=1)bind(v[i],v[i<<1],v[i<<1|1]);}T fold(
int l,int r){T vl=e,vr=e;for(l+=N,r+=N;l<r;l>>=1,r>>=1){if(l&1)pick(vl,vl,v[l++]);
if(r&1)pick(vr,v[--r],vr);}return pick(vl, vl, vr);}inline void bind(T &n,T l,T r)
{n=l+r;}inline T pick(T &n,T l,T r){n=l+r;return n;}};
int main() {
    int N = 8;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }
    SegTree<int> seg(N);
    seg.build(A);
    seg.set(2, 5);
    cout << "[0, 8) " << seg.fold(0, N) << endl;
    cout << "[3, 6) " << seg.fold(3, 6) << endl;
}
