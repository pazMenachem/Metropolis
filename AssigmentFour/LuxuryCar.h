//
// Created by Paz_m on 02/01/2022.
//

#ifndef ASSIGMENTTHREE__LUXURYCAR_H_
#define ASSIGMENTTHREE__LUXURYCAR_H_

#include "Car.h"
class LuxuryCar : virtual public Car{
  /// Luxury Car - Car Successor
  /// No need for Copy constructor or = operator
  /// default will do fine.

 public:
  /// Constructors
  LuxuryCar(string id);
  LuxuryCar();

  /// returns pollution
  virtual double getPollute()const;

  /// choose which road to go through between the options
  virtual int choose();

  /// Destructor
  virtual ~LuxuryCar();

 private:
  double pollute;
};

#endif //ASSIGMENTTHREE__LUXURYCAR_H_
