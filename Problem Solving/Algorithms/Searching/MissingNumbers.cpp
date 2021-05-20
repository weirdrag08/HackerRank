#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INFI 10e8
#define INF 10e7
#define mod 1000000007
#define sieve_limit 10e6

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli;
typedef vector<vector<bool> > vvb;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(); 
    
    unordered_map<int, int> my_map1, my_map2;
    vi v;
    int n, m, element;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> element;
        my_map1[element] += 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> element;
        my_map2[element] += 1;
    }
    
    for(auto i : my_map2){
        if(my_map1.count(i.first) == 0 || my_map1[i.first] != i.second){
           v.pb(i.first); 
        }
    }
    sort(v.begin(), v.end());
    
    for(int i : v){
        cout << i << " ";
    }
    cout << '\n';
}
