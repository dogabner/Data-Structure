#include <iostream>
#include <typeinfo>
#include "stdint.h"
#include "assert.h"
using namespace std;

template <typename T>
class TypeToID
{
  public:
    static int const ID = -1;
};

template <> class TypeToID<uint8_t>
{
public:
    static int const ID = 0;
};

template <>
class TypeToID<void *>
{
  public:
    static int const ID = 0x401d;
};

void PrintID()
{
    cout << "ID of uint8_t: " << TypeToID<uint8_t>::ID << endl;
    cout << "ID of uint8_t: " << TypeToID<void*>::ID << endl;
}

int main(){
    PrintID();
    return 0;
}