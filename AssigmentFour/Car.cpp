//
// Created by Paz_m on 14/12/2021.
//

#include "Car.h"
#include "Cross.h"

Car::Car(string id):cross(NULL),next(NULL),id(id),moved(false) {
}

Car::Car() {
}
string Car::getId() const {
  return this->id;
}
Cross *Car::getCross() const {
  return this->cross;
}

Car* Car::getNext() const {
  return next;
}
void Car::setNext(Car* car) {
  this->next = car;
}

void Car::moveCar(Road* road,int carIndex) {
  road->setPollution(this->getPollute());
  this->getCross()->removeCar(carIndex); // removing from cross
  road->getCross()->insertCar(this); // adding to new cross
}
void Car::setCross(Cross *newCross) {
  this->cross = newCross;
}
void Car::setMove() {
  moved = !moved;
}
bool Car::getMove() const {
  return moved;
}
Car::~Car() {

}

