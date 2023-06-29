#include<stdio.h>
#include<stdbool.h>

int main() {
   bool jeOK = true; 
   int stevec = getchar() - '0';
   getchar();
   int st = getchar() - '0';
   int prvi = st;
   getchar();
   for(int i = 0; i < stevec - 1; i++) {
        st = getchar() - '0';
        getchar();
        if(st != prvi) {
            jeOK = false;
        }
   }
   if(jeOK) {
        putchar('1');
   }
   else {
        putchar('0');
   } 
   putchar('\n');
   return 0;
}