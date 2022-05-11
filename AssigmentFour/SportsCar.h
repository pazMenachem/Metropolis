//
// Created by Paz_m on 02/01/2022.
//

#ifndef ASSIGMENTTHREE__SPORTSCAR_H_
#define ASSIGMENTTHREE__SPORTSCAR_H_

#include "Car.h"
class SportsCar: virtual public Car {
  /// Sports Car - Car Successor
  /// No need for Copy constructor or = operator
  /// default will do fine.
 public:
  /// constructor
  SportsCar(string id);
  SportsCar();

  /// choose which road to go through between the options
  virtual int choose();

  /// returns pollution
  virtual double getPollute()const;

  /// destructor
  virtual ~SportsCar();

 private:
  double pollute;

};

#endif //ASSIGMENTTHREE__SPORTSCAR_H_
