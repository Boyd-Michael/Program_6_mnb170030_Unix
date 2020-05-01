/*
  Filename:   program6.cc
  Date:       4/28/2020
  Author:     Michael Boyd
  Email:      mnb170030@utdallas.edu
  Version:    1.4
  Copyright:  2020, All Rights Reserved

  Description:
  Start of Program

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "program6.h"

using namespace std;

const int MAX_NUMBER_OF_ITEMS = 8;

int main(int argc, char *argv[])
{ 
  bool state;
  char *x = argv[1];
  string filename;

  //Testing Purpose
  if(x == NULL)
    state = true;
  else
    state = true;

  //Loaction Binary File
  cout << "File Location/Name(Type default for binary file creation in current directory): ";
  cin >> filename;
  cin.ignore();

  if(state == true)
    {
      cout << "Starting Display\n";
      //Starting Display
      displayRecords(filename);
    }
  else if(state == false)
    {
      //Testing Purposes
      cout << "Writing to binary file.\n";
      write_Data(filename);
      cout << "Writing Complete.\n";
    }
  else
    cerr << "Error: Filesystem\n";

  return 0;
}

