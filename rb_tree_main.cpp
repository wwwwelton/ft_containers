// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>

#include "./rb_tree.hpp"
#include "./utility.hpp"

#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"   /* Red */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */

#define TYPE ft::pair<int, int>

void print_helper(const ft::_Rb_tree_node<TYPE>::Node_ptr& root,
                  std::string indent,
                  bool last) {
  // print the tree structure on the screen
  if (root != NULL && root->data.first != 0) {
    std::cout << indent;
    if (last) {
      std::cout << "R----";
      indent += "     ";
    } else {
      std::cout << "L----";
      indent += "|    ";
    }

    std::string scolor = root->color ? BOLDRED "RED" RESET
                                     : BOLDBLACK "BLACK" RESET;
    std::cout << root->data.first << "(" << scolor << ")" << std::endl;
    print_helper(root->left, indent, false);
    print_helper(root->right, indent, true);
  }
  // std::cout<<root->left->data<<std::endl;
}

// print the tree structure on the screen
void pretty_print(ft::_Rb_tree_node<TYPE>::Node_ptr root) {
  if (root) {
    print_helper(root, "", true);
  }
}

void inorderOrderHelper(ft::_Rb_tree_node<TYPE>::Node_ptr node) {
  if (node != NULL && node->data.first != 0) {
    inorderOrderHelper(node->left);
    std::cout << node->data.first << " ";
    inorderOrderHelper(node->right);
  }
}

int main() {
  ft::Rb_tree<TYPE> bst;

  std::cout << "\nBefore delete: \n";
  bst.insert(TYPE(8, 8));
  bst.insert(TYPE(18, 18));
  bst.insert(TYPE(5, 5));
  bst.insert(TYPE(15, 15));
  bst.insert(TYPE(17, 17));
  bst.insert(TYPE(25, 25));
  bst.insert(TYPE(40, 40));
  bst.insert(TYPE(80, 80));
  bst.insert(TYPE(1, 1));
    pretty_print(bst.get_root());

  //   bst.delete_node(1);
  // bst.delete_node(18);
  // bst.delete_node(5);
  // bst.delete_node(15);
  // bst.delete_node(17);
  // bst.delete_node(25);
  // bst.delete_node(40);
  // bst.delete_node(80);
  // bst.delete_node(1);
  // bst.delete_node(25);
  // bst.delete_node(40);
  // bst.delete_node(2);
  // bst.delete_node(17);
  // bst.delete_node(15);
  //   bst.delete_node(15);
  //   bst.delete_node(8);
  // kkk
  //   bst.delete_node(25);
  //   std::cout << "\n";
  //   std::cout << "After delete: \n";
//   pretty_print(bst.get_root());
  //   std::cout << "\n";
  std::cout << "Search 10: " << bst.search(8)->data.first << "\n";
    std::cout << "Minimum: " << bst.minimum(bst.get_root())->data.first << "\n";
    std::cout << "Maximum: " << bst.maximum(bst.get_root())->data.first << "\n";
    std::cout << "Inorder: ";
    inorderOrderHelper(bst.get_root());
  return 0;
}
