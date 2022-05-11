//
// Created by Paz_m on 02/01/2022.
//

#include "MASERATI.h"
MASERATI::MASERATI(string id) :Car(id), SportsCar(id) {
}
int MASERATI::choose() {
  return SportsCar::choose();
}
double MASERATI::getPollute() const {
  return LuxuryCar::getPollute();
}
MASERATI::~MASERATI() {

}
