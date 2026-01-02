#include <bits/stdc++.h>
using namespace std;

// size, substr, replace, erase, insert, find
int main(){
    string s = "hello";
    s += " BKD!";
    cout << s.size() << '\n'; // 10
    cout << s.substr(2, 3) << '\n'; // llo
    s.replace(6, 4, "guys"); // hello guys
    cout << s << '\n';
    int it = s.find("guys"); // 6
    s.replace(it, 4, "everyone"); // hello everyone
    cout << s << '\n';
    s.erase(7, 6); // hello ee
    cout << s << '\n';
    s[6] = 'm';
    cout << s << '\n';
    s.insert(0, "say "); // say hello me
    cout << s << '\n';
    if(s.find("to") == string::npos){
        cout << "'to' is not in string 's'\n";
    }
    return 0;
}