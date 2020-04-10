/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;
using namespace KP_FileIO;

//trys to open filename, and return its contents in contents
	//it will strip out only \n's (char return\line feed)
	//returns:
	//SUCCESS all worked, contents string contains all in the file
	//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream myFile;
	string line;

	//open file attempt
	myFile.open(filename.c_str());
	if (!myFile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	//add each line to contents
	while (!myFile.eof()){
		getline(myFile, line);
		contents+=line;
	}
	//close file and return success constant
	myFile.close();
	return SUCCESS;

}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream myfile;
	vector<string>::iterator iterator;

	//open file
	myfile.open(filename.c_str());
	if (!myfile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	//iterate through vector
	for(iterator = myEntryVector.begin(); iterator != myEntryVector.end(); iterator++){
		//write data to file
		myfile << *iterator << endl;
	}

	//close file
	myfile.close();
	return SUCCESS;
}


