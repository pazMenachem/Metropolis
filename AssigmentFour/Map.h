//
// Created by Paz_m on 31/12/2021.
//

#ifndef ASSIGMENTFOUR__MAP_H_
#define ASSIGMENTFOUR__MAP_H_


template <class Key,class Value>
class Map {
  /// Generic Map Data Base
  /// The Data Base sorts the keys using their < operator
  /// In Order to use this Data base, Key Class NEEDS < and ==  Operators Defined
  /// Key and Value classes need << operator
  /// --- User is in charge of releasing dynamic memory ---
  /// No need for Copy Constructor nor = Operator, we use only one instance of map
 private:

  struct Node
  {
    Node* next;
    Key key;
    Value value;
  };
  int size;
  Node* head;
  void add(Node* currentNode,const Key& key,const Value& value,Node &newNode);

 public:
  /// Map constructor
  Map();

  /// inserts new Node with Key and Value to the map
  /// use's < operator to sort the values
  void insert(const Key& key,const Value& value);

  /// finds a value by its key, returns value pointer, uses == operator
  Value* find(const Key& key);

  /// finds a key by its key, returns key pointer, uses == operator
  Key* findKey(const Key& key);

  /// Clears map elements
  void clear();

  /// Deletes element by his key, returns true if found, false otherwise, uses == operator.
  bool deleteKey(Key& key);

  /// Prints the map elements by "Key *space* Value", require << operator for Key and Value
  void print()const;

  /// Returns the number of elements in the data base
  int numOfElements()const;

  /// Returns whether the data base is empty of not
  bool isEmpty();

  /// Map Destructor.
  ~Map();

};

#include "MapImp.h"
#endif //ASSIGMENTFOUR__MAP_H_
