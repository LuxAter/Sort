#include "binary_tree.hpp"
#include <time.h>
#include <vector>
#include "../algo_core.hpp"

void sort::BinaryTreeSort() {
  clock_t start = clock();
  BinaryTree* root = NULL;
  for (int i = 0; i < data.size(); i++) {
    result.vec_access++;
    InsertNode(root, data[i]);
  }
  data.clear();
  ReadTree(root);
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}

void sort::InsertNode(BinaryTree*& tree, int new_value) {
  if (tree == NULL) {
    tree = new BinaryTree;
    tree->value = new_value;
    tree->right = NULL;
    tree->left = NULL;
  } else if (tree != NULL) {
    result.comparisons++;
    if (new_value <= tree->value) {
      InsertNode(tree->left, new_value);
    } else {
      InsertNode(tree->right, new_value);
    }
  }
}

void sort::ReadTree(BinaryTree* node) {
  if (node != NULL) {
    ReadTree(node->left);
    result.vec_access++;
    data.push_back(node->value);
    ReadTree(node->right);
  }
}
