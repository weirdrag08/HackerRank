#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

long size = s.size();
    long count = 0;
    for(int i = 0 ; i < size ; i++){
        if(s[i] == 'a'){
            count+=1;
        }
    }
    long total_count = 0;
    long remaining_string = n % size;
    long string_repeated_number = n/size;
    total_count = string_repeated_number * count;
    for(int i  = 0 ; i < remaining_string ; i++){
        if(s[i] == 'a'){
            total_count += 1;
        }
    }
    return total_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
