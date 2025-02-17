#include <bits/stdc++.h>
using namespace std;

int powerSum(int X, int N, int i, int hi, int current_sum) {
    vector<int> combo;

    if(current_sum == X) return 1;

    if(current_sum > X) return 0;

    for(int x = i; x <= hi; x++) {
        int temp = 0;
        
    }
}

int main() {
    
    int X, N;
    cin >> X >> N;

    int temp = 1;
    while(pow(temp, N) < X) temp++;



    return 0;
}

