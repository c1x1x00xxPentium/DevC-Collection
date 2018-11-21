#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
  srand(time(NULL));
  int tmp = 0;
  tmp = rand()%10 +1;
  cout << "Output Random = " << tmp << endl;
  
  return 0 ;
}
