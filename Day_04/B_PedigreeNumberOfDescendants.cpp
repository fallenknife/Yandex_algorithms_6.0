#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

namespace solution {
map<string, set<string>> Tree;
map<string, int> ResultTree;
map<string, bool> VisitedNode;
};  // namespace solution

void FindChild(string name) {
  for (string i : solution::Tree[name]) {
    if (solution::ResultTree[i] == 0 && !solution::VisitedNode[i]) {
      if (solution::Tree[i].empty()) {
        solution::VisitedNode[i] = true;
        solution::ResultTree[name]++;
      } else {
        FindChild(i);
      }
    }
    if (!solution::VisitedNode[i]) {
      solution::ResultTree[name] += solution::ResultTree[i] + 1;
      solution::VisitedNode[i] = true;
    }
  }
}

int main() {
  int n;
  cin >> n;
  set<string> names;
  for (int i = 0; i < n - 1; ++i) {
    string child, parent;
    cin >> child >> parent;
    solution::Tree[parent].insert(child);
    solution::ResultTree[parent] = 0;
    solution::ResultTree[child] = 0;
    names.insert(parent);
    names.insert(child);
  }
  for (string i : names) {
    FindChild(i);
    cout << i << ' ' << solution::ResultTree[i] << '\n';
  }
  return 0;
}