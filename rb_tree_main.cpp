// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#include "./rb_tree.hpp"

void print_helper(const ft::Rb_tree_node::Node_ptr& root,
                  std::string indent,
                  bool last) {
  // print the tree structure on the screen
  if (root != NULL && root->data != 0) {
    std::cout << indent;
    if (last) {
      std::cout << "R----";
      indent += "     ";
    } else {
      std::cout << "L----";
      indent += "|    ";
    }

    std::string scolor = root->color ? "RED" : "BLACK";
    std::cout << root->data << "(" << scolor << ")" << std::endl;
    print_helper(root->left, indent, false);
    print_helper(root->right, indent, true);
  }
  // std::cout<<root->left->data<<std::endl;
}

// print the tree structure on the screen
void pretty_print(ft::Rb_tree_node::Node_ptr root) {
  if (root) {
    print_helper(root, "", true);
  }
}

void inorderOrderHelper(ft::Rb_tree_node::Node_ptr node) {
  if (node != NULL && node->data != 0) {
    inorderOrderHelper(node->left);
    std::cout << node->data << " ";
    inorderOrderHelper(node->right);
  }
}

int main() {
  ft::Rb_tree bst;

  bst.insert(8);
  bst.insert(18);
  bst.insert(5);
  bst.insert(15);
  bst.insert(17);
  bst.insert(25);
  bst.insert(40);
  bst.insert(80);
  bst.insert(1);
  bst.insert(2);
  bst.insert(30);

  std::cout << "\nBefore delete: \n";
  pretty_print(bst.get_root());
  //   bst.delete_node(8);
  //   bst.delete_node(18);
  //   bst.delete_node(5);
  //   bst.delete_node(15);
  //   bst.delete_node(17);
  //   bst.delete_node(25);
  //   bst.delete_node(40);
  //   bst.delete_node(80);
  //   bst.delete_node(1);
  //   bst.delete_node(25);
  //   bst.delete_node(40);
  //   bst.delete_node(17);
  //   bst.delete_node(17);
  //   bst.delete_node(15);
  //   bst.delete_node(8);
  //   bst.delete_node(18);
  std::cout << "\n";
  std::cout << "After delete: \n";
  pretty_print(bst.get_root());
  std::cout << "\n";
  std::cout << "Search 17: " << bst.search(17)->data << "\n";
  std::cout << "Minimum: " << bst.minimum(bst.get_root())->data << "\n";
  std::cout << "Maximum: " << bst.maximum(bst.get_root())->data << "\n";
  std::cout << "Inorder: ";
  inorderOrderHelper(bst.get_root());
  return 0;
}
