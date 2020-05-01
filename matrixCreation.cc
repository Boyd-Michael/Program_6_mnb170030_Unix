/*
  Filename:  matrixCreation.cc
  Author:    Michael Boyd, Stephen Perkins (His program with added variables)
  Email:     mnb170030@utdallas.edu
  Version:   1.3
  Copyright  2020, All Rights Reserved

  Description:
  Creation the Matrix that the data will show up in
 */

#include <iostream>
#include <stdint.h>
#include <fstream>
#include <string>
#include <sstream>
#include "cdk.h"
#include "program6.h"

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;


void dMatrix(uint32_t mNum, uint32_t vNum, uint64_t numRec, string rec1, string rec2, string rec3, string rec4)
{

  //cout << "strLenght Val: " << setprecision(10) << myRecord->strLength << endl;

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  //cout << "MagNum: " << mNum << "\nVer: " << vNum << "\nNumRec: " << numRec << "\nR1: " << rec1 << endl;

  stringstream ss;
  /*  string mStr;
  ss << hex << uppercase << mNum;
  mStr = "Magic: 0x" + ss.str();
  ss.str("");
  */
  string vStr;
  ss << unsigned(vNum);
  vStr = "Version: " + ss.str();
  ss.str("");

  string nRStr;
  ss << unsigned(numRec);
  nRStr = "NumRecords: " + ss.str();
  ss.str("");

  ss << rec1.length();
  string r1Len = "strlen: " + ss.str();
  ss.str("");

  ss << rec2.length();
  string r2Len = "strlen: " + ss.str();
  ss.str("");

  ss << rec3.length();
  string r3Len = "strlen: " + ss.str();
  ss.str("");

  ss << rec4.length();
  string r4Len = "strlen: " + ss.str();
  ss.str("");

  string mStr;
  ss << hex << uppercase << mNum;
  mStr = "Magic: 0x" + ss.str();
  ss.str("");

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"R0", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"C0", "x", "y", "z"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  //int           boxHeight[MATRIX_HEIGHT+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */

  setCDKMatrixCell(myMatrix, 1, 1, mStr.c_str());
  setCDKMatrixCell(myMatrix, 1, 2, vStr.c_str());
  setCDKMatrixCell(myMatrix, 1, 3, nRStr.c_str());
  drawCDKMatrix(myMatrix, true);

  setCDKMatrixCell(myMatrix, 2, 1, r1Len.c_str());
  setCDKMatrixCell(myMatrix, 2, 2, rec1.c_str());
  drawCDKMatrix(myMatrix, true);
   
  setCDKMatrixCell(myMatrix, 3, 1, r2Len.c_str());
  setCDKMatrixCell(myMatrix, 3, 2, rec2.c_str());
  drawCDKMatrix(myMatrix, true);

  setCDKMatrixCell(myMatrix, 4, 1, r3Len.c_str());
  setCDKMatrixCell(myMatrix, 4, 2, rec3.c_str());
  drawCDKMatrix(myMatrix, true);

  setCDKMatrixCell(myMatrix, 5, 1, r4Len.c_str());
  setCDKMatrixCell(myMatrix, 5, 2, rec4.c_str());
  drawCDKMatrix(myMatrix, true);    /* required  */


  /* so we can see results */
  cin.get();


  // Cleanup screen
  endCDK();
}
