#include "Main.h"

/****************************************************************
 * Main program for Homework 2.
 *
 * Author/copyright:  Dion de Jong. All rights reserved.
 * Date: 25 August 2014
 *
**/

int main(int argc, char *argv[])
{
  string fileName = "xinput.txt";
  MovingAverage movingAverage;

  movingAverage.readData(fileName);

  movingAverage.doMovingAverage(5, 0.1);

  movingAverage.doMovingAverage(5, 0.05);

  movingAverage.doMovingAverage(10, 0.1);

  movingAverage.doMovingAverage(10, 0.05);

  return 0;
}

