#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class DisJoinSet{

public:
    vector<int> rank, parent;

    DisJoinSet(int n){
        
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){

        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionByRank(int u, int v){

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v){

            // stay in the same graph
            
            return;
        }

        if(rank[ulp_u] > rank[ulp_v]){

            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]){

            parent[ulp_u] = ulp_v;
        }
        else{

            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }

    }

};

void solve(){
    DisJoinSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // if 3 and 7 belong to the same componenets or not

    if(ds.findUPar(3) == ds.findUPar(7)) {

        cout << "same" << '\n';
    }

    else{
        cout << "not same" << '\n';
    }

    ds.unionByRank(3, 7);
    
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
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}