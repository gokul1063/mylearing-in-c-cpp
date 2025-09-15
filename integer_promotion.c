#include <stdio.h>

void function(int key){
  if (key == 'a'){
    printf("entered : %c (%d)" , key , key);
  }
}


int main(){
  char ele = 'a';
  function(ele);

  int ele2 = 'a';
  function(ele2);
}
