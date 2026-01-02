#include <bits/stdc++.h>

using namespace std;

vector<int> merge_sort(vector<int> &arr_1, vector<int> &arr_2, int a, int b){
    int i = 0, j = 0;
    vector<int> result_arr(a+b,0);

    int limits = std::numeric_limits<int>::max();
    arr_1.push_back(limits);
    arr_2.push_back(limits);

    for(int k = 0; k < a+b; ++k){
        if(arr_1[i] < arr_2[j]){
            result_arr[k] = arr_1[i];
            i++;
        }
        else{
            result_arr[k] = arr_2[j];
            j++;
        }
    }

    return result_arr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    vector<int> arr_1(a, 0);
    vector<int> arr_2(b, 0);

    for(int i = 0; i < a; i++){
        cin >> arr_1[i];
    }

    for(int i = 0; i < b; i++){
        cin >> arr_2[i];
    }

    vector<int> result = merge_sort(arr_1, arr_2, a, b);

    for(const auto &i : result){
        cout<< i << " ";
    }

    return 0;
}