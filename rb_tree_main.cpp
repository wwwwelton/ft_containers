#include <iostream>

#include "rb_tree.hpp"

void print_helper(const ft::Rb_tree_node::Node_ptr& root,
                  std::string indent,
                  bool last) {
  // print the tree structure on the screen
  if (root != NULL && root->_data != 0) {
    std::cout << indent;
    if (last) {
      std::cout << "R----";
      indent += "     ";
    } else {
      std::cout << "L----";
      indent += "|    ";
    }

    std::string s_color = root->_color ? "RED" : "BLACK";
    std::cout << root->_data << "(" << s_color << ")" << std::endl;
    print_helper(root->_left, indent, false);
    print_helper(root->_right, indent, true);
  }
  // std::cout<<root->_left->_data<<std::endl;
}

// print the tree structure on the screen
void pretty_print(ft::Rb_tree_node::Node_ptr root) {
  if (root) {
    print_helper(root, "", true);
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
//   bst.delete_node(18);
  pretty_print(bst.get_root());
  bst.delete_node(8);
  //   bst.delete_node(25);
  pretty_print(bst.get_root());
  return 0;
}
