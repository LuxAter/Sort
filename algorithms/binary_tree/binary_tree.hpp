#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
namespace sort{
  struct BinaryTree{
    int value;
    BinaryTree* left = NULL;
    BinaryTree* right = NULL;
  };
  void BinaryTreeSort();
  void InsertNode(BinaryTree* &tree, int new_value); 
  void ReadTree(BinaryTree* node);
}
#endif
