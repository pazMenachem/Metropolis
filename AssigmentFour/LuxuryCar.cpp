//
// Created by Paz_m on 02/01/2022.
//

#include "LuxuryCar.h"
#include "Cross.h"
LuxuryCar::LuxuryCar(string id) : Car(id),pollute(3){

}
LuxuryCar::LuxuryCar() {

}
int LuxuryCar::choose() {
  srand (time(NULL));
  if(rand() % 2)
    return rand() % (this->getCross()->getNumOfRoads())+1;
  return 0;
}
double LuxuryCar::getPollute() const {
  return this->pollute;
}
LuxuryCar::~LuxuryCar() {

}

