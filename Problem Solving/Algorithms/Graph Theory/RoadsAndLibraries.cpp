#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<ll, ll> pl;

class Graph{
    unordered_map<int, list<pl> > gmap;

public:
    void addEdge(ll src , ll dest, ll weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

private:
    ll construct_helper(ll src, vb &visited){
        ll count = 0;
        queue<ll> q;
        q.push(src);
        visited[src] = true;
        count++;
        while(!q.empty()){
            ll front = q.front();
            q.pop();
            for(auto neighbour : gmap[front]){
                if(!visited[neighbour.first]){
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                    count++;
                }
            }
        }
        return count;
    }

public:
    ll construct(ll libraries, ll roads, ll c_lib, ll c_roads){
        vb visited(libraries + 1, false);
        ll total_cost = 0;
        for(ll i = 1; i <= libraries; i++){
            if(!visited[i]){
               ll count = construct_helper(i, visited);
               total_cost += c_lib + (c_roads * (count - 1));
            }
        }
        return total_cost;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        Graph g;
        ll libraries, roads, c_lib, c_road, u, v, total_cost = 0;
        cin >> libraries >> roads >> c_lib >> c_road;

        for(ll j = 0; j < roads; j++){
            cin >> u >> v;
            g.addEdge(u, v, INFI);
        }
        if (c_road >= c_lib){
            cout << (c_lib * libraries) << '\n';
            continue;
        }

        total_cost = g.construct(libraries, roads, c_lib, c_road);
        cout << total_cost << '\n';
    }
}
