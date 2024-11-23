#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {  // NOLINT
    string s;
    getline(cin, s);
    stack<int> stack;
    for (char c : s)
        if (isdigit(c))
            stack.push(c - '0');
        else if (c != ' ') {
            const int a = stack.top();
            stack.pop();
            const int b = stack.top();
            stack.pop();
            if (c == '+')
                stack.push(a + b);
            else if (c == '-')
                stack.push(b - a);
            else
                stack.push(a * b);
        }
    cout << stack.top();
    return 0;
}