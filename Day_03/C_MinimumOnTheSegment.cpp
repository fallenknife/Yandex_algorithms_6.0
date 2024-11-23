#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void push_back(deque<int>& d, int v) {
    while (!d.empty() && d.back() > v) d.pop_back();

    d.push_back(v);
}

void pop_front(deque<int>& d, int v) {
    if (d.front() == v) d.pop_front();
}

int main() {  
    unsigned n, k;
    cin >> n >> k;

    vector<int> array(n);
    for (int& v : array) cin >> v;

    deque<int> d;
    unsigned i = 0;
    for (; i < k; ++i) push_back(d, array[i]);

    cout << d.front() << '\n';

    for (; i < n; ++i) {
        pop_front(d, array[i - k]);
        push_back(d, array[i]);
        cout << d.front() << '\n';
    }
}