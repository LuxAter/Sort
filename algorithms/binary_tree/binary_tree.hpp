#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
namespace sort{
  struct BinaryTree{
    int value;
    BinaryTree* left;
    BinaryTree* right;
  };
  void BinaryTreeSort();
  void InsertNode(BinaryTree* &tree, int new_value); 
  void ReadTree(BinaryTree* node);
}
#endif
