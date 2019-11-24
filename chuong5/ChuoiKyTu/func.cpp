#include<stdio.h>
#include<string.h>
int kiemTraChuoiDoi(char *str);
void xoaPt(char *str, int n, int *len);
void xoaKhoangChanThua(char *str);
void lk_CHAR_inString(char *str);
int demSoTu(char *str);
char *layTenFILE(char *url);

int kiemTraChuoiDoi(char *str){
   int len = strlen(str);
   for(int i=0; i<len/2; i++)
      if(str[i]!=str[len-i-1])
         return 0;
   return 1;
}

void xoaPt(char *str, int n, int *len){
   for(int i = n; i<*len-1; i++)
      str[i]=str[i+1];
   *len-=1;
}
void xoaKhoangChanThua(char *str){
   int len = strlen(str);
   //xoa dau chuoi
   while(str[0]==' '){
      xoaPt(str, 0, &len);
   }
   //xoa trong chuoi co 2 khoang chan
   for(int i=0; i<len-1;i++)
      if(str[i]==' '&&str[i+1]==' '){
         xoaPt(str, i, &len);
         i--;
      }
   str[len] = '\0';
}
void lk_CHAR_inString(char *str){
   int len = strlen(str);
   for(int i=0; i<len; i++){
      if(str[0]!=' '){
         char c = str[i];
         if(c!=' ')
            printf("%c", c);
         else if(str[i+1]!=' ')
            printf("\n");
      }else{
         xoaPt(str, i, &len);
         i--;
      }
   }  
}
int demSoTu(char *str){
   int dem = 0, len= strlen(str);
   if(str[0]!=' ')
      dem++;
   for(int i=0;i<len-1;i++)
      if(str[i]==' '&&str[i+1]!=' ')
         dem++;
   return dem;
}
char *layTenFILE(char *url, char *fName){
   int i= strlen(url)-1, d=0;
   while(url[i]!='\\')
      i--;
   for(int j=i+1; j<strlen(url);j++)
      fName[d++]=url[i];
   return fName;
}
