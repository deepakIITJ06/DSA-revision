#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

// 1. parent(i): Function to return the parent node of node i
// 2. leftChild(i): Function to return index of the left child of node i
// 3. rightChild(i): Function to return index of the right child of node i
// 4. shiftUp(int i): Function to shift up the node in order to maintain the
// heap property
// 5. shiftDown(int i): Function to shift down the node in order to maintain the
// heap property.
// int s=-1, current index value of the array H[].

class Solution {
public:
    int extractMax() {
        // your code here
        int maxi = H[0];
        
        // after extracting max element, last one will occupy first place
        // and decrease size by one
        swap(H[0], H[s]);
        s--;
        // Now we will try to make heap valid again
        shiftDown(0);
        return maxi;
    }
};