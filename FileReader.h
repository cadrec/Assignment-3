#include <iostream>
#include "Genstack.h"
#include <fstream>
using namespace std;

class FileReader
{
  public:
    FileReader();
    FileReader(string name);
    ~FileReader();
    bool FileCheck();


  private:
    string fileName;
    Genstack<char>* stack;
};
