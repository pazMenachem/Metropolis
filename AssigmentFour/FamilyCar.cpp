//
// Created by Paz_m on 02/01/2022.
//

#include "FamilyCar.h"
#include "Cross.h"
FamilyCar::FamilyCar(string id) : Car(id),pollute(2) {

}
int FamilyCar::choose() {
  srand (time(NULL));
  return rand() % (this->getCross()->getNumOfRoads()+1);
}
double FamilyCar::getPollute() const {
  return this->pollute;
}
FamilyCar::~FamilyCar() {

}

