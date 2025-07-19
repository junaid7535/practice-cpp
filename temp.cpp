#include<iostream>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;

int main(){
    string s = "geeksforgeeks";
    int n = s.size();
    vector<int>consecutive(s.size());
    consecutive[0] = 0;

    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]){
            if(consecutive[i-1] > 0){
                consecutive[i] = consecutive[i-1] + 1;
            }
            else{
                consecutive[i] = 2;
            }
        }
        else{
            consecutive[i] = 0;
        }
    }
    int k = 2;
    for(int i = 0; i < n; i++){
            if(consecutive[i] == k){
                cout << s.substr(i-k+1,k);
                s.erase(i - k+1,k);
            }
        }
        //cout << s;
}