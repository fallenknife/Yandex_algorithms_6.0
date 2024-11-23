#include <iostream>
#include <vector>

using namespace std;

class MainTree {
  vector<vector<int>> branch;
  vector<int> count;

 public:
  MainTree(int n) : branch(n + 1), count(n + 1) {}
  void AddEdge(int a, int b) {
    branch[a].push_back(b);
    branch[b].push_back(a);
  }

  vector<int> SizeOfSubtrees() {
    NumberOfNodes(1, 0);
    return {next(count.begin()), count.end()};
  }

 private:
  void NumberOfNodes(int size, int element) {
    count[size] = 1;
    for (int i : branch[size]) {
      if (i == element) continue;
      NumberOfNodes(i, size);
      count[size] += count[i];
    }
  }
};

int main() {
  int n;
  cin >> n;
  MainTree tree(n);
  for (int i = 0; i < n - 1; i++) {
    int a = 0, b = 0;
    cin >> a >> b;
    tree.AddEdge(a, b);
  }
  for (int i : tree.SizeOfSubtrees()) {
    cout << i << ' ';
  }
}