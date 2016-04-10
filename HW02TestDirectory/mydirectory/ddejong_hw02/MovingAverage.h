/****************************************************************
 * Header file for the application class for the moving average
 * program.
 *
 * Author/copyright:  Dion de Jong
 * Date: 7 September 2014
 *
**/

#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class MovingAverage
{
public:
  MovingAverage();
  virtual ~MovingAverage();

  void doMovingAverage(int width, double tolerance);
  void readData(string fileName);
  string toStringTheData();

private:
  vector<double> theData;

  double computeAverage(int start, int width);
};

#endif
