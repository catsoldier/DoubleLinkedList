/*
 * Name        : dl_list.h
 * Author      : Robbie Reaves
 * Description : header file for DLList class
 *
 */

// Header guards to prevent multiple inclusion
#ifndef REAVES_DL_LIST_H_
#define REAVES_DL_LIST_H_

#include <iostream>
#include "dl_node.h"
using std::cout;
using std::endl;

/*
 * DLList
 */
class DLList {
 public:
  DLList();
  ~DLList();

  void Clear();
  unsigned int GetSize() const;
  string ToStringForwards() const;
  string ToStringBackwards() const;
  
  
  void PushFront(int contents);
  void PushBack(int contents);
  
  int GetFront() const;
  int GetBack() const;
  void PopFront();
  void PopBack();
  
  bool Exists(int);
  void RemoveFirst(int);
  void RemoveAll(int);
  
  void Insert(int);
  
 private:
  DLNode* head_;
  DLNode* tail_;
  unsigned int size_;
};

#endif /* REAVES_DL_LIST_H_ */
