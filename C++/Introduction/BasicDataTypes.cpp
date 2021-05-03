#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
   int integer;
   long long_one;
   char ch;
   float small_decimal;
   double big_decimal;

   cin >> integer >> long_one >> ch >> small_decimal >> big_decimal;
   cout << integer << endl;
   cout << long_one << endl;
   printf("%c \n%.3f \n%.9f \n" , ch , small_decimal , big_decimal);

    return 0;
}
