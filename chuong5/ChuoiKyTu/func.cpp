#include<stdio.h>
#include<string.h>

int kiemTraChuoiDoi(char *str){
   int len = strlen(str);
   for(int i=0; i<len/2; i++)
      if(str[i]!=str[len-i-1])
         return 0;
   return 1;
}

char *xoaPt(char *str, int n, int &len){
   for(int i = n; i<len-1; i++)
      str[i]=str[i+1];
   len--;
}
void xoaKhoangChanThua(char *str){
   int len = strlen(str);
   
}
