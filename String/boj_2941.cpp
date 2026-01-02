#include <bits/stdc++.h>
using namespace std;

int search(string &doc){
    int result = 0;

    for(int i = 0; i < doc.size();){
        switch(doc[i]){
            case 'c':
                if(doc.substr(i, 2) == "c=" || doc.substr(i, 2) == "c-"){
                    result++;
                    i = i + 2;
                    break;
                }
                else{
                    result++;
                    i++;
                    break;
                }
            case 'd':
                if(doc.substr(i, 3) == "dz="){
                    result++;
                    i = i + 3;
                    break;
                }
                else if(doc.substr(i, 2) == "d-"){
                    result++;
                    i = i + 2;
                    break;
                }
                else{
                    result++;
                    i++;
                    break;
                }
            case 'l':
                if(doc.substr(i, 2) == "lj"){
                    result++;
                    i = i + 2;
                    break;
                }
                else{
                    result++;
                    i++;
                    break;
                }
            case 'n':
                if(doc.substr(i, 2) == "nj"){
                    result++;
                    i = i + 2;
                    break;
                }
                else{
                    result++;
                    i++;
                    break;
                }
            case 's':
                if(doc.substr(i, 2) == "s="){
                    result++;
                    i = i + 2;
                    break;
                }
                else{
                    result++;
                    i++;
                    break;
                }
            case 'z':
                if(doc.substr(i, 2) == "z="){
                    result++;
                    i = i + 2;
                    break;
                }
                else{
                    result++;
                    i++;
                    break;
                }
            default:
                result++;
                i++;
                break;
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string doc;
    
    getline(cin, doc);

    cout << search(doc) << '\n';

    return 0;
}