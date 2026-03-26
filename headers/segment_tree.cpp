#include <bits/stdc++.h>

using namespace std;

// summation
struct segmenttree
{
	int n;			// size of the input array
	vector<int> st; // segment tree array

	segmenttree(vector<int> &v) // pass the main array to the constructor
	{
		n = v.size();
		st.resize(4 * n, 0); // max 4*n size needed for segment tree array
		build(0, n - 1, 0, v);
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
		// left subtree is (start,mid)
		build(start, mid, 2 * node + 1, v);
		// right subtree is (mid+1,ending)
		build(mid + 1, ending, 2 * node + 2, v);

		// the operation statement
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}

	int query(int l, int r){ return query(0, n - 1, l, r, 0); }	// main function will call this overload
	int query(int start, int ending, int l, int r, int node)
	{
		// non overlapping case
		if (start > r || ending < l) { return 0; }

		// complete overlap
		if (start >= l && ending <= r){ return st[node]; }

		// partial case
		int mid = (start + ending) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

		// the operation statement
		return q1 + q2;
	}

	void update(int x, int y) { update(0, n - 1, 0, x, y); }	// main function will call this overload
	void update(int start, int ending, int node, int index, int value)
	{
		// base case
		if (start == ending)
		{
			st[node] = value;
			return;
		}

		int mid = (start + ending) / 2;
		if (index <= mid) update(start, mid, 2 * node + 1, index, value); // left subtree
		else update(mid + 1, ending, 2 * node + 2, index, value); // right

		// the operation statement
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}
};

int main()
{
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

	segmenttree tree(v);

	cout << tree.query(0, 4) << '\n';

	tree.update(4, 10);

	cout << tree.query(2, 6) << '\n';

	tree.update(2, 20);

	cout << tree.query(0, 4) << '\n';

	return 0;
}