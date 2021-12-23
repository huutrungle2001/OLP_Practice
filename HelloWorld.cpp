#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;

    Node(){
        value = INT_MIN;
    }

    void set(int v){
        value = v;
    }

    void merge(Node left, Node right) {
        value = max(left.value, right.value);
    }
};

struct SegmentTree {
    vector<int> arr;
    vector<Node> ST;
    int n, size;

    void init(vector<int> input, int inputSize){
        n = inputSize;
        arr = input;
        int height = (int)ceil(log2(n));
        size = 2*pow(2, height) - 1;
        ST.resize(size);
    }

    void construct(int start, int end, int current){
        if(start == end){
            ST[current].set(arr[start]);
            return;
        }

        int mid = start + (end - start) / 2;

        construct(start, mid, current * 2 + 1);
        construct(mid + 1, end, current * 2 + 2);

        ST[current].merge(ST[current * 2 + 1], ST[current * 2 + 2]);
    }

    SegmentTree(vector<int> input, int inputSize){
        init(input, inputSize);
        construct(0, n - 1, 0);
    }

    Node Query(int l, int r, int start, int end, int current){
        if(l <= start && r >= end){
            return ST[current];
        }

        Node answer;

        if(l > end || r < start){
            return answer;
        }

        int mid = start + (end - start) / 2;

        Node left = Query(l, r, start, mid, current * 2 + 1);
        Node right = Query(l, r, mid + 1, end, current * 2 + 2);

        answer.merge(left, right);

        return answer;
    }

    Node Query(int l, int r){
        return Query(l, r, 0, n - 1, 0);
    }

    
};

int main(){

}