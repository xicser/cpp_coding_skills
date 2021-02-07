#ifndef __STREAM_OPERATOR_H__
#define __STREAM_OPERATOR_H__

#include <string>

using namespace std;

void testInputOutputNum(void);
void testInputOutputString(void);
void testInputOutputObj(void);

class Employee
{
private:
    int id;
    string name;
    string addr;

public:
    void setId(void);
    void setName(void);
    void setAddr(void);
    int getId(void);
    string getName(void);
    string getAddr(void);
};

#endif // __STREAM_OPERATOR_H__
