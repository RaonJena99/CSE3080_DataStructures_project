#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 10000000
#define MAX_PAT 3000

char str[MAX_STR];
int match[MAX_STR];
char pat[MAX_PAT];
int fail[MAX_PAT];

int sstr, pstr;
int i, j, mpos = 1;

int main(){
  FILE* fp_str = fopen("string.txt", "r");
  FILE* fp_pat = fopen("pattern.txt", "r");
  FILE* fp_res = fopen("result_kmp.txt", "w");

  if(!fp_str || !fp_pat){
    printf("The string file does not exist.\n");
    return 0;
  }

  fgets(str, MAX_STR, fp_str);
  fgets(pat, MAX_PAT, fp_pat);

  sstr = strlen(str);
  pstr = strlen(pat);

  fail[0] = -1;
  for(i = 1 ; i < pstr ; i++){
    j = fail[i - 1];
    while((pat[i] != pat[j+1]) && (j >= 0)) j = fail[j];
    if(pat[i] == pat[j+1]) fail[i] = j+1;
    else fail[i] = -1;
  }

  i = 0, j = 0;
  while(i < sstr && j < pstr){
    if(str[i] == pat[j]){
      i++, j++;
    }
    else if(j == 0) i++;
    else j = fail[j-1] + 1;
    if(j == pstr){
      match[0]++;
      match[mpos++] = i - pstr;
      i = i - pstr + 1, j = 0;
    }
  }
  
  fprintf(fp_res,"%d\n", match[0]);
  for(i = 1 ; i <= match[0] ; i++){
    fprintf(fp_res, "%d ", match[i]);
  }
  fprintf(fp_res, "\n");

  fclose(fp_str);
  fclose(fp_pat);
  fclose(fp_res);
  return 0;
}