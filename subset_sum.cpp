#include <iostream>
#include <utility>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<array>
using namespace std;
bool subsetSumTabulation(int n, int t, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(t+1, false));
    for(int i=0; i<n; i++){
        dp[i][0] = true; // sum 0 can be achieved by empty subset
    }
    if(arr[0]<=t){
        dp[0][arr[0]] = true; // first element can form a subset with sum equal to its value
    }
    for(int ind=1; ind<n; ind++){
        for(int target=1; target<=t; target++){
            bool notTaken = dp[ind-1][target];
            bool taken = false;
            if(arr[ind]<=target){
                taken = dp[ind-1][target - arr[ind]];
            }
            dp[ind][target] = notTaken || taken;
        }
    }
    return dp[n-1][t];
}
int main() {
    int n = 5; // number of elements
    int target = 19; // target sum
    vector<int> arr= {2, 3, 5, 7, 8};  // given input array in the question
    if(subsetSumTabulation(n, target, arr)) {
        cout << "There exists a subset with sum " << target << endl;
    } else {
        cout << "There does not exist a subset with sum " << target << endl;
    }
    return 0;
}