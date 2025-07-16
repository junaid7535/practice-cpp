#include <iostream>
#include <vector>
#include<unordered_set>
#include<queue>
#include<map>
#include<stack>
using namespace std;

int di = 2;
int dj = 3;
int max_length = -1;

void backtrack(vector<vector<int>>mat,int i,int j,vector<vector<bool>>&visited,int currlen){
    int m = mat.size();
    int n = mat[0].size();

    if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || mat[i][j] == 0) return;

    if(i == di && j == dj){
        max_length = max(max_length,currlen);
        return;
    }
    visited[i][j] = true;

    backtrack(mat,i,j-1,visited,currlen+1);
    backtrack(mat,i,j+1,visited,currlen+1);

    backtrack(mat,i-1,j,visited,currlen+1);
    backtrack(mat,i+1,j,visited,currlen+1);

    visited[i][j] = false;
}

int main(){
    vector<vector<int>> matrix(3,vector<int>(4));

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cin>>matrix[i][j];
        }
    }

    vector<vector<bool>>visited(matrix.size(),vector<bool>(matrix[0].size(),false));

    backtrack(matrix,0,0,visited,0);

    cout << endl;
    cout << max_length << endl;
}