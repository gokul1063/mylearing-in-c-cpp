#include <stdio.h>

void callFuncionForStaticVariable(){
  static int i = 0;
  printf("%d \n" , i++);
  return;
}
int main(){
  for (int i = 0 ; i < 10 ; i++){
    callFuncionForStaticVariable();

  }
  return 0;

}

/* THE EXPECTED RESULT IS 
      0
      1
      2
      ...
      9

*/
