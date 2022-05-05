// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include "rb_tree_main.hpp"

#define RESET "\033[0m"
#define GREEN "\033[0m\033[32m"     /* Green */
#define CYAN "\033[0m\033[36m"      /* Cyan */
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */
#define YELLOW "\033[1m\033[33m"    /* Bold Black */

void print_helper(const ft::_Rb_tree_node<TYPE>::Node_ptr& root,
                  std::string indent,
                  bool last) {
  // print the tree structure on the screen
  if (root != NULL && KOV<TYPE>()(root->data) != PRINT_EMPTY) {
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
    std::cout << YELLOW << KOV<TYPE>()(root->data) << RESET << "(" << scolor << ")";
    std::cout << CYAN " K: [" << KOV<TYPE>()(root->data) << "] " RESET;
    std::cout << GREEN "V: [" << VOV<TYPE>()(root->data) << "]" RESET << std::endl;
    print_helper(root->left, indent, false);
    print_helper(root->right, indent, true);
  }
}

// print the tree structure on the screen
void pretty_print(ft::_Rb_tree_node<TYPE>::Node_ptr root) {
  if (root) {
    print_helper(root, "", true);
  }
}

void preorder_print(ft::_Rb_tree_node<TYPE>::Node_ptr node) {
  if (node != NULL && KOV<TYPE>()(node->data) != PRINT_EMPTY) {
    std::cout << KOV<TYPE>()(node->data) << " ";
    preorder_print(node->left);
    preorder_print(node->right);
  }
}

void postorder_print(ft::_Rb_tree_node<TYPE>::Node_ptr node) {
  if (node != NULL && KOV<TYPE>()(node->data) != PRINT_EMPTY) {
    postorder_print(node->left);
    postorder_print(node->right);
    std::cout << KOV<TYPE>()(node->data) << " ";
  }
}

void inorder_print(ft::_Rb_tree_node<TYPE>::Node_ptr node) {
  if (node != NULL && KOV<TYPE>()(node->data) != PRINT_EMPTY) {
    inorder_print(node->left);
    std::cout << KOV<TYPE>()(node->data) << " ";
    inorder_print(node->right);
  }
}

int main(void) {
  ft::Rb_tree<KEY, TYPE, KOV<TYPE> > bst1;
  ft::Rb_tree<KEY, TYPE, KOV<TYPE> > bst;

  std::cout << "\nBefore delete: \n";

  bst1.insert(TYPE("a", 8));
  bst1.insert(TYPE("b", 18));
  bst1.insert(TYPE("c", 5));
  bst1.insert(TYPE("d", 15));
  bst1.insert(TYPE("e", 17));
  bst1.insert(TYPE("f", 25));
  bst1.insert(TYPE("g", 40));
  bst1.insert(TYPE("h", 80));
  bst1.insert(TYPE("i", 1));

  bst = bst1;
  pretty_print(bst.get_root());
  bst.delete_node("h");

  std::cout << "\nDelete \"h\"\n";

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
  std::cout << "Search \"h\": " << VOV<TYPE>()(bst.search("h")->data) << "\n";
  std::cout << "Minimum: " << KOV<TYPE>()(bst.minimum(bst.get_root())->data);
  NEWLINE
  std::cout << "Maximum: " << KOV<TYPE>()(bst.maximum(bst.get_root())->data);
  NEWLINE
  std::cout << "Preorder:  ", preorder_print(bst.get_root());
  NEWLINE
  std::cout << "Inorder:   ", inorder_print(bst.get_root());
  NEWLINE
  std::cout << "Postorder: ", postorder_print(bst.get_root());
  NEWLINE

  std::cout << "\n[ Iterators: ] \n";
  ft::Rb_tree<KEY, TYPE, KOV<TYPE> >::iterator it0(bst.begin());
  ft::Rb_tree<KEY, TYPE, KOV<TYPE> >::iterator it = it0;
  ft::Rb_tree<KEY, TYPE, KOV<TYPE> >::const_iterator itc0(bst.begin());
  ft::Rb_tree<KEY, TYPE, KOV<TYPE> >::const_iterator itc = itc0;
  std::cout << "Begin:       " << it->first << "\n";
  std::cout << "Begin Const: " << itc->first << "\n";
  NEWLINE
}
