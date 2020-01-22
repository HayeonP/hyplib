#include "CsvLogger.h"

void write_csv_data(FILE *fp, char* data[], int category_num){
  for(int i = 0; i < category_num; i++){
    fputs(data[i], fp);
    if(i==category_num-1)
      fputc('\n',fp);
    else
      fputc(',', fp);
  }
  return;
}