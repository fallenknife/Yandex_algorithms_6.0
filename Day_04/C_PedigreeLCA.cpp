#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


class Child {
    public:
      string child, parent;
};

class FamilyTree {
    unordered_map<string, string> family_tree;

public:
    FamilyTree(vector<Child> const& peoples) {
        for (auto const& [child, parent] : peoples) {
            family_tree[child] = parent;
        }
    }

    [[nodiscard]] auto LCA(string const& one, string const& two) const
        -> string {  // NOLINT(*-easily-swappable-parameters)
        auto ancestor_tmp = Ancestors(one);
        auto ancestor_one = unordered_set(ancestor_tmp.begin(), ancestor_tmp.end());
        auto ancestor_two = Ancestors(two);
        for (auto const& ancestor : ancestor_two) {
            if (ancestor_one.contains(ancestor)) {
                return ancestor;
            }
        }
        return "";
    }

private:
    [[nodiscard]] auto Ancestors(string child) const -> vector<string> {
        vector<string> result{child};
        while (family_tree.contains(child)) {
            child = family_tree.at(child);
            result.push_back(child);
        }
        return result;
    }
};

int main() {  
    int n;
    cin >> n;
    vector<Child> family(n - 1);
    for (auto& [child, parent] : family) {
        cin >> child >> parent;
    }
    FamilyTree familyTree(family);
    for (string one, two; cin >> one >> two;) {
        cout << familyTree.LCA(one, two) << '\n';
    }
}