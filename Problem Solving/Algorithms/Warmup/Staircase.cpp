#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
     for(int i = 0 ; i < n ; i++){
         int spaces = n -i-1;
         for(int j = 0 ; j < spaces ; j++){
             cout << " "; 
         }
         for(int j = 0 ; j < i+1 ; j++){
             cout << "#";
         }
         cout << endl;
     } 

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
