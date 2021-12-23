#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value, countEven, countOdd;

    void set(int value_) {
        value = value_;
        countEven = (value % 2 == 0);
        countOdd = 1 - countEven;
    }

    void merge(Node left, Node right) {
        value = left.value + right.value;
        countEven = left.countEven + right.countEven;
        countOdd = left.countOdd + right.countOdd;
    }

    void halve() {
        if (value % 2 == 0) {
            value /= 2;
            countEven = (value % 2 == 0);
            countOdd = 1 - countEven;
        }
    }

    void pour() {
        if (value % 2 == 1) {
            value -= 1;
            countOdd = (value % 2 == 1);
            countEven = 1 - countOdd;
        }
    }
};

int getMid(int start, int end) {
    return start + (end - start) / 2;
}

void constructSTUntil(int arr[], int n, Node *st, int start, int end, int current) {
    if (start == end) {
        st[current].set(arr[start]);
        return;
    }

    int mid = getMid(start, end);

    constructSTUntil(arr, n, st, start, mid, current * 2 + 1);
    constructSTUntil(arr, n, st, mid + 1, end, current * 2 + 2);

    st[current].merge(st[current * 2 + 1], st[current * 2 + 2]);
}

Node *constructST(int arr[], int n) {
    int height = (int)ceil(log2(n));
    int max_size = 2 * (pow(2, height)) - 1;

    Node *st = new Node[max_size];

    constructSTUntil(arr, n, st, 0, n - 1, 0);

    return st;
}

int getSumUntil(Node *st, int l, int r, int start, int end, int current) {
    if (l <= start && r >= end) {
        return st[current].value;
    }

    if (r < l || l > end || r < start) {
        return 0;
    }

    int mid = getMid(start, end);

    return getSumUntil(st, l, r, start, mid, current * 2 + 1) + getSumUntil(st, l, r, mid + 1, end, current * 2 + 2);
}

int getSum(Node *st, int n, int l, int r) {
    return getSumUntil(st, l, r, 0, n - 1, 0);
}

void HalveUntil(Node *st, int start, int end, int current) {
    if (st[current].countEven == 0) {
        return;
    }

    if (start == end) {
        st[current].halve();
        return;
    }

    int mid = getMid(start, end);

    if (st[current * 2 + 1].countEven > 0) {
        HalveUntil(st, start, mid, current * 2 + 1);
    }

    if (st[current * 2 + 2].countEven > 0) {
        HalveUntil(st, mid + 1, end, current * 2 + 2);
    }

    st[current].merge(st[current * 2 + 1], st[current * 2 + 2]);
}

void Halve(Node *st, int n) {
    HalveUntil(st, 0, n - 1, 0);
}

void PourUntil(Node *st, int start, int end, int current) {
    if (st[current].countOdd == 0) {
        return;
    }

    if (start == end) {
        st[current].pour();
        return;
    }

    int mid = getMid(start, end);

    if (st[current * 2 + 1].countOdd > 0) {
        PourUntil(st, start, mid, current * 2 + 1);
    }

    if (st[current * 2 + 2].countOdd > 0) {
        PourUntil(st, mid + 1, end, current * 2 + 2);
    }

    st[current].merge(st[current * 2 + 1], st[current * 2 + 2]);
}

void Pour(Node *st, int n) {
    PourUntil(st, 0, n - 1, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node *st = constructST(arr, n);

    string operations;
    cin >> operations;

    // clock_t start = clock();
    for (char operation : operations) {
        if (operation == '0') {
            Halve(st, n);
            cout << st[0].value << "\n";
        } else {
            Pour(st, n);
            cout << st[0].value << "\n";
        }
    }
    // clock_t end = clock();

    // printf("\nTime: %f\n", double(end - start));
}