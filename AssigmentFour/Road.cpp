//
// Created by Paz_m on 14/12/2021.
//

#include "Road.h"

Road::Road(double len,int gIndex):pollution(0),len(len),next(NULL),toCross(NULL),graphIndex(gIndex) {

}
Road::Road(){
}

Road *Road::getNext() const{
  return this->next;
}
void Road::setNext(Road* road) {
  this->next = road;
}

Cross *Road::getCross() const{
  return toCross;
}
double Road::getPollution() const {
  return this->pollution;
}

int Road::getGraphIndex() const {
  return this->graphIndex;
}
void Road::setCross(Cross* cross)
{
  this->toCross = cross;
}
void Road::setPollution(double c) {
  pollution += (c/len);
}

