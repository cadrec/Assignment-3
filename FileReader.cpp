#include <iostream>
#include "Genstack.h"
#include "FileReader.h"
#include <fstream>
using namespace std;

FileReader::FileReader() { //constructor
  stack = new Genstack<char>();
}

FileReader::FileReader(string name) {
  fileName = name;
  stack = new Genstack<char>();

  FileCheck();
}

FileReader::~FileReader() { //destructor
  delete stack;
}

bool FileReader::FileCheck() {
  string line;
  ifstream fileInputCheck(fileName);
  int check = 0;

  if(!fileInputCheck) {//checks to see if file is found
    check = 1;
    cout << "No file was available with the name " << fileName << endl;

    fileInputCheck.close();

  }

  int LineNum = 0;//counts line number

  while(getline(fileInputCheck, line)) {
    //cout << "test" << endl; //for testing
    for(int i = 0; i < line.length(); ++i) {//checks the current link in while loop to see if each char is a delimiter
      if(line[i] == '(' || line[i] == '{' || line[i] == '[' || line[i] == ')' || line[i] == '}' || line[i] == ']') { //looks for delimiters
        if(line[i] == '(' || line[i] == '{' || line[i] == '[') { //pushes to stack if it is an opening delimiter
          stack->push(line[i]);
        }
        else if(line[i] == ')' || line[i] == '}' || line[i] == ']') { //this will tell user there is a missing opening delimiter
          if(stack->empty()) {
            cout << "Missing opening parameter for "<< line[i] << " at line " << LineNum+1 << endl;
            return false;
          }//rest will check to see if delimeters do not match
          if(stack->peek() == '(' && line[i] != ')') {
            cout << "Missing ) at line " << LineNum+1 << endl;
            return false;
          }
          else if(stack->peek() == '{' && line[i] != '}') {
            cout << "Missing } at line " << LineNum+1 << endl;
            return false;
          }
          else if(stack->peek() == '[' && line[i] != ']') {
            cout << "Missing ] at line " << LineNum+1 << endl;
            return false;
          }
          stack->pop();
        }
      }
    }
    LineNum++;
  }

  if(stack->empty() && check != 1) { //if case hits, syntax is correct
    //cout << check << endl; //for testing
    cout << "All Delimeters matched up." << endl;
    return true;
  }
  else {//if any case hits here, the file is missing a closing parameter
    if(stack->peek() == '(') {
      cout << "Missung closing parameter: )" << endl;
    }
    else if(stack->peek() == '{') {
      cout << "Missung closing parameter: }" << endl;
    }
    else if(stack->peek() == '[') {
      cout << "Missung closing parameter: ]" << endl;
    }
    return false;
  }
  fileInputCheck.close();
}
