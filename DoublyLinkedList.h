#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "DataType.h"

struct NodeType{
  DataType data;
  NodeType* next;
  NodeType* back;
};

class DoublyLinkedList{

 public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertItem(DataType &item);
  void deleteItem(DataType &item);
  int lengthIs() const;
  void print();

 private:
  int length;
  NodeType* head;
  NodeType* tail;

};

#endif
