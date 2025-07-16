#include <iostream>
#include <vector>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;

vector<vector<int>>result;

int main(){
    vector<int>nums{1,2,3,4,5,6,7,8};

    int num = 3;

    //int idx = upper_bound(nums.begin(),nums.end(),num) - nums.begin();

    auto func = [](int a){
        cout << "a" << endl;
    };

    func(2);

    auto custom = [](pair<int,int>a,pair<int,int>b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    };

    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(custom)>pq(custom);

    pq.push({5,10});
    pq.push({3,20});
    pq.push({3,15});
    pq.push({1,5});

    vector<pair<int,int>>nums1{{5,10},{3,20},{3,15},{1,5}};

    sort(nums1.begin(),nums1.end(),[](pair<int,int>a,pair<int,int>b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    for(int i = 0; i < nums1.size(); i++){
        //cout << nums1[i].first << " " << nums1[i].second << endl;
    }

    vector<int>nums2{4,8,5,2,25};

    stack<int>stack;

    for(int i = 0; i < nums2.size(); i++){
        while(!stack.empty() && nums2[i] < nums2[stack.top()]){
            stack.pop();
        }
        //stack.push(i);
    }

    while(!stack.empty()){
        //cout << nums2[stack.top()] << " ";
        stack.pop();
    }
    
    // maintain monotonic decreasing stack(next greater element)

    vector<int>result(nums2.size());

    for(int i = nums2.size()-1; i >= 0; i--){
        while(!stack.empty() && nums2[stack.top()] < nums2[i]){
            stack.pop();
        }

        if(stack.empty()){
            result[i] = -1;
        }
        else{
            result[i] = nums2[stack.top()];
        }
        stack.push(i);
    }

    for(int i = 0; i < result.size(); i++){
        //cout << result[i] << " ";
    }

    // maintain monotonic increasing stack(next smaller element)

    while(!stack.empty()) stack.pop();

    for(int i = nums2.size()-1; i >= 0; i--){
        while(!stack.empty() && nums2[i] < nums2[stack.top()]){
            stack.pop();
        }
        if(stack.empty()){
            result[i] = -1;
        }
        else{
            result[i] = nums2[stack.top()];
        }

        stack.push(i);
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] <<  " " ;
    }

    //cout << idx;
    
}