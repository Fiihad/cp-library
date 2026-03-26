// 29-05-2023 05:19
#include <bits/stdc++.h>
using namespace std;

class BST {
    struct node {
        int value;
        node *left, *right;
        node(int x) { value = x; left = right = NULL; }
    };

    node *root;

public:
    BST() { root = NULL; }
    ~BST() { destruct(&root); }

    void insert(int x){ insert(x, &root); } // overload to call in main function
    void insert(int x, node **i){ // the original version
        if (*i == NULL){
            try { *i = new node(x); }
            catch(exception e) { cout << "Memory Allocation Error: " << e.what() << endl; return; }
        }
        else if (x < (*i)->value) insert(x, &((*i)->left));
        else insert(x, &((*i)->right));
    }

    void post_traverse() { post_traverse(root); cout << endl; }
    void post_traverse(node *i){
        if (i == NULL) return;

        post_traverse(i->right);
        post_traverse(i->left);
        cout << i->value << endl;
    }

    void destruct(node **i){ // recursive destructor function
        if (*i == NULL) return;
        destruct(&((*i)->left));
        destruct(&((*i)->right));
        delete *i;
    }
};

int main (void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);

    BST b;
    for (int i=n-1; i>=0; i--) b.insert(v[i]);
    b.post_traverse();
    return 0;
}