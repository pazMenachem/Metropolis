//
// Created by Paz_m on 14/12/2021.
//

#include "Cross.h"
Cross::Cross():carHead(NULL),roadHead(NULL),numOfCar(0),numOfRoads(0) {

}
void Cross::insertCar(Car* car) {

  if(!numOfCar)
  {
    carHead = car;
    carHead->setCross(this);
    car->setNext(NULL);
    numOfCar++;

    return;
  }
  Car* tmp = carHead;
  while(tmp->getNext())
    tmp = tmp->getNext();
  tmp->setNext(car);
  car->setCross(this);
  car->setNext(NULL);
  numOfCar++;

}

void Cross::removeCar(int index) {
  numOfCar--;

  Car* tmp = (*this)[index];
  if(!index)
    carHead = carHead->getNext();
  else
    (*this)[index-1]->setNext((*this)[index]->getNext());
  tmp->setNext(NULL);
}

void Cross::insertRoad(double len,int gIndex,Cross& toCross) {
  if(!roadHead)
  {
    roadHead = new Road(len,gIndex);
    roadHead->setCross(&toCross);
    numOfRoads++;
    return;
  }

  Road* newRoad = new Road(len,gIndex);
  newRoad->setNext(roadHead->getNext());
  roadHead->setNext(newRoad);
  newRoad->setCross(&toCross);
  numOfRoads++;

}

Cross::~Cross() {
  clearCars();
  clearRoads();
}

void Cross::clearRoads() {

  Road* tmp = roadHead;
  Road* deleteMe;
  for(int i=0;i<numOfRoads;i++)
  {
    deleteMe = tmp;
    tmp = tmp->getNext();
    delete deleteMe;
  }
  numOfRoads = 0;
}

void Cross::clearCars() {

  Car* tmp = carHead;
  Car* deleteMe;
  while(tmp)
  {
    deleteMe = tmp;
    tmp = tmp->getNext();
    delete deleteMe;
  }
  numOfCar = 0;
}

Car *Cross::operator[](int index) {
  Car* tmp = carHead;

  for(int i = 0;i<index;i++)
    tmp = tmp->getNext();

  return tmp;
}

Road* Cross::operator()(int index) {

  Road* tmp = roadHead;

  for(int i = 0;i<index-1;i++)
    tmp = tmp->getNext();

  return tmp;
}


int Cross::getNumOfCars() {
  return numOfCar;
}
int Cross::getNumOfRoads() {
  return numOfRoads;
}
int Cross::getId() {
  return this->id;
}
void Cross::setId(int ID) {
  this->id = ID;
}



