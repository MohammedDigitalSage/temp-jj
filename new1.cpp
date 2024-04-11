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

#include "myAVLtree.hpp"
#include <vector>
#include <string>

using namespace std;

// Function to track median using AVL trees
void treeMedian(const vector<string>* instructions) {
    // Initialize AVL trees for smaller and larger elements
    AvlTree<int> smallerElements;
    AvlTree<int> largerElements;

    // AvlTree<int> tree;
    // // Populate the tree
    // int numberOfNodes = tree.size(); // Get the size of the tree


    // Variable to track total number of elements
    int totalCount = 0;

    // Process instructions
    for (const auto& instruction : *instructions) {
        AvlTree<int> tree;
        // Populate the tree
        int numberOfNodes = tree.size(); // Get the size of the tree

        // Balance AVL trees
        if (smallerElements.size() < largerElements.size()) {
            // If the smaller elements AVL tree has fewer elements than the larger elements AVL tree
            // Move the smallest element from the larger elements AVL tree to the smaller elements AVL tree
            int smallestFromLarge = largerElements.findMin();
            smallerElements.insert(smallestFromLarge);
            largerElements.remove(smallestFromLarge);
        } else if (smallerElements.size() > largerElements.size() + 1) {
            // If the smaller elements AVL tree has more than one element than the larger elements AVL tree
            // Move the largest element from the smaller elements AVL tree to the larger elements AVL tree
            int largestFromSmall = smallerElements.findMax();
            largerElements.insert(largestFromSmall);
            smallerElements.remove(largestFromSmall);
        }






        // Balance AVL trees
        // if (smallerElements.size() < largerElements.size()) {
        //     // If the smaller elements AVL tree has fewer elements than the larger elements AVL tree
        //     // Move the smallest element from the larger elements AVL tree to the smaller elements AVL tree
        //     int smallestFromLarge = largerElements.findMin();
        //     smallerElements.insert(smallestFromLarge);
        //     largerElements.remove(smallestFromLarge);
        // } else if (smallerElements.size() > largerElements.size() + 1) {
        //     // If the smaller elements AVL tree has more than one element than the larger elements AVL tree
        //     // Move the largest element from the smaller elements AVL tree to the larger elements AVL tree
        //     int largestFromSmall = smallerElements.findMax();
        //     largerElements.insert(largestFromSmall);
        //     smallerElements.remove(largestFromSmall);
        // }


        // Calculate median
        int median;
        if (totalCount % 2 == 0) {
            // If total elements is even, median is average of middle two elements
            int firstMedian = largerElements.findMin();
            int secondMedian = smallerElements.findMax();
            median = (firstMedian + secondMedian) / 2;
        } else {
            // If total elements is odd, median is the middle element
            median = largerElements.findMin();
        }

        // Output median
        cout << "Current Median: " << median << endl;
    }
}

// #include "myAVLtree.hpp"
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

// // Function to create a new AVL node
// AVLNode* createAVLNode(int data) {
//     AVLNode* newNode = new AVLNode();
//     newNode->data = data;
//     newNode->height = 1;
//     newNode->count = 1;
//     newNode->left = nullptr;
//     newNode->right = nullptr;
//     return newNode;
// }



// // Function to get height of AVL node
// int getHeight(AVLNode* node) {
//     if (node == nullptr)
//         return 0;
//     return node->height;
// }

// // Function to calculate balance factor of AVL node
// int getBalance(AVLNode* node) {
//     if (node == nullptr)
//         return 0;
//     return getHeight(node->left) - getHeight(node->right);
// }

// // Function to rotate AVL tree right
// AVLNode* rotateRight(AVLNode* y) {
//     AVLNode* x = y->left;
//     AVLNode* T2 = x->right;

//     // Perform rotation
//     x->right = y;
//     y->left = T2;

//     // Update heights
//     y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
//     x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

//     // Return new root
//     return x;
// }

// // Function to rotate AVL tree left
// AVLNode* rotateLeft(AVLNode* x) {
//     AVLNode* y = x->right;
//     AVLNode* T2 = y->left;

//     // Perform rotation
//     y->left = x;
//     x->right = T2;

//     // Update heights
//     x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
//     y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

//     // Return new root
//     return y;
// }

// // Function to insert a node into AVL tree
// AVLNode* insertNode(AVLNode* root, int data, int& leftCount) {
//     // Perform normal BST insertion
//     if (root == nullptr) {
//         leftCount = 0;
//         return createAVLNode(data);
//     }

//     if (data < root->data) {
//         root->left = insertNode(root->left, data, leftCount);
//         leftCount++;
//     } else if (data > root->data) {
//         root->right = insertNode(root->right, data, leftCount);
//     } else {
//         root->count++;
//         leftCount += getHeight(root->left);
//         return root;
//     }

//     // Update height of current node
//     root->height = 1 + max(getHeight(root->left), getHeight(root->right));

//     // Get balance factor
//     int balance = getBalance(root);

//     // Left Left Case
//     if (balance > 1 && data < root->left->data)
//         return rotateRight(root);

//     // Right Right Case
//     if (balance < -1 && data > root->right->data)
//         return rotateLeft(root);

//     // Left Right Case
//     if (balance > 1 && data > root->left->data) {
//         root->left = rotateLeft(root->left);
//         return rotateRight(root);
//     }

//     // Right Left Case
//     if (balance < -1 && data < root->right->data) {
//         root->right = rotateRight(root->right);
//         return rotateLeft(root);
//     }

//     // Return the (unchanged) node pointer
//     return root;
// }

// // Function to find median of AVL tree
// int findMedian(AVLNode* root, int totalCount) {
//     // If tree is empty
//     if (root == nullptr)
//         return -1;

//     int leftCount = 0;
//     // Total nodes in left subtree
//     if (root->left != nullptr)
//         leftCount = root->left->count;

//     // If total nodes are even
//     if (totalCount % 2 == 0) {
//         // If left subtree has one more node than right subtree
//         if (leftCount == totalCount / 2)
//             return root->data;
//         // If left subtree has one less node than right subtree
//         else if (leftCount == totalCount / 2 - 1)
//             return (root->data + root->right->data) / 2;
//     }
//     // If total nodes are odd
//     else {
//         // If left subtree has same number of nodes as right subtree
//         if (leftCount == totalCount / 2)
//             return root->data;
//     }

//     // If median is not found in current root, recursively search in left or right subtree
//     if (leftCount > totalCount / 2)
//         return findMedian(root->left, totalCount);
//     else
//         return findMedian(root->right, totalCount - leftCount - root->count);
// }

// // Function to delete AVL tree
// void deleteTree(AVLNode* root) {
//     if (root != nullptr) {
//         deleteTree(root->left);
//         deleteTree(root->right);
//         delete root;
//     }
// }

// void treeMedian(const vector<string>* instructions) {
//     AVLNode* root = nullptr;
//     int totalCount = 0;

//     // Iterate over each instruction
//     for (const string& instruction : *instructions) {
//         if (instruction == "pop median") {
//             // If instruction is pop median and tree is not empty, calculate median
//             if (root != nullptr) {
//                 int median = findMedian(root, totalCount);
//                 // Print the median
//                 cout << median << " ";
//             }
//         } else {
//             // If instruction is insert X, extract the number X and insert into AVL tree
//             int num = stoi(instruction.substr(7)); // Extract X from "insert X"
//             int leftCount = 0;
//             root = insertNode(root, num, leftCount);
//             totalCount++;
//         }
//     }

//     // // Delete the AVL tree
//     // deleteTree(root);

//     // // Print a newline after all medians are printed
//     // cout << endl;
// }
