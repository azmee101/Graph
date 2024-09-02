#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class DisjoinSet{

vector<int> size, parent;

public:

    DisjoinSet(int n){

        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i = 0; i <=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){

        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionBySize(int u, int v){

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] > size[ulp_v]){

            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else if(size[ulp_v] > size[ulp_u]){

            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }

};

void solve(){
    DisjoinSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // if 3 and 7 belong to the same componenets or not

    if(ds.findUPar(3) == ds.findUPar(7)) {

        cout << "same" << '\n';
    }

    else{
        cout << "not same" << '\n';
    }

    
    ds.unionBySize(3, 7);

    // if 3 and 7 belong to the same componenets or not

    if(ds.findUPar(3) == ds.findUPar(7)) {

        cout << "same" << '\n';
    }

    else{
        cout << "not same" << '\n';
    }
    
    return;
}

int32_t main()
{
    NEED_FOR_SPEED;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}