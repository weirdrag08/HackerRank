#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   int size , queries;
   cin >> size >> queries;
   int* arr[100000];
    for(int i = 0 ; i < size ; i++){
        int sub_size;
        cin >> sub_size;
        arr[i] = new int[sub_size];
        for(int j = 0 ; j < sub_size ; j++){
            cin >> arr[i][j];
        }

    }

    for(int i = 0 ; i < queries ; i++){
        int k;
        cin >> k;
        int j;
        cin >> j;
        cout << arr[k][j] << endl;
    }
    return 0;
}
