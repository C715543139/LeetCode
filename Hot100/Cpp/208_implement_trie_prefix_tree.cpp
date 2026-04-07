#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Trie {
public:
    class Node {
    public:
        char v;
        vector<Node *> children;

        Node(char val) : v(val) {}

        Node *findChild(char val) {
            for (auto child: children) {
                if (child->v == val) {
                    return child;
                }
            }
            return nullptr;
        }

        Node *addChild(char val) {
            auto child = new Node(val);
            children.push_back(child);
            return child;
        }
    };

    Node *head;
    unordered_set<string> s;

    Trie() : head(new Node('.')) {}

    void insert(const string &word) {
        auto temp = head;
        for (auto c: word) {
            auto next = temp->findChild(c);
            if (next == nullptr) {
                next = temp->addChild(c);
            }
            temp = next;
        }
        s.emplace(word);
    }

    bool search(const string &word) {
        return s.count(word) != 0;
    }

    bool startsWith(const string &prefix) {
        auto temp = head;
        for (auto c: prefix) {
            auto next = temp->findChild(c);
            if (next == nullptr) {
                return false;
            }
            temp = next;
        }
        return true;
    }
};

int main() {
    return 0;
}
