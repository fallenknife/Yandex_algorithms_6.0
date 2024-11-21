#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, string> ChildParentTree; 
  map<string, int> ParentGenerationTree;    
  for (int i = 0; i < n - 1; ++i) {
    string a1, a2;
    cin >> a1 >> a2;
    ChildParentTree[a1] = a2;
    ParentGenerationTree[a1] = 0;
    ParentGenerationTree[a2] = 0;
  }

  
  for (auto const& [node, next_node] : ChildParentTree) {
    string s = node;
    int count = 0;
    while (ChildParentTree.count(s)) {
      s = ChildParentTree[s];
      count++;
    }
    ParentGenerationTree[node] = count;
  }


  vector<pair<string, int>> sorted_a;
  for (auto const& [key, val] : ParentGenerationTree) {
    sorted_a.push_back({key, val});
  }
  sort(sorted_a.begin(), sorted_a.end());

  for (const auto& p : sorted_a) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}

