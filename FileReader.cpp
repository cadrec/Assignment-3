#include <iostream>
#include "Genstack.h"
#include "FileReader.h"
#include <fstream>
using namespace std;

FileReader::FileReader() {
  stack = new Genstack<char>();
}

FileReader::FileReader(string name) {
  fileName = name;
  stack = new Genstack<char>();

  FileCheck();
}

FileReader::~FileReader() {
  delete stack;
}

bool FileReader::FileCheck() {
  string line;
  ifstream UserIn(fileName);
  int check = 0;

  if(!UserIn) {
    check = 1;
    cout << "No file was available with the name " << fileName << endl;

    UserIn.close();

  }

  int LineNum = 0;

  while(getline(UserIn, line)) {
    //cout << "test" << endl; //for testing
    for(int i = 0; i < line.length(); ++i) {
      if(line[i] == '(' || line[i] == '{' || line[i] == '[' || line[i] == ')' || line[i] == '}' || line[i] == ']') {
        if(line[i] == '(' || line[i] == '{' || line[i] == '[') {
          stack->push(line[i]);
        }
        else if(line[i] == ')' || line[i] == '}' || line[i] == ']') {
          if(stack->empty()) {
            cout << "There is no match. Missing opening parameter for "<< line[i] << " at line " << LineNum+1 << endl;
            return false;
          }
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

  if(stack->empty() && check != 1) {
    //cout << check << endl; //for testing
    cout << "All Delimeters matched up." << endl;
    return true;
  }
  else {
    if(stack->peek() == '(') {
      cout << "Reached end of file: missing )" << endl;
    }
    else if(stack->peek() == '{') {
      cout << "Reached end of file: missing }" << endl;
    }
    else if(stack->peek() == '[') {
      cout << "Reached end of file: missing ]" << endl;
    }
    return false;
  }
  UserIn.close();
}
