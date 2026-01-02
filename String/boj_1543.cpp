#include <bits/stdc++.h>
using namespace std;

int search(string &doc, string &target_str){
    int result = 0;

    int target_size = target_str.size();

    for(int i = 0; i < doc.size();){
        if(doc.substr(i, target_size) == target_str){
            result++;
            i = i + target_size;
        }
        else{
            i++;
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string doc;
    string target_str;

    getline(cin, doc);
    getline(cin, target_str);

    cout << search(doc, target_str) << '\n';

    return 0;
}