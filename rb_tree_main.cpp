// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include <iostream>
#include <string>

#include "./rb_tree.hpp"
#include "./utility.hpp"

#define RESET "\033[0m"
#define GREEN "\033[0m\033[32m"     /* Green */
#define CYAN "\033[0m\033[36m"      /* Cyan */
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */
#define YELLOW "\033[1m\033[33m"    /* Bold Black */

#define TYPE ft::pair<std::string, int>

void print_helper(const ft::_Rb_tree_node<TYPE>::Node_ptr& root,
                  std::string indent,
                  bool last) {
  // print the tree structure on the screen
  if (root != NULL && root->data.first != "") {
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
    std::cout << YELLOW << root->data.first << RESET << "(" << scolor << ")";
    std::cout << CYAN " K: [" << root->data.first << "] " RESET;
    std::cout << GREEN "V: [" << root->data.second << "]" RESET << std::endl;
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
  if (node != NULL && node->data.first != "") {
    inorderOrderHelper(node->left);
    std::cout << node->data.first << " ";
    inorderOrderHelper(node->right);
  }
}

int main(void) {
  ft::Rb_tree<std::string, int> bst;

  std::cout << "\nBefore delete: \n";
  bst.insert(TYPE("a", 8));
  bst.insert(TYPE("b", 18));
  bst.insert(TYPE("c", 5));
  bst.insert(TYPE("c", 15));
  bst.insert(TYPE("d", 17));
  bst.insert(TYPE("e", 25));
  bst.insert(TYPE("f", 40));
  bst.insert(TYPE("g", 80));
  bst.insert(TYPE("h", 1));
  pretty_print(bst.get_root());

  bst.delete_node("h");
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
  std::cout << "\n";
  std::cout << "After delete: \n";
  pretty_print(bst.get_root());
  std::cout << "\n";
  std::cout << "Search 17: " << bst.search("a")->data.first << "\n";
  std::cout << "Minimum: " << bst.minimum(bst.get_root())->data.first << "\n";
  std::cout << "Maximum: " << bst.maximum(bst.get_root())->data.first << "\n";
  std::cout << "Inorder: ";
  inorderOrderHelper(bst.get_root());
  return 0;
}
