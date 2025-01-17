#include <iostream>
// #include "CLikePyType.h"
#include "dataType.h"
using namespace std;

int main() {
    Tuple<int, double, char> t(7, 3.14, 'a');
  
    cout << t.get(1) << endl;

    

    return 0;
}