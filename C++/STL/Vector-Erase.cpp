#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, pos, l_pos, r_pos;
    cin >> n;
    vi v(n); 
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> pos >> l_pos >> r_pos;
    v.erase(v.begin() + pos - 1);
    v.erase(v.begin() + l_pos - 1, v.begin() + r_pos - 1);
    cout << v.size() << '\n';
    for(int i : v) cout << i << " ";
    return 0;
}
