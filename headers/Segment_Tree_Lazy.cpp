#include <bits/stdc++.h>
using namespace std;
#define int long long

struct segmenttree
{
#define left(node) ((node << 1) | 1)
#define right(node) (left(node) + 1)

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
        return a + b;
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
        // lazy propagation
        push(start, ending, node);

        // non overlapping case
        if (start > r || ending < l) { return 0; }

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

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for (int i = 1; i<= n; i++)
        cin >> v[i];
    segmenttree s(v);

    while (m--){
        int mode;
        cin >> mode;
        if (mode == 1){
            int a, b, u;
            cin >> a >> b >> u;
            s.update(a, b, u);
        }
        else {
            int a;
            cin >> a;
            cout << s.query(a, a) << endl;
        }
    }
}