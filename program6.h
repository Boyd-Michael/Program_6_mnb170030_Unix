/*
  Filename:  program6.h
  Date:      4/28/2020
  Author:    Michael Boyd
  Email:     mnb170030@utdallas.edu
  Version:   1.0
  Copyright: 2020, All Rights Reserved
  
  Description:
  Program's Header File
 */
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>

void dMatrix(uint32_t mNum, uint32_t vNum, uint64_t numRec, std::string rec1, std::string rec2, std::string rec3, std::string rec4);

void write_Data(std::string filename);
void displayRecords(std::string filename);
