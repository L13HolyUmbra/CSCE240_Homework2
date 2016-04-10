/****************************************************************
 * Cpp file for the application class for the moving average
 * program. This file holds the code for the functions that the 
 * MovingAverage uses. It has functions for reading and ToStringing 
 * the data. It also has functions for computing the averaage of a 
 * certain window and doing the overall moving average of a set of 
 * data. 
 *
 * Author/copyright:  Dion de Jong
 * Date: 7 September 2014
 *
**/

#include "MovingAverage.h"

/****************************************************************
 * Constructor
**/ 
MovingAverage::MovingAverage()
{
}

/****************************************************************
 * Deconstructor
**/ 
MovingAverage::~MovingAverage()
{
}

/****************************************************************
 * computeAverage function
 * Function that will compute the average given the starting item
 * in the array and a given window width. 
**/  
double MovingAverage::computeAverage(int start, int width)
{
  double WindowAverage = 0.0; 
  double WindowTotal = 0.0;   

  //Loop from the starting item to the end of the window, not including the last number subscripted by the start + window. 
  for (int i = start; i < width + start; ++i)
    {
      WindowTotal += theData[i]; 
    }
  //create the average value to return. 
  WindowAverage = WindowTotal/width; 

  return WindowAverage; 
}

/****************************************************************
 * computeAverage function
 * Function that will use computeAverage and loop through the
 * vector and calculate all the values and use the decision
 * metric to decide on which days to buy and sell. 
**/
void MovingAverage::doMovingAverage(int width, double tolerance)
{  
  cout << "Doing the Moving Average. \n";  
  cout << "Compute with 'with' and 'Tolerance'" + Utils::Format(width,4) + " " +  Utils::Format(tolerance,7,3) + "\n";    

  //initialize variables used in this function. 
  double TestValue = 0.0;
  double Percentage = 0.0; 
  double Total = 0.0; 
  string BoS = "";
  
  //Massive loop used for calculations. In order to account for subscripts starting at 0, we must add one to the stop condition. To account for size of window, which prevents correct averages from being calculated near the end of the vector list, subtract the width of the window from the stop condition. 
  for(int i = 0; i < theData.size()-width + 1; ++i)
    { 
      //Test value is the last value in the window divided by the average of that window. For the last value in the window, we must add i to make sure our window starts at the corrct subscript in the vector, and then we must substract 1 to account for subscripts starting at 0. 
      TestValue = (theData[i+width-1]/computeAverage(i, width));
      //Percentage is this the percentage difference of these two values as a decimal. 
      Percentage = ((1- TestValue));  
     
      //if that number is greater than or equal to the tolerance, the last value is more than 5% cheaper, therefore we should buy stock since it is low. 
      if (Percentage >= tolerance) 
        { 
          BoS = "BUY";   
        } 
     
      //Here we compare to a negative tolerance, to account for negative percentages. The percentage value will be negative if the last value is bigger than the average and we stract that value from 1. If this percentage value is less than or equal to the negative of the tolerance, we know that the stock has risen by more than 5% and we should sell. 
      else if (Percentage <= (tolerance * -1))
        {
          BoS = "SELL";  
        }
     
      //If the percentage value falls in the range of -.0499999 - .499999, nothing happens, so there is no buy or sell command. 
      else 
        {
          BoS = ""; 
        }
    
     //recalculate the total number of the window size to add to the display string. 
     Total = computeAverage(i, width)*width; 
    
     //loop for adding the values average to the display string 
     for (int j = i; j < i + width; ++j) 
       {
         cout <<  Utils::Format(theData[j],7,3) + " "; 
       }   
      
       //Add the total of the window size, the average, the testvalue, and the the buy or sell decision to the display string and cout it. 
       cout << ": "; 
       cout << Utils::Format(Total,7,3) + ": "; 
       cout << Utils::Format(computeAverage(i, width),7,3) + " ";
       cout << Utils::Format(TestValue,7,3) + " ";
       //ArrayString += Utils::Format(Percentage,4) + " "; 
       cout <<  Utils::Format(BoS,7) + "\n"; 
     }
    
   cout << "Leaving DoMovingAverage.";        
}

/****************************************************************
 * computeAverage function
 * this function will read the Data from the input file and push
 * it into a vector of doubles.  
**/
 
void MovingAverage::readData(string fileName)
{
  cout << "Reading Data from input \n"; 
  //create the Scanner from the utils to take in the data. 
  Scanner MyScanner; 
  MyScanner.openFile(fileName);
  
  double StockPrice = 0.0; 

  //push this data into the vector. 
  while(MyScanner.hasNext())
  {
    StockPrice = MyScanner.nextDouble(); 
    this->theData.push_back(StockPrice);  
  }
  cout << "Vector filled with Data \n"; 
  MyScanner.close();
//  cout << toStringTheData();   
}

/****************************************************************
 * computeAverage function
 * this function takes all the double values in a vector of
 * doubles and formats them to a string. 
**/
string MovingAverage::toStringTheData()
{
  string ReturnString = ""; 
  for (int i = 0; i < theData.size(); i++)
    {
      ReturnString += Utils::Format(theData[i]) + " "; 
    } 
  return ReturnString; 
}
