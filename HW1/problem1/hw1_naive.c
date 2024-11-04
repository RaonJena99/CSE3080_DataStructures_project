#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 10000000
#define MAX_PAT 3000

char str[MAX_STR];
int match[MAX_STR];
char pat[MAX_PAT];

int sstr, pstr;
int i, j, ppos, spos = 0, mpos = 1;

int main(){
  FILE* fp_str = fopen("string.txt", "r");
  FILE* fp_pat = fopen("pattern.txt", "r");
  FILE* fp_res = fopen("result_naive.txt", "w");

  if(!fp_str || !fp_pat){
    printf("The string file does not exist.\n");
    return 0;
  }

  fgets(str, MAX_STR, fp_str);
  fgets(pat, MAX_PAT, fp_pat);

  sstr = strlen(str);
  pstr = strlen(pat);
  
  for(i = 0 ; i < sstr ; i++){
    if(str[i] == pat[0]){
      spos = i, ppos = i;
      for(j = 0 ; j < pstr ; j++, spos++){
        if(pat[j] != str[spos]) break;
      }
      if(j == pstr){
        match[mpos++] = ppos;
        match[0]++;
      }
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