#include <bits/stdc++.h>
using namespace std;

struct Node {
    map<char, int> count;
    int unique;

    Node() {
        unique = 0;
    }

    void set(char c) {
        count[c]++;
        unique = 1;
    }

    void getUnique() {
        for (auto it : count) {
            if (it.second == 1) {
                unique++;
            }
        }
    }

    void merge(Node left, Node right) {
        for (auto it : left.count) {
            count[it.first] += it.second;
        }

        for (auto it : right.count) {
            count[it.first] += it.second;
        }

        getUnique();
    }
};

int getMid(int start, int end) {
    return start + (end - start) / 2;
}

struct SegmentTree {
    string s;
    int size;
    vector<Node> ST;

    SegmentTree(string s_) {
        s = s_;
        int height = (int)ceil(log2(s.length()));
        size = 2 * pow(2, height) - 1;
        ST.resize(size);
    }

    void Construct(int start, int end, int current) {
        if (start == end) {
            ST[current].set(s[start]);
            return;
        }

        int mid = getMid(start, end);

        Construct(start, mid, current * 2 + 1);
        Construct(mid + 1, end, current * 2 + 2);
        ST[current].merge(ST[current * 2 + 1], ST[current * 2 + 2]);
    }

    void Construct() {
        Construct(0, s.length() - 1, 0);
    }

    Node Query(int l, int r, int start, int end, int current) {
        Node answer;

        if (l > end || r < start || l > r) {
            return answer;
        }

        if (l <= start && r >= end) {
            answer = ST[current];
            return answer;
        }

        int mid = getMid(start, end);

        Node left = Query(l, r, start, mid, current * 2 + 1);
        Node right = Query(l, r, mid + 1, end, current * 2 + 2);

        answer.merge(left, right);

        return answer;
    }

    Node Query(int l, int r) {
        return Query(l, r, 0, s.length(), 0);
    }
};

int main() {
    string s;
    cin >> s;
    SegmentTree tree(s);
    tree.Construct();
    for (Node node : tree.ST) {
        for (auto it : node.count) {
            cout << it.first << " " << it.second << endl;
        }
        cout << endl;
    }

    Node temp = tree.Query(0, 2);
    for (auto it : temp.count) {
        cout << it.first << " " << it.second << endl;
    }

    int answer = 0;

    for (int i = 0; i <= s.length(); i++) {
        for (int j = i; j <= s.length(); j++) {
            answer += tree.Query(i, j).unique;
        }
    }

    cout << answer << endl;
}

//     5
//   3   2
//  2 1 1 1
// 1 1

// 1 + 2 + 3 + 4 + 5 = 15
// 10
// 6
// 3
// 1
