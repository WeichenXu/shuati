#include <iostream>
#include <unordered_map>
#include <queue>
// 1. Construct the huffman tree
//    a. use a min heap to store all nodes in descending order (compare the freq)
//    b. everty time combine two smallest two nodes in the heap
//    c. use '$' to represent a interim node
// 2. Get the length of each char
//    Use recursive way
// 3. Sum the length += huffman length (char) * freq
//
// This has been tested with the samples in the picture, remember to replace the hard coded input with the test input
// For more information and picture, please look at http://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/

using namespace std;

struct treeNode{
    char ch;
    int freq;
    treeNode *left, *right;
    treeNode(char data, int f){
        left = right = NULL;
        ch = data;
        freq = f;
    }
};

struct comparator{
    bool operator()(treeNode* left, treeNode* right){
        return left->freq > right->freq;
    }
};

treeNode* buildHuffmanTree(vector<char>& data, vector<int>& freq){
    struct treeNode *left, *right, *top;
    // Create a min heap & inserts all characters of data[]
    priority_queue<treeNode*, vector<treeNode*>, comparator> minHeap;
    for (int i = 0; i < data.size(); ++i)
        minHeap.push(new treeNode(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1)
    {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the
        // sum of the two nodes frequencies. Make the two extracted
        // node as left and right children of this new node. Add
        // this node to the min heap
        // '$' is a special value for internal nodes, not used
        top = new treeNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    return minHeap.top();
}
void getLenHelper(unordered_map<char,int>& dicts, treeNode* cur, string str){
    if (!cur){
        return;
    }
    if (cur->ch != '$'){
        dicts[cur->ch] = str.length();
    }
    getLenHelper(dicts, cur->left, str+"0");
    getLenHelper(dicts, cur->right, str+"1");
}
// remember to replace the input to the way you do
int main(){
    int n = 5;
    vector<char> data = {'a','b','c','d','e'};
    vector<int> freqs = {5, 15, 40, 30, 10};
    treeNode* root =  buildHuffmanTree(data, freqs);
    unordered_map<char, int> dicts;
    getLenHelper(dicts, root, "");
    // sum the length
    int sum = 0;
    for (int i=0; i<n; ++i){
        sum += dicts[data[i]] * freqs[i];
    }
    cout << "sum size: " << sum << endl;
    return sum;
}
