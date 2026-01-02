#include <bits/stdc++.h>
using namespace std;

/**
 * a b c d e f g h i j k l m n o p q r s t u v w x y z
 */

int main(){
    vector<int> alphabet(26, 0);
    string str;
    cin >> str;
    // ascii: 0x61 ~ 0x7a
    for(auto i : str){
        alphabet[i-0x61]++;
    }

    for(auto i : alphabet){
        cout << i << " ";
    }


    return 0;
}