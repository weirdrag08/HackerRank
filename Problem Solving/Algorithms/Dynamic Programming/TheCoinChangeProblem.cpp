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
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<long long> vll;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vll v(m), dp(n + 1, 0);
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }
    dp[0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 1; j <= n; j++){
            if(j >= v[i]){
                dp[j] += dp[j - v[i]];
            }
        }
    }
    cout << dp[n] << '\n';
}
