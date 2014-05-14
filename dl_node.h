/*
 * Name        : DL_node.h
 * Author      : Robbie Reaves
 * Description : header file for DLNode class
 *               
 */

// Header guards to prevent multiple inclusion
#ifndef REAVES_DL_NODE_H_
#define REAVES_DL_NODE_H_

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::stringstream;

/*
 *   
 * DL NODE
 * 
 */
class DLNode {
 public:
  /*
   * Constructor, default/overloaded
   */
  DLNode();
  DLNode(int contents);

  /*
   * destructor
   */
  ~DLNode();
  
  /*
   * mutators and accessors
   */
  
  void SetContents(int contents);
  int GetContents() const;
  void SetNext(DLNode* next_node);
  void SetPrevious(DLNode* previous_node);
  DLNode* GetNext() const;
  DLNode* GetPrevious() const;
 private:
  DLNode* next_node_;
  DLNode* previous_node_;
  int contents_;
};

#endif /* REAVES_DL_NODE_H_ */
