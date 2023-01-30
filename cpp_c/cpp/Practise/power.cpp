/*
there's a function f(a,b), which is defined as follows:
f(a,b) = C*b+D if a = 1
f(a,b) = f(a-1, f(a,b-1)) if a > 1
where C and D are constants.

we want to know if give a,b,C,D what is the value of f(a,b).

we only need the single digits of integer
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>


int f(int a, int b, int C, int D) {
  while (a > 1) {
    int temp = b;
        
    b = f(a, b - 1, C, D);
    a--;
  }
  return (C * b + D) % 10;
}

int main() {
    int a, b, C, D;
    std::cin>>a>>b>>C>>D;

  int result = f(a, b, C, D);
  std::cout << "f(" << a << ", " << b << ") = " << result << std::endl;

  return 0;
}
