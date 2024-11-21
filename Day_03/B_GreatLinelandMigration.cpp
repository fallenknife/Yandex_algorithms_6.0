#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {  

    int n;
    cin >> n;
    vector<int> input(n);
    for (int& a : input) cin >> a;

    stack<int> nums;
    nums.push(-1);
    stack<int> costs;
    costs.push(-1);

    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int cost = input[i];
        while (cost < costs.top()) {
            ans[nums.top()] = i;
            costs.pop();
            nums.pop();
        }
        costs.push(cost);
        nums.push(i);
    }
    for (auto& i : ans) cout << i << " ";

    return 0;
}