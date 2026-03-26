/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
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

// some typedefs for my convenience
#define int long long int
#define pii pair<int, int>
#define vi vector<int>
#define si set<int>
#define mi map<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define print(str) cout << str << endl
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))
#define all(v) v.begin(), v.end()

// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}


void solve(int cases);
int32_t main()
{
    fast
    int total_cases = 1;
    // cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
struct segmenttree
{
#define left(node) ((node << 1) | 1)
#define right(node) (left(node) + 1)

    int n; // size of the input array
    vector<int> st, lazy, lazy2;

    segmenttree(vector<int> &v) // pass the main array to the constructor
    {
        n = v.size();
        st.resize(4 * n, 0); // max 4*n size needed for segment tree array
        lazy.resize(4 * n, 0);
        lazy2.resize(4 * n, -1);
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
        if (lazy[node] == 0 && lazy2[node] == -1) return; // no pending updates

        st[node] += lazy[node] * (ending - start + 1); // update the segment tree node
        if (lazy2[node] != -1) st[node] = lazy2[node] * (ending - start + 1);
        if (start != ending) {
            // propagate the updated value
            lazy[left(node)] += lazy[node];
            lazy[right(node)] += lazy[node];
            if (lazy2[node] != -1) lazy2[left(node)] = lazy2[node],
                lazy2[right(node)] = lazy2[node];
        }
        lazy[node] = 0;
        lazy2[node] = -1;
    }

    int query(int l, int r){ return query(0, n - 1, l, r, 0); }	// main function will call this overload
    int query(int start, int ending, int l, int r, int node)
    {
        push(start, ending, node);
        // non overlapping case
        if (start > r || ending < l) { return 0; }

        // lazy propagation

        // complete overlap
        if (start >= l && ending <= r){ return st[node]; }

        // partial case
        int mid = (start + ending) / 2;
        int q1 = query(start, mid, l, r, left(node));
        int q2 = query(mid + 1, ending, l, r, right(node));
        return combine(q1, q2);
    }

    // range update
    // increase x from index l to r
    void update(int l, int r, int x, int mode) { update(0, n - 1, 0, l, r, x, mode); } // overload for main function
    void update(int start, int ending, int node, int l, int r, int value, int mode) {
        // bug(start, ending, node, l, r);
        // lazy propagation
        push(start, ending, node);

        // non overlapping case
        if (start > r || ending < l) return;


        // complete overlap
        if (start >= l && ending <= r) {
            // int mid = (start + ending) / 2;
            // if (start != ending){
            //     update(start, mid, left(node), l, r, value, mode);
            //     update(mid + 1, ending, right(node), l, r, value, mode);
            //     st[node] = combine(st[left(node)], st[right(node)]);
            // }
            up_push(start, ending, node);
            if (mode == 1) lazy[node] = value;
            else lazy2[node] = value;
            push(start, ending, node);
            return;
        }

        // partial case
        int mid = (start + ending) / 2;
        update(start, mid, left(node), l, r, value, mode);
        update(mid + 1, ending, right(node), l, r, value, mode);
        st[node] = combine(st[left(node)], st[right(node)]);
    }

    void up_push(int start, int ending, int node){
        push(start, ending, node);

        if (start != ending) {
            int mid = (start + ending) / 2;
            up_push(start, mid, left(node));
            up_push(mid + 1, ending, right(node));
        }
    }
};

void solve(int cases)
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
        if (mode == 1 || mode == 2){
            int a, b, u;
            cin >> a >> b >> u;
            s.update(a, b, u, mode);
        }
        else if (mode == 3) {
            int a, b;
            cin >> a >> b;
            cout << s.query(a, b) << endl;
        }
        #define printp(p) cout << '(' << p.first << ',' << gap << p.second << ')' << endl;
        #define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
        #define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
        // printx(s.st);
        // printx(s.lazy);
        // printx(s.lazy2);
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        27-06-2023 16:52
*/