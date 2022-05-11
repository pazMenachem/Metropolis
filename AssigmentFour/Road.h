//
// Created by Paz_m on 14/12/2021.
//

#ifndef ASSIGMENTTHREE__ROAD_H_
#define ASSIGMENTTHREE__ROAD_H_

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include "Map.h"




#define error() {cerr << "ERROR: Invalid input."; \
exit(1);}


class Cross;


///
/// No need for Copy Constructor nor = operator
/// since all pointers start as nulls
/// default "Big Three" are good enough
///


class Road {
 public:
/// Road Constructor
/// \param len - length of the road
/// \param gIndex which index the road is at the road graph
  Road(double len,int gIndex);

/// default Road Constructor
///"its not much, but its an honest Constructor"
  Road();

  /// \return the next Road in the linked list
  Road* getNext()const;

  /// Sets the next road ahead in the linked list
  /// \param road - next road
  void setNext(Road* road);

  ///
  /// \return the Cross the Road is "heading" to
  Cross* getCross()const;

  ///
  /// \return the pollution the road is having at the moment
  double getPollution()const;

  ///
  /// \return the index the road is coordinated in the graph ( does NOT include which row )
  int getGraphIndex()const;

  /// Sets the cross the road is "heading" to
  void setCross(Cross* cross);

  /// Update the pollution of the road
  void setPollution(double c);

 private:
  double pollution;
  double len;
  Road* next;
  Cross* toCross;
  int graphIndex;
};

#endif //ASSIGMENTTHREE__ROAD_H_
