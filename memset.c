#include <stdio.h>
#include <string.h>


void stringfun(){
  char buf[100];

  memset(buf,'a',sizeof(buf));
  printf("%s , %d" , buf , *buf);
  return;
}

int main(){
  stringfun();
  return 0;
}
