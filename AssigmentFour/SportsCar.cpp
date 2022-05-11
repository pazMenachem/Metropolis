//
// Created by Paz_m on 02/01/2022.
//

#include "SportsCar.h"
#include "Cross.h"
SportsCar::SportsCar(string id) : Car(id),pollute(4) {

}

int SportsCar::choose() {
  srand (time(NULL));
  if(!this->getCross()->getNumOfRoads())
    return 0;
  return (rand() % this->getCross()->getNumOfRoads())+1;
}
double SportsCar::getPollute() const {
  return this->pollute;
}
SportsCar::~SportsCar() {

}
SportsCar::SportsCar() {

}
