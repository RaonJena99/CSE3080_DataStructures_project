#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 10000000

char str[MAX_STR];
char match[MAX_STR];
int fail[MAX_STR];

int i, j, k, sstr, Max;

int pmatch(int t);

int main(){
  FILE* fp_str = fopen("string.txt", "r");
  FILE* fp_res = fopen("result.txt", "w");

  if(!fp_str){
    printf("The string file does not exist.\n");
    return 0;
  }

  while(fgets(str, MAX_STR, fp_str)){
    if(str[0] == '\n') fprintf(fp_res,"0\n");
    else{
      sstr = strlen(str);
      Max = 0;
      for (int i = 0; str[i] != 0; i++) {
        if(str[i] == '\n') {
          str[i] = 0;
          sstr--;
          break;
        }
      }

      fail[0] = -1;
      for(i = 1 ; i < sstr ; i++){
        j = fail[i - 1];
        while(str[i] != str[j+1] && j >= 0) j = fail[j];
        if(str[i] == str[j+1]) fail[i] = j+1;
        else fail[i] = -1;
      }

      for(k = 0 ; k < sstr ; k++){
        if(fail[k] != -1){
          if(pmatch(k)) break;
        }
        Max++;
      }

      fprintf(fp_res,"%d\n", (sstr)/Max);
    }
  }

  fclose(fp_str);
  fclose(fp_res);
  return 0;
}

int pmatch(int t){
  j=0;

  for(i = 0 ; i < t ; i++){
    match[i] = str[i];
  }

  while(i < sstr){
    if(j == t) j = 0;
    if(str[i] == match[j]){ 
      i++; j++; 
    }
    else if(str[i] != match[j]) break;
  }
  return ((i==sstr) ? 1 : 0);
}