/*
 * CSIS1600
 * dataChecks.cpp
 * personal namespace dataChecks
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

namespace dataChecks
{
  /*
   * parameter str - the string to parse into an int
   * returns true if str can be parsed into an int value
   *   false otherwise
   */
   bool isvalidInt(string str)
   {
     int start = 0;
     int i; //index of one character in the string
     bool valid = true;  // assume a valid string
     bool sign = false;  // assume no sign

     if(str.length() == 0)// if the length of the string is 0
    {
        valid = false;//set valid to false
     	return valid;	//return valid
    }

	if(str.at(0) == '-' || str.at(0) == '+')	 // if the first character is '-' or '+'
    {
        sign = true;
        start = 1;//set sign to true and start to 1

        if(!str.at(1))// if there is not at least one character after the sign
        {
            valid = false; //set valid to false
     		return valid; //return valid
        }

    }

 	for(int n = 0; n < str.length(); n++)
    {
        if(!isdigit(str.at(n)))// check if each character in the string is a digit - isdigit(str.at(i))
			 valid = false;// if a character is not a digit, set valid to false
    }
		return valid;  // return valid;

  }

  /*
   * returns the int value entered from the keyboard
   * throws an exception of the value entered
   *   cannot be converted to an int
   *   allows the user to enter another value
   */
  int getInt()
  {
    bool notanint = true;
    string svalue;

    LOOP1:while (notanint)
    {
      try
      {
        cin >> svalue; // get a string from the keyboard
        if(isvalidInt(svalue) == false)// if it is not a valid int throw an excepetion
        {
            throw svalue;
        }
      }
      catch (string e)
      {
        cout << e << " is not a valid integer, please try again."; // print an error messag
        goto LOOP1; // send control back to the while statement
      }
      notanint = false;
    }
    return atoi(svalue.c_str());  // convert to an integer
  }


  /*
   * parameter str - the string to parse into a double
   * returns true if str can be parsed into a double value
   *   false otherwise
   */
  bool isValidDouble(string str)
  {
    if(str.length() == 0)
        return false; // return false if an empty string

    if(str.at(0) == '-' || str.at(0) == '+')// check for a leading sign
    {
        if(!str.at(1)) // start checking for digits after the sign
            return false; // return false if there is not at least one character after the sign
    }
        int counter = 0;
        for(int n = 0; n < str.length(); n++)
        {
            if(str.at(n) == '.')
                counter++;
            // now check the string, which you know
        }// has at least one non-sign character
        if(counter > 1)
            return false;
        // allow for only one decimal point (.)

    return true;//return true;
  }//end isValidDouble()


  /*
   * returns the double value entered from the keyboard
   * throws an exception of the value entered
   *   cannot be converted to a double
   *   allows the user to enter another value
   */
  double getDouble()
  {
    bool notadouble = true;
    string svalue;

    LOOP2:while (notadouble)
    {
      try
      {
        cin >> svalue; // get a string from the keyboard
        if(isValidDouble(svalue) == false)// if it is not a valid double throw an excepetion
            throw svalue;
      }
      catch (string e)
      {
        cout << e << " is not a valid double, please try again.";// print an error messag
        goto LOOP2; // send control back to the while statement
      }
      notadouble = false;
    }
    return atof(svalue.c_str());  // convert to a double
  }//end getAReal()

}  // end of dataChecks namespace

