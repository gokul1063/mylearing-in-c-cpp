#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

char* variable_argument(int size , const char* fmt , ...){
  va_list ap;
  va_start(ap, fmt);
  char *buffer;
  buffer = (char*) malloc(size + 1);
  vsnprintf(buffer , size , fmt , ap);
  buffer[size+1] = '\0';
  return buffer;

}

int main(){
  char *buffer ;
  buffer = variable_argument(30, "hello world %d",5);
  printf("%s", buffer);
  free(buffer);
  return 0;
}
