/*
 * Name        : dl_list.cpp
 * Author      : Robbie Reaves
 * Description : cpp file for DLNode class
 */

// We need to include the header file
#include "dl_list.h"
#include "dl_node.h"

DLList::DLList() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

DLList::~DLList() {
  Clear();
}

void DLList::PushFront(int contents) {
  if(size_ > 0) {
      DLNode* to_insert = new DLNode(contents);
      to_insert->SetNext(head_);
      head_->SetPrevious(to_insert);
      head_ = to_insert;
      size_++;
  } else {
      head_ = new DLNode(contents);
      tail_ = head_;
      size_++;
  }

}
void DLList::PushBack(int contents) {
  if (size_ == 0) {
    DLNode* to_insert = new DLNode(contents);
    tail_ = to_insert;
    head_ = tail_;
    size_++;
  } else if (size_ == 1) {
    head_->SetNext(new DLNode(contents));
    tail_ = head_->GetNext();
    tail_->SetPrevious(head_);
    size_++;
  } else {
    DLNode* to_insert = new DLNode(contents);
    to_insert->SetPrevious(tail_);
    tail_->SetNext(to_insert);
    tail_ = to_insert;
    size_++;
  }
}
void DLList::PopFront() {
  //if(head_ != NULL) {
  if (size_ == 1) {
    delete head_;
    size_--;
  }
  if(size_ > 1) {
    DLNode* temp = head_;
    head_ = head_->GetNext();
    delete temp;
    size_--;
  }
  if (size_ == 1) {
    head_->SetNext(NULL);
    tail_ = head_;
  } else if (size_ == 0) {
    tail_ = NULL;
    head_ = NULL;
    cerr << "List Empty";
  }
}

void DLList::Clear() {
  if (head_ == NULL)
    return;
  while(head_->GetNext() != NULL) {
    DLNode* iterator = head_;
    head_ = head_->GetNext();
    delete iterator;
    size_--;
  }
  delete head_;
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}


unsigned int DLList::GetSize() const {
  return size_;
}

string DLList::ToStringForwards() const {
  if (head_ != NULL) {
    stringstream ss;
    if(size_ == 1) {
      ss << GetFront();
      return ss.str();
    } else if (size_ > 1) {
      DLNode* iterator = head_;
      while(iterator->GetNext() !=NULL) {
        ss << iterator->GetContents() << ", ";
        iterator = iterator->GetNext();
      }
      ss << iterator->GetContents();
      return ss.str();
    }
  } else {
    cerr << "List Empty";
    return "";
  }
  cerr << "List Empty";
  return "";
} 

string DLList::ToStringBackwards() const {
  if (tail_ != NULL) {
    stringstream ss;
    if(size_ == 1) {
      ss << GetBack();
      return ss.str();
    } else if (size_ > 1) {
      DLNode* iterator = tail_;
      while(iterator != head_) {
        ss << iterator->GetContents() << ", ";
        iterator = iterator->GetPrevious();
      }
      ss << iterator->GetContents();
      return ss.str();
    } else {
      cerr << "List Empty";
      return "";
    }
  } else {
    cerr << "List Empty";
    return "";
  }
  cerr << "List Empty";
  return "";
}

void DLList::PopBack(){
  if (head_ != NULL) {
    if(head_ == tail_) {
      PopFront();
    } else {
      DLNode* iterator = head_;
      while(iterator->GetNext() != tail_){
        iterator = iterator->GetNext();
      }
      iterator->SetNext(NULL);
      delete tail_;
      tail_ = iterator;
      size_--;
      if (size_ == 1) {
        head_ = tail_;
      } else if (size_ == 0) {
        head_ = tail_;
      }
    }
  } else {
    cerr << "List Empty";
  }
}
int DLList::GetFront() const{
  if (size_ == 0) {
    cerr << "List Empty";
    return 0;
  } else {
  return head_->GetContents();
  }

}
int DLList::GetBack() const{
  if (size_ == 0) {
    cerr << "List Empty";
    return 0;
  } else {
    return tail_->GetContents();
  }
}

bool DLList::Exists(int to_delete) {
  if (size_ > 0) {
    DLNode* iterator = head_;
    DLNode* trailer = iterator;
    while (iterator->GetNext() != NULL && iterator->GetContents() != to_delete) {
      trailer = iterator;
      iterator = iterator->GetNext();
    }
    if (iterator->GetContents() == to_delete) {
      return true;
    } else {
      return false;
    }
//    if (iterator == head_) {
//      PopFront();
//      return true;
//    } else if (iterator == tail_) {
//      PopBack();
//      return true;
//    } else {
//      trailer->SetNext(iterator->GetNext());
//      iterator->GetNext()->SetPrevious(trailer);
//      delete iterator;
//      size_--;
//      return true;
//    }
    //return false;
  } else {
  return false;
  }
}

void DLList::RemoveFirst(int to_delete) {
if (size_ > 0) {
    DLNode* iterator = head_;
    DLNode* trailer = iterator;
    while (iterator->GetNext() != NULL && iterator->GetContents() != to_delete) {
      trailer = iterator;
      iterator = iterator->GetNext();
    }
    if (iterator->GetContents() != to_delete) {
      cerr << "Not Found";
      return;
    }
    if (iterator == head_) {
      PopFront();
    } else if (iterator == tail_) {
      PopBack();
    } else {
      trailer->SetNext(iterator->GetNext());
      DLNode* temp = iterator->GetNext();
      temp->SetPrevious(trailer);
      delete iterator;
      size_--;
    }
    //return false;
  } else {
    cerr << "Not Found";
  }
  //return false;
}

void DLList::RemoveAll(int to_delete) {
  if (Exists(to_delete)) {
    while (Exists(to_delete) == true) {
      RemoveFirst(to_delete);
    }
  } else 
    cerr << "Not Found";
}

void DLList::Insert(int contents) {
  if(head_ == NULL || contents <= head_->GetContents()) {
    PushFront(contents);
  } else {
    DLNode* iterator = head_;
    DLNode* trailer = iterator;
    while (iterator != NULL && iterator->GetContents() < contents) {
      trailer = iterator;
      iterator = iterator->GetNext();
    }  
    if(iterator == NULL) {
    PushBack(contents);
    } else {
      DLNode* newNode = new DLNode(contents);
      newNode->SetNext(iterator);
      newNode->SetPrevious(trailer);
      trailer->SetNext(newNode);
      size_++;
    }
  }
}