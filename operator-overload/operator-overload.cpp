#include <iostream>
#include <ostream>
#include <iterator>
#include <algorithm>

using namespace std;

struct int_node {
  // Overload << operator
  // Note: the << binary operator has two arguments with the first one as the ostream
  // object, therefore it cannot be a member function of int_node.
  friend ostream& operator<<(ostream& os, const struct int_node & i);

  // Constructor
  int_node(int v = 0, int_node* p = NULL) : val(v), next(p) {}
  // Copy constructor
  int_node(const int_node& i) : val(i.val), next(i.next) {}

  // Overload == operator
  bool operator==(int i) {return val == i;}
  friend bool operator==(int i, const int_node& node);

  int val;
  int_node* next;
};

bool operator==(int i, const int_node& node) {
  return node.val == i;
}

ostream& operator<<(ostream& os, const struct int_node & i) {
  return os << i.val;
}

// Wrapper class for the linked list node, which plays the role of iterator.
template <class Node> struct node_wrap {
  Node* ptr;

  // Constructor
  node_wrap(Node* p = 0) : ptr(p) {}
  // Copy constructor.
  node_wrap(const node_wrap& i) : ptr(i.ptr) {}

  // Dereference operator
  Node& operator*() {return *ptr;}
  // Get the reference
  Node* operator->() {return ptr;}

  // ///////////////////////////////////////////////////////////////////////////
  // Note: the increment operation still returns the reference to the iterator.
  // However, why the code in the book return the object for the suffix version.
  // This can be understood as: after increment, the iterator is the same
  // iterator as before but points to the next element in the linear structure.
  // If we still return its reference, it does not point to the previous
  // element. That's why we need to create a new iterator and return its copy.

  // ///////////////////////////////////////////////////////////////////////////

  // Increment operator: prefix ++.
  node_wrap& operator++() {ptr = ptr->next; return *this;}
  // Increment operator: suffix ++
  node_wrap operator++(int) {node_wrap tmp = *this; ++(*this); return tmp;}

  // Compare with iterator.
  bool operator==(const node_wrap& i) {return ptr == i.ptr;}
  bool operator!=(const node_wrap& i) {return ptr != i.ptr;}

  // Assignment.
  node_wrap operator=(const node_wrap& i) {ptr = i.ptr; return *this;}
};

// Initialize a linked list.
void InitIntList(int_node* int_list, unsigned int int_list_length) {
  for (unsigned int i = 0; i < (int_list_length - 1); i++) {
    int_list[i].val = (i + 1) * 2;
    int_list[i].next = int_list + i + 1;
  }

  int_list[int_list_length - 1].val = (unsigned int) (int_list_length * 2);
  int_list[int_list_length - 1].next = NULL;
}

// Print a list.
template <class Iterator, class ostream_type> ostream_type& PrintIntList(Iterator first, Iterator last, ostream_type& os) {
  for (; first != last; first++) {
    os << (*first) << " ";
  }

  return os;
}

int main() {
  // Initialize the linked list.
  const unsigned int int_list_length = 10;
  int_node int_list[int_list_length];

  InitIntList(int_list, int_list_length);

  struct node_wrap<int_node> int_list_iterator(int_list);
  struct node_wrap<int_node> int_list_last;

  // Print the list.
  cout << "The integer list is: ";
  PrintIntList<struct node_wrap<int_node>, ostream>(int_list_iterator, int_list_last, cout);
  cout << endl;

  if (int_list[3] == 7) {
    cout << "int_list[3] is equal to 7." << endl;
  }
  else {
    cout << "int_list[3] is not equal to 7." << endl;
  }

  if (7 == int_list[3]) {
    cout << "int_list[3] is equal to 7." << endl;
  }
  else {
    cout << "int_list[3] is not equal to 7." << endl;
  }

  if (int_list[3] == 8) {
    cout << "int_list[3] is equal to 8." << endl;
  }
  else {
    cout << "int_list[3] is not equal to 8." << endl;
  }

  if (8 == int_list[3]) {
    cout << "int_list[3] is equal to 8." << endl;
  }
  else {
    cout << "int_list[3] is not equal to 8." << endl;
  }

  return 0;
}
