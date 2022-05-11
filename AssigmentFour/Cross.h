//
// Created by Paz_m on 14/12/2021.
//

#ifndef ASSIGMENTTHREE__CROSS_H_
#define ASSIGMENTTHREE__CROSS_H_

#include "Car.h"
#include "FamilyCar.h"
#include "LuxuryCar.h"
#include "SportsCar.h"
#include "MASERATI.h"

class Cross {

/// No need for copy constructor - the amount of roads are pre-made from input and never changed
/// No need for operator= overRide - Roads will not change from the same reason above

 public:
  /// Default Cross Constructor
  /// "its not much, but its an honest Constructor"
  Cross();

  /// inserts the given car into the Cross
  /// \param car
  void insertCar(Car* car);

  /// removes the car from the Cross
  /// \param index the index which the car is found at the cars linked list
  void removeCar(int index);

  /// creates new Road from the Cross
  /// \param len length of the new Road
  /// \param gIndex the index the road is at the graph (only By Col)
  /// \param toCross which cross the Road is "heading" to
  /// \param c pollution parameter
  void insertRoad(double len,int gIndex,Cross& toCross);

  /// "its not much, but its an honest getter"
  /// \return  amount of cars at the Cross
  int getNumOfCars();

  /// "its not much, but its an honest getter"
  /// \return  amount of roads which head out from the cross
  int getNumOfRoads();


  /// \param index
  /// \return the Car from the linked list at specified index
  Car* operator[](int index);


  /// \param index
  /// \return the Road from the linked list at specified index
  Road* operator()(int index);

  /// Destructor
  ~Cross();

  /// returns cross ID
  int getId();

  /// sets cross ID
  void setId(int ID);

 private:
  Car* carHead;
  Road* roadHead;
  int numOfCar;
  int numOfRoads;
  int id;

  /// Destructor functions
  void clearRoads();
  void clearCars();
};

#endif //ASSIGMENTTHREE__CROSS_H_
