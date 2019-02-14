#ifndef LINKEDLIST_HPP
#define	LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"

using namespace std;

/*....DO NOT EDIT BELOW....*/
template <class T>
class LinkedList {
private:
    Node<T>* head;
    int length;
public:

    LinkedList();
    LinkedList(const LinkedList<T>& ll);
    LinkedList<T>& operator=(const LinkedList<T>& ll);
    ~LinkedList();


    Node<T>* getHead() const;
    Node<T>* first() const;
    Node<T>* findPrev(const T& data) const;
    Node<T>* findNode(const T& data) const;
    void insertNode(Node<T>* prev, const T& data);
    void deleteNode(Node<T>* prevNode);
    void clear();
    size_t getLength() const;
    void print() const;
    void swap(int index1, int index2);
};

template <class T>
void LinkedList<T>::print() const {
    const Node<T>* node = first();
    while (node) {
        std::cout << node->getData();
        node = node->getNext();
    }
    cout << std::endl;
}

/*....DO NOT EDIT ABOVE....*/

/* TO-DO: method implementations below */
template <class T>
LinkedList<T>::LinkedList(){
  head = new Node<T>;
}

//copy constructor
//
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll){
    head = new Node<T>; //buraya () geldi
    *this = ll;
}

//deconstructor
template <class T>
LinkedList<T>::~LinkedList(){
  clear();
  delete head;
}


//assignment operator
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll) {
    if (this != &ll){
        clear();
        const Node<T>* r = ll.first();
        Node<T>* p = getHead();

        while (r) {
            insertNode(p, r->getData());
            r = r->getNext();
            p = p->getNext();
        }
    }
    return *this;
}

//first
template<class T>
Node<T>* LinkedList<T>::first() const{
  return head->getNext();
}

//getHead
template <class T>
Node<T>* LinkedList<T>::getHead() const {
  return head;
}

//similar makeempty
template <class T>
void LinkedList<T>::clear(){ //iff prev deletenode
  Node<T>* dummy = getHead();
  while ( dummy->getNext() ){
    Node<T>* temp = dummy->getNext();
    dummy->setNext(temp->getNext());
    delete temp;
    //temp i silince core dump veriyor.
  }
}

//findPrev
template <class T>
Node<T>* LinkedList<T>::findPrev(const T& data) const{
  Node<T> *p = first();
  while (p->getNext()){
    if (p->getNext()->getData() == data) {
      return p;
    }
    p = p->getNext();
  }
  return NULL;
}
// findNode
template <class T>
Node<T>* LinkedList<T>::findNode(const T& data) const{
  Node<T> *p = first();
  while(p) {
    if(p->getData()==data){
      return p;
    }
    p = p->getNext();
  }
  return NULL;
}


//insert bak buna
template <class T>
void LinkedList<T>::insertNode(Node<T>* prev, const T& data){
  Node<T> *newNode = new Node<T>(data);
  if(prev != NULL){                //getNext eklemeden de oluyo
    if( prev->getNext()!=NULL){
      newNode -> setNext(prev -> getNext());
      prev -> setNext(newNode);
      length++;
    }

    else {
      newNode -> setNext(NULL);
      prev -> setNext(newNode);
      length++;
    }

  }
  else{
    newNode -> setNext(first());
    head -> setNext(newNode);
    length++;
  }

}


//delete
template <class T>
void LinkedList<T>::deleteNode(Node<T>* prevNode) {
  if(prevNode){
    if(prevNode->getNext()){
      Node<T> * del = prevNode->getNext();
      prevNode->setNext(del->getNext());
      delete del;
      length = length - 1;
    }
  }
  else if(prevNode == NULL){
    Node<T> * second = first()->getNext();
    Node<T> * firstNode = first();
    head->setNext(second);
    delete firstNode;
    length = length - 1;
  }
}

template<class T>
size_t LinkedList<T>::getLength() const{
  return length;
}

template <class T>
void LinkedList<T>::swap(int index1, int index2){
  if(index1 == index2){
    return;
  }
  else if ( index1>length || index2>length || index1<0 || index2<0){
    return;
  }
  Node<T>* first_prev = head;
  Node<T>* first_cur = first();
  Node<T>* second_prev = first_prev;
  Node<T>* second_cur = first_cur;
  if(index1<index2){
    int count1=0;
    while(index1!=count1){
      first_prev = first_prev->getNext();
      first_cur = first_cur->getNext();
      second_prev = second_prev->getNext();

      count1= count1 +1 ;
    }
    while (index2!=count1) {
      second_prev = second_prev->getNext();
      second_cur = second_cur->getNext();
      count1 = count1 + 1 ;
    }
    first_prev->setNext(second_cur);
    second_prev->setNext(first_cur);
    Node<T>* temp = second_cur->getNext();
    second_cur->setNext(first_cur->getNext());
    first_cur->setNext(temp);

}
  if(index2<index1){
    int count1=0;
    while(index2!=count1){
      first_prev = first_prev->getNext();
      first_cur = first_cur->getNext();
      second_prev = second_prev->getNext();

      count1= count1 +1 ;
    }
    while (index1!=count1) {
      second_prev = second_prev->getNext();
      second_cur = second_cur->getNext();
      count1 = count1 + 1 ;
    }
    first_prev->setNext(second_cur);
    second_prev->setNext(first_cur);
    Node<T>* temp = second_cur->getNext();
    second_cur->setNext(first_cur->getNext());
    first_cur->setNext(temp);

}
}
/* end of your implementations*/
#endif
