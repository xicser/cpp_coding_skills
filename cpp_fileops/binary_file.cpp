#include <iostream>
#include <fstream>
#include "binary_file.h"
#include "Employee.h"

using namespace std;

void testBinaryFile(void)
{
    ofstream outfile("object.dat", ios::binary);
    Employee W_empVar;

    W_empVar.setId();
    W_empVar.setName();
    W_empVar.setAddr();

    outfile.write((char *)&W_empVar, sizeof(Employee));
    outfile.close();
}
