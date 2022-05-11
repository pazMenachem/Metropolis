//
// Created by Paz_m on 14/12/2021.
//

#ifndef ASSIGMENTTHREE__METROPOLIS_H_
#define ASSIGMENTTHREE__METROPOLIS_H_

#include "Cross.h"



class Metropolis {

/// Using the default "Big Three" is good enough
/// there are no pointers nor references that require
/// One of the big three

 public:

  /// Metropolis Constructor
  Metropolis(double** graph,unsigned int size);

  ///default Constructor
  ///"its not much, but its an honest Constructor"
  Metropolis();

  /// "Runs" the amount of given iterations and prints the result of the "city"
  /// Will print the "city" at the begging if the amount of given iteration is 0
  void iteration();

  /// "runs" one iteration
  void iterationBeat();

  /// moves all the cars from the cross
  /// * a car can also stay at the cross
  /// \param cross index of the cross
  void carMoving(unsigned int cross);

  /// prints the Cross's and the Cars which "parking" there at the moment
  void printCars() const;

  /// prints a graph of the "city" and the pollution of each Road
  void printPollution() const;

  /// checks whether the given Graph is valid, if so it will update the "city's graph", line by line.
  /// \param line the line which needs to be checked
  /// \param len the given length that each line should be checked by
  /// \param indexCheck the index of the row, used to check whether its 0 in the diagonal
  /// \param testGraph the graph the being tested
  static void checkArgsMap(string line,int len,int indexCheck,double** testGraph);

  /// sets the cars in the "city"
  /// \param line string of cars ID which passed by using tokenizer
  /// \param index which row/cross by the given graph
  /// \param met the metropolitan
  static void carsSetup(string line,int index,Metropolis& met);

  /// receive from user pollution parameter and how many times the simulation will "run"
  /// \param pol
  /// \param times
  void setupInputs(int&times);

  ///Metropolitan destructor
  ~Metropolis();

 private:

  Cross* cList;
  unsigned int size;
  bool reset;
  unsigned int numOfSim;
  Map<string,int> map;

  /// set up for the metropolitan
  /// \param graph
  void setup(double** graph);
};

#endif //ASSIGMENTTHREE__METROPOLIS_H_
