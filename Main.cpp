#include <iostream>
#include "Genstack.h"
#include <string>
#include <fstream>
#include "FileReader.h"
using namespace std;

int main(int argc, char** argv) {
  char condition = 'n';
  if(argc > 1) {
    do{
      string fileName = argv[1];
      FileReader file(fileName);
      while(true){
        cout << "Would you like to input a new file to check? Type 'y' to continue. Type anything else to exit." << endl;
        cin >> condition;

        if(condition == 'y'){
          cout << "Enter a new file. Followed by anything after entering file name." << endl;
          cin >> argv[1] >> fileName;
          break;
        }
        else{
          cout << "Exiting Program" << endl;
          break;
        }
      }
    }
    while(condition == 'y');

  }
  else {
    cout << "No file entered on command line!" << endl;
  }
}
