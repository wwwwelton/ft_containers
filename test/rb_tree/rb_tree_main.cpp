// Copyright (c) 2022 Welton Leite, wleite. All rights reserved.

#include "./rb_tree_main.hpp"

#include <typeinfo>

#define RESET "\033[0m"
#define GREEN "\033[0m\033[32m"     /* Green */
#define CYAN "\033[0m\033[36m"      /* Cyan */
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */
#define YELLOW "\033[1m\033[33m"    /* Bold Black */

#define RB_TREE ft::Rb_tree<KEY, TYPE, KOV<TYPE>, COMPARE>

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
  RB_TREE bst1;
  RB_TREE bst;

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

  std::cout << "\n\n===========[ MEMBER FUNCTIONS ]===========\n";
  {
    std::cout << "\n[ BEGIN ]\n";
    RB_TREE::iterator it(bst.begin());
    RB_TREE::const_iterator itc(bst.begin());
    std::cout << "Begin Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Begin Const:  " << KOV<TYPE>()(*itc) << "\n";
  }

  {
    std::cout << "\n[ END - 1 ]\n";
    RB_TREE::iterator it(bst.end());
    RB_TREE::const_iterator itc(bst.end());
    it--;
    itc--;
    std::cout << "Begin Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Begin Const:  " << KOV<TYPE>()(*itc) << "\n";
  }

  std::cout << "\n\n================[ ITERATOR ]================\n";
  {
    std::cout << "\n[ TAG ]\n";
    std::cout << "Normal: ";
    std::cout << typeid(RB_TREE::iterator::iterator_category).name();
    NEWLINE
    std::cout << "Const:  ";
    std::cout << typeid(RB_TREE::const_iterator::iterator_category).name();
    NEWLINE
    NEWLINE
  }

  {
    std::cout << "\n[ LOOP FROM (BEGIN) ]\n";
    RB_TREE::iterator it = bst.begin();
    RB_TREE::const_iterator itc = bst.begin();
    std::cout << "Normal: ";
    for (; it != bst.end(); it++) {
      std::cout << KOV<TYPE>()(*it) << " ";
    }
    NEWLINE
    std::cout << "Const:  ";
    for (; itc != bst.end(); itc++) {
      std::cout << KOV<TYPE>()(*itc) << " ";
    }
    NEWLINE
  }
  {
    std::cout << "\n[ LOOP FROM (END) ]\n";
    RB_TREE::iterator it = bst.end();
    RB_TREE::const_iterator itc = bst.end();
    it--;
    itc--;
    std::cout << "Normal: ";
    for (; it != bst.begin(); it--) {
      std::cout << KOV<TYPE>()(*it) << " ";
    }
    std::cout << KOV<TYPE>()(*it) << " ";
    NEWLINE
    std::cout << "Const:  ";
    for (; itc != bst.begin(); itc--) {
      std::cout << KOV<TYPE>()(*itc) << " ";
    }
    std::cout << KOV<TYPE>()(*itc) << " ";
    NEWLINE
  }

  {
    std::cout << "\n[ * ]\n";
    RB_TREE::iterator it0(bst.begin());
    RB_TREE::iterator it = it0;
    RB_TREE::const_iterator itc0(bst.begin());
    RB_TREE::const_iterator itc = itc0;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }

  //   {
  //     std::cout << "\n[ -> ]\n";
  //     RB_TREE::iterator it0(bst.begin());
  //     RB_TREE::iterator it = it0;
  //     RB_TREE::const_iterator itc0(bst.begin());
  //     RB_TREE::const_iterator itc = itc0;
  //     std::cout << "Normal: " << it->first << "\n";
  //     std::cout << "Const:  " << itc->first << "\n";
  //   }

  {
    std::cout << "\n[ ++ PRE-INCREMENT ]\n";
    RB_TREE::iterator it(bst.begin());
    RB_TREE::const_iterator itc(bst.begin());
    ++it;
    ++itc;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }
  {
    std::cout << "\n[ POST-INCREMENT ++ ]\n";
    RB_TREE::iterator it(bst.begin());
    RB_TREE::const_iterator itc(bst.begin());
    it++;
    itc++;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }

  {
    std::cout << "\n[ -- PRE-DECREMENT ]\n";
    RB_TREE::iterator it(bst.begin());
    RB_TREE::const_iterator itc(bst.begin());
    ++it;
    ++itc;
    --it;
    --itc;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }
  {
    std::cout << "\n[ POST-DECREMENT -- ]\n";
    RB_TREE::iterator it(bst.begin());
    RB_TREE::const_iterator itc(bst.begin());
    it++;
    itc++;
    it--;
    itc--;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }

  std::cout << "\n\n================[ RELATIONAL OPERATORS ]================\n";
  {
    std::cout << "\n[ EQUAL == (TRUE) ]\n";
    RB_TREE::iterator it1(bst.begin());
    RB_TREE::iterator it2(bst.begin());
    RB_TREE::const_iterator itc1(bst.begin());
    RB_TREE::const_iterator itc2(bst.begin());
    std::cout << "Normal:           " << (it1 == it2) << "\n";
    std::cout << "Const:            " << (itc1 == itc2) << "\n";
    std::cout << "Normal == Const:  " << (it1 == itc1) << "\n";
  }
  {
    std::cout << "\n[ EQUAL == (FALSE) ]\n";
    RB_TREE::iterator it1(bst.begin());
    RB_TREE::iterator it2(bst.begin());
    RB_TREE::const_iterator itc1(bst.begin());
    RB_TREE::const_iterator itc2(bst.begin());
    std::cout << "Normal:           " << (++it1 == it2) << "\n";
    std::cout << "Const:            " << (++itc1 == itc2) << "\n";
    std::cout << "Normal == Const:  " << (++it2 == itc2) << "\n";
  }

  {
    std::cout << "\n[ DIFFERENT != (TRUE) ]\n";
    RB_TREE::iterator it1(bst.begin());
    RB_TREE::iterator it2(bst.begin());
    RB_TREE::const_iterator itc1(bst.begin());
    RB_TREE::const_iterator itc2(bst.begin());
    std::cout << "Normal:           " << (++it1 != it2) << "\n";
    std::cout << "Const:            " << (++itc1 != itc2) << "\n";
    std::cout << "Normal != Const:  " << (++it1 != itc1) << "\n";
  }
  {
    std::cout << "\n[ DIFFERENT != (FALSE) ]\n";
    RB_TREE::iterator it1(bst.begin());
    RB_TREE::iterator it2(bst.begin());
    RB_TREE::const_iterator itc1(bst.begin());
    RB_TREE::const_iterator itc2(bst.begin());
    std::cout << "Normal:           " << (it1 != it2) << "\n";
    std::cout << "Const:            " << (itc1 != itc2) << "\n";
    std::cout << "Normal != Const:  " << (it2 != itc2) << "\n";
  }

  std::cout << "\n\n================[ REVERSE ITERATOR ]================\n";
  {
    std::cout << "\n[ TAG ]\n";
    std::cout << "Normal: ";
    std::cout << typeid(RB_TREE::reverse_iterator::iterator_category).name();
    NEWLINE
    std::cout << "Const:  ";
    std::cout << typeid(RB_TREE::const_reverse_iterator::iterator_category).name();
    NEWLINE
    NEWLINE
  }

  {
    std::cout << "\n[ * ]\n";
    RB_TREE::reverse_iterator it0(bst.begin());
    RB_TREE::reverse_iterator it = it0;
    RB_TREE::const_reverse_iterator itc0(bst.begin());
    RB_TREE::const_reverse_iterator itc = itc0;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }

  //   {
  //     std::cout << "\n[ -> ]\n";
  //     RB_TREE::reverse_iterator it0(bst.begin());
  //     RB_TREE::reverse_iterator it = it0;
  //     RB_TREE::const_reverse_iterator itc0(bst.begin());
  //     RB_TREE::const_reverse_iterator itc = itc0;
  //     std::cout << "Normal: " << it->first << "\n";
  //     std::cout << "Const:  " << itc->first << "\n";
  //   }

  {
    std::cout << "\n[ ++ PRE-INCREMENT ]\n";
    RB_TREE::iterator it0(bst.begin());
    RB_TREE::const_iterator itc0(bst.begin());
    it0++;
    itc0++;
    it0++;
    itc0++;
    RB_TREE::reverse_iterator it(it0);
    RB_TREE::const_reverse_iterator itc(itc0);
    ++it;
    ++itc;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }
  {
    std::cout << "\n[ POST-INCREMENT ++ ]\n";
    RB_TREE::iterator it0(bst.begin());
    RB_TREE::const_iterator itc0(bst.begin());
    it0++;
    itc0++;
    it0++;
    itc0++;
    RB_TREE::reverse_iterator it(it0);
    RB_TREE::const_reverse_iterator itc(itc0);
    it++;
    itc++;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }

  {
    std::cout << "\n[ -- PRE-DECREMENT ]\n";
    RB_TREE::iterator it0(bst.begin());
    RB_TREE::const_iterator itc0(bst.begin());
    RB_TREE::reverse_iterator it(it0);
    RB_TREE::const_reverse_iterator itc(itc0);
    --it;
    --itc;
    --it;
    --itc;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }
  {
    std::cout << "\n[ POST-DECREMENT -- ]\n";
    RB_TREE::iterator it0(bst.begin());
    RB_TREE::const_iterator itc0(bst.begin());
    RB_TREE::reverse_iterator it(it0);
    RB_TREE::const_reverse_iterator itc(itc0);
    it--;
    itc--;
    it--;
    itc--;
    std::cout << "Normal: " << KOV<TYPE>()(*it) << "\n";
    std::cout << "Const:  " << KOV<TYPE>()(*itc) << "\n";
  }

  std::cout << "\n\n================[ RELATIONAL OPERATORS ]================\n";
  {
    std::cout << "\n[ EQUAL == (TRUE) ]\n";
    RB_TREE::reverse_iterator it1(bst.begin());
    RB_TREE::reverse_iterator it2(bst.begin());
    RB_TREE::const_reverse_iterator itc1(bst.begin());
    RB_TREE::const_reverse_iterator itc2(bst.begin());
    std::cout << "Normal:           " << (it1 == it2) << "\n";
    std::cout << "Const:            " << (itc1 == itc2) << "\n";
    std::cout << "Normal == Const:  " << (it1 == itc1) << "\n";
  }
  {
    std::cout << "\n[ EQUAL == (FALSE) ]\n";
    RB_TREE::reverse_iterator it1(bst.begin());
    RB_TREE::reverse_iterator it2(bst.begin());
    RB_TREE::const_reverse_iterator itc1(bst.begin());
    RB_TREE::const_reverse_iterator itc2(bst.begin());
    std::cout << "Normal:           " << (--it1 == it2) << "\n";
    std::cout << "Const:            " << (--itc1 == itc2) << "\n";
    std::cout << "Normal == Const:  " << (--it2 == itc2) << "\n";
  }

  {
    std::cout << "\n[ DIFFERENT != (TRUE) ]\n";
    RB_TREE::iterator it1(bst.begin());
    RB_TREE::iterator it2(bst.begin());
    RB_TREE::const_iterator itc1(bst.begin());
    RB_TREE::const_iterator itc2(bst.begin());
    std::cout << "Normal:           " << (--it1 != it2) << "\n";
    std::cout << "Const:            " << (--itc1 != itc2) << "\n";
    std::cout << "Normal != Const:  " << (--it1 != itc1) << "\n";
  }
  {
    std::cout << "\n[ DIFFERENT != (FALSE) ]\n";
    RB_TREE::iterator it1(bst.begin());
    RB_TREE::iterator it2(bst.begin());
    RB_TREE::const_iterator itc1(bst.begin());
    RB_TREE::const_iterator itc2(bst.begin());
    std::cout << "Normal:           " << (it1 != it2) << "\n";
    std::cout << "Const:            " << (itc1 != itc2) << "\n";
    std::cout << "Normal != Const:  " << (it2 != itc2) << "\n";
  }

  NEWLINE
}
