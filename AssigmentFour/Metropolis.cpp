//
// Created by Paz_m on 14/12/2021.
//

#include "Metropolis.h"


Metropolis::Metropolis(double **graph, unsigned int size):cList(new Cross[size]),size(size),reset(true),numOfSim(0) {
  setup(graph);
}

Metropolis::Metropolis() {
}

void Metropolis::setup(double **graph) {

  int times;
  unsigned int col,row;
  setupInputs(times);
  numOfSim = times;
  for(row=0;row<size;row++)
  {
    cList[row].setId(row+1);

    for(col=0;col<size;col++)
      if(graph[row][col] > 0)
        cList[row].insertRoad(graph[row][col],col,cList[col]);
  }

}

void Metropolis::iteration() {

  if(!numOfSim)
  {
    printPollution();
    printCars();
    return;
  }

  for(unsigned int i=0;i<numOfSim;i++)
  {
    iterationBeat();
    reset = !reset;
  }
  printPollution();
  printCars();
}

void Metropolis::iterationBeat() {

  for(unsigned int cross=0;cross<size;cross++)
    carMoving(cross);
}

void Metropolis::carMoving(unsigned int cross) {

  int road,car;

  for(car = cList[cross].getNumOfCars() - 1 ;car > -1;car--)
  {
    Car* handledCar = cList[cross][car];
    if(handledCar->getMove() == reset)
      continue;

    handledCar->setMove();

    if(cList[cross].getNumOfRoads() == 0)
      continue;

    road = handledCar->choose();

    if(!road)
      continue;
    Road* throughRoad = cList[cross](road);
    map.insert(handledCar->getId(),throughRoad->getCross()->getId());
    handledCar->moveCar(throughRoad,car);
  }
}

void Metropolis::printCars() const {

  int car;
  unsigned int row;
  for(row=0;row<size;row++)
  {
    cout << row + 1 << ":";
    for(car=0;car<cList[row].getNumOfCars();car++)
      cout << " " <<cList[row][car]->getId();
    cout << endl;
  }
}
void Metropolis::printPollution() const {
  unsigned int row,road,roadInd;
  for(row=0;row<size;row++)
  {
    if(!cList[row].getNumOfRoads())
      roadInd = -1;
    else
    {
      road = cList[row].getNumOfRoads();
      roadInd = cList[row](road)->getGraphIndex();
    }

      for(unsigned int i=0;i<size;i++)
      {

        if(roadInd == i)
        {
          cout << setprecision(3) << cList[row](road)->getPollution();
          road--;
          if(road>=0)
            roadInd = cList[row](road)->getGraphIndex();
        }
        else
          cout << 0;
        if(i != size -1)
          cout << " ";
      }
    cout << endl;
  }
}
void Metropolis::checkArgsMap(string line,int len,int indexCheck,double **testGraph) {

  int checkSize = 0;
  float x;
  stringstream check(line);
  string checkLine;

  while(getline(check,checkLine,' '))
  {

    checkSize++;
    if(!isdigit(*checkLine.c_str()))
      error()

    x = atof(checkLine.c_str());

    if(indexCheck == checkSize-1)
      if(x)
        error()
    testGraph[indexCheck][checkSize-1] = x;
  }
  if(checkSize > len)
    error()
}
void Metropolis::carsSetup(string line,int cross,Metropolis& met) {

  if(line.empty())
    return;
  else
    line = line.substr(1);
  string id;
  stringstream check(line);
  string checkMe;

  while(getline(check,checkMe,' '))
  {
    id = checkMe;
    met.map.insert(id,met.cList[cross].getId());
    char option = id[0];
    switch(option)
    {
      case 'F':
        met.cList[cross].insertCar((new FamilyCar(id)));
        break;
      case 'S':
        met.cList[cross].insertCar((new SportsCar(id)));
        break;
      case 'L':
        met.cList[cross].insertCar((new LuxuryCar(id)));
        break;
      case 'M':
        met.cList[cross].insertCar((new MASERATI(id)));
        break;
    }
  }
}
void Metropolis::setupInputs(int&times) {
  cin >> times;
}
Metropolis::~Metropolis() {
  delete []cList;
}

