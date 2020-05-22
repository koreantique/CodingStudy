#include <iostream>
#include <algorithm>

using namespace std;

int stair[301] = {0,};
int dp[301] = {0,};
int step(int n){
    dp[0] = stair[0];
    dp[1] = max(stair[0]+stair[1],stair[1]);
    dp[2] = max(stair[0]+stair[2], stair[1]+stair[2]);

    for(int i=3; i<n; i++){
        dp[i] = max(dp[i-3]+stair[i-1]+stair[i], dp[i-2]+stair[i]);
    }

    return dp[n-1];
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> stair[i];
    }

    cout << step(n) << endl;

    

}