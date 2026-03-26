/*
        আমার অমনোযোগী ক্লাসরুম... আমার মগজে নষ্ট ধুম...
        আমার বাহিরে বুদ্ধ, ভেতরে হিটলার... লাশের মোড়কে ঘুম :)
*/
 
#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  // fast IO! but only when online_judge
#define debug 0
#else
#define fast ;
#define debug 1
#endif
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}
 
// some typedefs for my convenience
#define int long long int
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
// some speedup macros
#define print(str) cout << str << '\n'
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for (__typeof(end)i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define all(v) v.begin(), v.end()
 
 
void solve(int cases);
int32_t main()
{
    fast
    int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}
 
// SOLVE STARTS HERE
struct segmenttree
{
#define left(node) ((node << 1) | 1)
#define right(node) (left(node) + 1)
#define init_data INT32_MAX
 
    int n; // size of the input array
    vector<int> st, lazy;
 
    segmenttree(vector<int> &v) // pass the main array to the constructor
    {
        n = v.size();
        st.resize(4 * n, 0); // max 4*n size needed for segment tree array
        lazy.resize(4 * n, 0);
        build(0, n - 1, 0, v);
    }
 
    inline int combine(int a, int b) {
        return min(a, b);
    }
 
    void build(int start, int ending, int node, vector<int> &v)
    // start and ending denotes the range (0 based indexes of the main array) the segment is covering
    // (int)log2(ending-start+1) will denote the height of the node (height of leaves are zero)
    {
        // leaf node base case
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }
 
        int mid = (start + ending) / 2;
        build(start, mid, left(node), v); // left subtree is (start,mid)
        build(mid + 1, ending, right(node), v); // right subtree is (mid+1,ending)
 
        // the operation statement
        st[node] = combine(st[left(node)], st[right(node)]);
    }
 
    inline void push(int start, int ending, int node) { // lazy propagation
        if (lazy[node] == 0) return; // no pending updates
 
        st[node] += lazy[node] * (ending - start + 1); // update the segment tree node
        if (start != ending) {
            // propagate the updated value
            lazy[left(node)] += lazy[node];
            lazy[right(node)] += lazy[node];
        }
        lazy[node] = 0;
    }
 
    int query(int l, int r){ return query(0, n - 1, l, r, 0); }	// main function will call this overload
    int query(int start, int ending, int l, int r, int node)
    {
        if (r < l) return INTMAX_MAX;
 
        // lazy propagation
        push(start, ending, node);
 
        // non overlapping case
        if (start > r || ending < l) { return init_data; }
 
        // complete overlap
        if (start >= l && ending <= r){ return st[node]; }
 
        // partial case
        int mid = (start + ending) / 2;
        int q1 = query(start, mid, l, r, left(node));
        int q2 = query(mid + 1, ending, l, r, right(node));
        return combine(q1, q2);
    }
 
    // single node update
    void update(int x, int y) { update(0, n - 1, 0, x, y); } // main function will call this overload
    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] = value;
            return;
        }
 
        int mid = (start + ending) / 2;
        if (index <= mid) update(start, mid, left(node), index, value); // left subtree
        else update(mid + 1, ending, right(node), index, value); // right
 
        // the operation statement
        st[node] = combine(st[left(node)], st[right(node)]);
    }
 
    // range update
    // increase x from index l to r
    void update(int l, int r, int x) { update(0, n - 1, 0, l, r, x); } // overload for main function
    void update(int start, int ending, int node, int l, int r, int value) {
        // lazy propagation
        push(start, ending, node);
 
        // non overlapping case
        if (start > r || ending < l) return;
 
        // complete overlap
        if (start >= l && ending <= r) {
            lazy[node] = value;
            push(start, ending, node);
            return;
        }
 
        // partial case
        int mid = (start + ending) / 2;
        update(start, mid, left(node), l, r, value);
        update(mid + 1, ending, right(node), l, r, value);
        st[node] = combine(st[left(node)], st[right(node)]);
    }
};
 
 
bool pred(int x, int q, vi &pref, segmenttree &st)
{
    if (!x) return true;
    int n = pref.size() - 1;
    loop(i,1,n+1){
        int last = i + x - 1;
        if (last > n) break;
        if (st.query(i, last) - pref[i-1] + q >= 0) return true;
    }
    return false;
}
 
void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0;
    int in;
    cin >> n >> q;
    vi pref(n+1);
    vi indices;
    loop(i,0,n){
        cin >> in;
        pref[i+1] = in + pref[i];
    }
    segmenttree st(pref);
 
    int hi = n, lo = 0;
    while (hi >= lo){
        int mid = (hi + lo)/2;
        if (pred(mid, q, pref, st)) out = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    if (!out) print(-1);
    else{
        loop(i,1,n+1){
            int last = i + out - 1;
            if (last > n) break;
            if (st.query(i, last) - pref[i-1] + q >= 0){
                print (i << " " << last);
                break;
            }
        }
    }
}
    