//
// Created by Paz_m on 31/12/2021.
//

#ifndef ASSIGMENTFOUR__MAPIMP_H_
#define ASSIGMENTFOUR__MAPIMP_H_

#include "Map.h"
#include <iostream>
using namespace std;

template <class Key,class Value>
Map<Key,Value>::Map():size(0),head(new Node){}

template<class Key, class Value>
void Map<Key, Value>::insert(const Key &key, const Value &value) {

  if(isEmpty()) // In case Map is empty
  {
    head->key = key;
    head->next = NULL;
    head->value = value;
    size++;
    return;
  }

  // Three next checks exist because further checking includes element ahead checking

  if(head->key == key) // if head's key is the same as new one
  {
    head->value = value;
    return;
  }

  Node* newNode = new Node();

  if(key < head->key)    // If new key should be before head's key
  {
      newNode->key = head->key;
      newNode->value = head->value;
      newNode->next = head->next;
      head->next = newNode;
      head->value = value;
      head->key = key;
      size++;
      return;
  }

  if(head->key < key && size == 1) // If there's only one element and new key is larger
   {
      add(head,key,value,*newNode);
      return;
   }

  Node* tmp = head->next;
  Node* prevTmp = head;

  for(int i = 0;i<size-1; i++,prevTmp=tmp,tmp=tmp->next)
  {
    if(tmp->key == key)
    {
      tmp->value = value;
      return;
    }

    if(key < tmp->key)
    {
      add(prevTmp,key,value,*newNode);
      return;
    }
  }
  add(prevTmp,key,value,*newNode);
}

template<class Key, class Value>
void Map<Key, Value>::add(Node* currentNode,const Key& key,const Value& value,Node &newNode) {
  newNode.value = value;
  newNode.key = key;
  newNode.next = currentNode->next;
  currentNode->next = &newNode;
  size++;
  return;
}

template<class Key, class Value>
Value *Map<Key, Value>::find(const Key &key) {
  if(isEmpty())
    return NULL;

  Node* tmp = head;
  while(tmp)
  {
    if(key == tmp->key)
      return &tmp->value;
    tmp = tmp->next;
  }
  return NULL;
}

template<class Key, class Value>
Key* Map<Key, Value>::findKey(const Key &key) {
  if(isEmpty())
    return NULL;

  Node* tmp = head;
  while(tmp)
  {
    if(key == tmp->key)
      return &tmp->key;
    tmp = tmp->next;
  }
  return NULL;
}

template<class Key, class Value>
bool Map<Key, Value>::deleteKey(Key &key) {

  if(isEmpty())
    return false;

  Node* tmp = head->next;
  Node* tmpPrev = head;
  if(head->key == key)
  {
    delete(head);
    head = tmp;
    size--;
    return true;
  }

  while(tmp)
  {
    if(tmp->key == key)
    {

      tmpPrev->next = tmp->next;
      delete(tmp);
      size--;
      return true;
    }
    tmpPrev = tmp;
    tmp = tmp->next;
  }
  return false;
}

template<class Key, class Value>
void Map<Key, Value>::print() const
{
  for(Node* tmp = head; tmp ; tmp = tmp->next)
    cout << tmp->key << " " << tmp->value << endl;
}

template<class Key, class Value>
int Map<Key, Value>::numOfElements() const {
  return size;
}

template<class Key, class Value>
Map<Key, Value>::~Map() {
  clear();
}

template<class Key, class Value>
bool Map<Key, Value>::isEmpty() {
  return size == 0;
}
template<class Key, class Value>
void Map<Key, Value>::clear() {
  Node* tmp = head;
  while(head)
  {
    head = head->next;
    delete(tmp);
    tmp = head;
  }
  size = 0;
}

#endif //ASSIGMENTFOUR__MAPIMP_H_
