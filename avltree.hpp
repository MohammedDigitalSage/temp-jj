// Developer: Mohammed

// Project Name: Median Tracker

// Overview: The project aims to implement an Abstract Data Type (ADT) for tracking medians in various data structures. Four different implementations are provided:

// 1. Vector-based: Uses a sorted vector to insert elements and pop medians.
// 2. Linked list-based: Utilizes a sorted linked list to insert elements and pop medians.
// 3. Heap-based: Maintains a max heap for elements less than or equal to the median and a min heap for elements greater than the median.
// 4. AVL tree-based: Implements two AVL trees, one for elements less than or equal to the median and the other for elements greater than the median.

// The project involves creating separate files for each implementation, including `myVector.cpp`, `myList.cpp`, `myHeap.cpp`, and `myAVLtree.cpp`. Each file contains functions to insert elements and pop medians according to the provided instructions.

// Additionally, a `main.cpp` file is provided to read input instructions from a file, convert them into an integer format, and pass them to each median tracking method. The performance of each implementation is measured and compared, and the results are presented in a report.

// Overall, the project focuses on understanding and implementing different approaches to efficiently track medians in various data structures.

// #ifndef MYAVLTREE_HPP
// #define MYAVLTREE_HPP

// #include <vector>
// #include <string>

// // Function prototype for treeMedian function
// void treeMedian(const std::vector<std::string>* instructions);

// #endif // MYAVLTREE_HPP

// #ifndef MY_AVL_TREE_HPP
// #define MY_AVL_TREE_HPP

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// AVL Tree node structure
// struct AVLNode {
//     int data;
//     int height;
//     int count;
//     AVLNode* left;
//     AVLNode* right;
// };

// struct AVLNode::AVLNode { createAVLNode; getHeight; getBalance; rotateRight; rotateLeft; insertNode; findMedian; deleteTree; treeMedian }

// // Function declarations
// // AVLNode* createNode(int data);
// // AVLNode* createAVLNode(int data);
// // Function declaration for creating AVL node
// AVLNode* createAVLNode(int data);
// int getHeight(AVLNode* node);
// int getBalance(AVLNode* node);
// AVLNode* rotateRight(AVLNode* y);
// AVLNode* rotateLeft(AVLNode* x);
// AVLNode* insertNode(AVLNode* root, int data, int& leftCount);
// int findMedian(AVLNode* root, int totalCount);
// void deleteTree(AVLNode* root);
// void treeMedian(const vector<string>* instructions);

// #endif /* MY_AVL_TREE_HPP */

// AVL Tree node structure
#ifndef MY_AVL_TREE_HPP
#define MY_AVL_TREE_HPP

#include <iostream>
#include <vector>
#include <string>

struct AVLNode {
    int data;
    int height;
    int count;
    AVLNode* left;
    AVLNode* right;

    // Function declarations
    static AVLNode* createAVLNode(int data);
    static int getHeight(AVLNode* node);
    static int getBalance(AVLNode* node);
    static AVLNode* rotateRight(AVLNode* y);
    static AVLNode* rotateLeft(AVLNode* x);
    static AVLNode* insertNode(AVLNode* root, int data, int& leftCount);
    static int findMedian(AVLNode* root, int totalCount);
    static void deleteTree(AVLNode* root);
};

// void treeMedian(const std::vector<int>* instructions);
// void treeMedian(const std::vector<int>* instructions);
void treeMedian(const std::vector<int>* instructions);
#endif /* MY_AVL_TREE_HPP */
