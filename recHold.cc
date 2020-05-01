/*
  Filename:  recHold.cc
  Date:      4/28/2020
  Author:    Michael Boyd
  Email:     mnb170030@utdallas.edu
  Version:   1.0
  Copyright: 2020, All Rights Reserved
  
  Description:
   Reads Binary Files

 */
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include "program6.h"

const int maxRecordStringLength = 25;

class BinaryFH
{
 public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;

  void setMagicNum()
  {
    //Sets magic numebr
    magicNumber = 0xFEEDFACE;
  }
  void setVersion()
  {
    //Sets Version Number
    versionNumber = 16;
  }
  void setNumRecords()
  { 
    //Sets Number of inputted Records
    numRecords = 4;
  }

  uint32_t getMagNum()
  {
    //Returns current Magic Number
    return magicNumber;
  }

  uint32_t getVerNum()
  {
    //returns current Version Number
    return versionNumber;
  }

  uint64_t getNumRec()
  {
    //returns Current Number of Records
    return numRecords;
  }

};

int write_Header(std::string filename)
{
  std::ofstream outFile;
  outFile.open(filename.c_str(), std::ios::binary | std::ios::out);
  if(!outFile)
    {
      //Checks to see if File BinaryFileTesting.Bin has failed to create
      std::cerr << "Error: File Creation\n";
    }

  BinaryFH headRec;
  //Writes to new Binary File
  headRec.setMagicNum();
  headRec.setVersion();
  headRec.setNumRecords();
  outFile.write((char *)&headRec, sizeof(headRec));

  return headRec.getNumRec();
}



class BinaryFR
{
 public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];

  void setData()
  {
    //Was used for testing purpose
  }

  char* getStrBuf()
  {
    //Returns current Record Data
    return stringBuffer;
  }

};

void write_Data(std::string filename)
{
  //Creates new Binary file
  write_Header(filename);
  std::ofstream outFile;
  outFile.open(filename.c_str(), std::ios::binary | std::ios::app);
  
  //Adding Records
  BinaryFR dataRec;
  strcpy(dataRec.stringBuffer, "Seed Money");
  outFile.write((char *)&dataRec, sizeof(dataRec));

  strcpy(dataRec.stringBuffer, "Leadership");
  outFile.write((char *)&dataRec, sizeof(dataRec));

  strcpy(dataRec.stringBuffer, "Enrepreneurship");
  outFile.write((char *)&dataRec, sizeof(dataRec));

  strcpy(dataRec.stringBuffer, "Skillz");
  outFile.write((char *)&dataRec, sizeof(dataRec));
  
  outFile.close();
}

void displayRecords(std::string filename)
{
  //Checks for default value
  if(filename == "default")
    {
      filename = "BinaryFileTesting.bin";
      write_Data(filename);
    }
  else;
  
  //Opening File
  std::ifstream inFile;
  inFile.open(filename.c_str(), std::ios::binary);
  
  //Variable Creation
  uint32_t x;
  uint32_t y;
  uint64_t z;
  int state;

  char* temp;
  std::string str1; 
  std::string str2;
  std::string str3;
  std::string str4;

  BinaryFH headRec;
  BinaryFR dataRec;

  //Reading Magic Number, Version Number, and Number of Records
  inFile.read((char *)&headRec, sizeof(headRec));

  x = headRec.getMagNum();
  y = headRec.getVerNum();
  z = headRec.getNumRec();

  //Check Number of Records
  state = z;
  if(state > 4)
    state = 4;
  else;

  //If Gets number of records between 1-4
  switch(state)
    {
    case 4:
      inFile.read((char *)&dataRec, sizeof(dataRec));
      temp = dataRec.getStrBuf();
      str4 = temp;
    case 3:
      inFile.read((char *)&dataRec, sizeof(dataRec));
      temp = dataRec.getStrBuf();
      str3 = temp;
    case 2:
      inFile.read((char *)&dataRec, sizeof(dataRec));
      temp = dataRec.getStrBuf();
      str2 = temp;
    case 1:
      inFile.read((char *)&dataRec, sizeof(dataRec));
      temp = dataRec.getStrBuf();
      str1 = temp;
      break;
    default:
      std::cerr << "\nError\n";
    }

  inFile.close();

  //Starting The Display of the Records in Matrix format
  dMatrix(x, y, z, str1, str2, str3, str4);
}
