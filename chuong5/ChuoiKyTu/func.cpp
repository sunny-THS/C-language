#include<stdio.h>
#include<string.h>

int kiemTraChuoiDoi(char *str){
   int len = strlen(str);
   for(int i=0; i<len/2; i++)
      if(str[i]!=str[len-i-1])
         return 0;
   return 1;
}

void xoaPt(char *str){

}
void xoaKhoangChanThua(char *str){
   int len = strlen(str);
   if(str[0]==' ')
      
}
