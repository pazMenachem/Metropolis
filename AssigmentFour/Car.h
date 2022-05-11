//
// Created by Paz_m on 14/12/2021.
//

#ifndef ASSIGMENTTHREE__CAR_H_
#define ASSIGMENTTHREE__CAR_H_

#include "Road.h"

#include <string>
using namespace std;
class Cross;

class Car {

  /// Using the default "Big Three" is good enough
  /// there are no pointers nor references that require
  /// One of the big three


 public:
  /// Car Constructor
  /// \param id - ID of the Car
  Car(string id);


  ///default Constructor
  ///"its not much, but its an honest Constructor"
  Car();


  /// "its not much, but its an honest getter"
  /// \return the ID of the Car
  string getId()const;


  /// "its not much, but its an honest getter"
  /// \return the Cross the Car is at
  Cross* getCross()const;


  /// "its not much, but its an honest getter"
  /// \return the next car in the list
  Car* getNext()const;


  ///  puts the new car in the linked list
  /// \param car future next car
  void setNext(Car* car);


  /// Moves the car through given Road
  /// Will remove the car from current cross car list
  /// And adds the same car to the cross which the road "heading" to
  /// also increase's the pollution at the given road
  /// \param road
  /// \param carIndex - which index the car is at the linked list
  void moveCar(Road* road,int carIndex);


  /// sets the new cross the car is at
  /// \param newCross
  void setCross(Cross *newCross);


  /// defines whether the car moved this iteration
  void setMove();


  /// returns whether the car already or not
  /// "its not much, but its an honest getter"
  bool getMove()const;

  /// choose which road to go through between the options
  /// abstract method - each class which heirs have they're own option
  virtual int choose() = 0;

  /// returns pollution - abstract method
  virtual double getPollute()const =0;

  /// car destructor
  /// "its not much, but its an honest destructor"
  virtual ~Car();

 private:
  Cross* cross;
  Car* next;
  string id;
  bool moved;
};

#endif //ASSIGMENTTHREE__CAR_H_
