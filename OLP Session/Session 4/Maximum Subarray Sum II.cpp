#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long value;

    Node() {
        value = LLONG_MIN;
    }

    void set(long long value_) {
        value = value_;
    }

    void merge(Node left, Node right) {
        value = left.value + right.value;
    }
};

int getMid(int start, int end) {
    return start + (end - start) / 2;
}

struct SegmentTree {
    vector<long long> arr;
    vector<Node> ST;
    int n, treeSize;

    void init(vector<long long> other, int otherSize) {
        arr = other;
        n = otherSize;

        int height = (int)ceil(log2(n));
        treeSize = 2 * pow(2, height) - 1;
        ST.resize(treeSize);
    }

    void construct(int start, int end, int current) {
        if (start == end) {
            ST[current].set(arr[start]);
            return;
        }

        int mid = getMid(start, end);

        construct(start, mid, current * 2 + 1);
        construct(mid + 1, end, current * 2 + 2);

        ST[current].merge(ST[current * 2 + 1], ST[current * 2 + 2]);
    }

    SegmentTree(vector<long long> arr, int otherSize) {
        init(arr, otherSize);
        construct(0, n - 1, 0);
    }

    Node Query(int l, int r, int start, int end, int current) {
        if (l <= start && r >= end) {
            return ST[current];
        }

        Node answer;

        if (l > end || r < start || l > r) {
            return answer;
        }

        int mid = getMid(start, end);

        Node left = Query(l, r, start, mid, current * 2 + 1);
        Node right = Query(l, r, mid + 1, end, current * 2 + 2);

        answer.merge(left, right);
        return answer;
    }

    Node Query(int l, int r) {
        return Query(l, r, 0, n - 1, 0);
    }
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> arr(n);
    for (long long &i : arr) {
        cin >> i;
    }

    SegmentTree tree(arr, n);

    long long maxSubarraySum = LLONG_MIN;

    for (int i = a; i <= b; i++) {
        for (int j = 0; j + i < n; j++) {
            maxSubarraySum = max(maxSubarraySum, tree.Query(j, j + i - 1).value);
        }
    }

    cout << maxSubarraySum;
}