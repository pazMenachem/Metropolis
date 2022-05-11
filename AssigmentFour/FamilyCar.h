//
// Created by Paz_m on 02/01/2022.
//

#ifndef ASSIGMENTTHREE__FAMILYCAR_H_
#define ASSIGMENTTHREE__FAMILYCAR_H_

#include "Car.h"

class FamilyCar : public Car{
  /// Family Car - Car Successor
  /// No need for Copy constructor or = operator
  /// default will do fine.

 public:
  /// constructor
  FamilyCar(string id);

  /// choose which road to go through between the options
  int choose();

  /// returns pollution
  double getPollute()const;

  /// destructor
  virtual ~FamilyCar();

 private:
  double pollute;
};

#endif //ASSIGMENTTHREE__FAMILYCAR_H_
