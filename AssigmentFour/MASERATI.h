//
// Created by Paz_m on 02/01/2022.
//

#ifndef ASSIGMENTTHREE__MASERATI_H_
#define ASSIGMENTTHREE__MASERATI_H_
#include "LuxuryCar.h"
#include "SportsCar.h"

class MASERATI : public LuxuryCar,public SportsCar{
  /// MASERATI Car - Luxury Car and Sport Car Successor
  /// No need for Copy constructor or = operator
  /// default will do fine.
 public:

  /// constructor
  MASERATI(string id);

  /// choose which road to go through between the options
  int choose();

  /// returns pollution
  double getPollute()const;

  /// destructor
  virtual ~MASERATI();

 private:
};

#endif //ASSIGMENTTHREE__MASERATI_H_
