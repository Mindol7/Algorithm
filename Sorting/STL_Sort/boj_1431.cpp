#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &str1, const string &str2){
    if(str1.length() != str2.length()){
        return str1.length() < str2.length();
    }
    else{ // str1.length() == str2.length()
        int str1_sum = 0, str2_sum = 0;
        for(int i = 0; i < str1.length(); ++i){
            if(str1[i] >= 0x30 && str1[i] <=0x39){
                str1_sum += str1[i] - '0';
            }
        }
        for(int i = 0; i < str2.length(); ++i){
            if(str2[i] >= 0x30 && str2[i] <=0x39){
                str2_sum += str2[i] - '0';
            }
        }

        if(str1_sum != str2_sum) return str1_sum < str2_sum;
        else{
            return str1 < str2;
        }
    }
}

void SORT(vector<string> &str, int n){
    sort(str.begin(), str.end(), cmp);
}

int main(){
    int n;
    cin >> n;
    vector<string> str;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        str.push_back(s);
    }

    SORT(str, n);

    for(auto &at : str){
        cout << at << endl;
    }
    return 0;
}