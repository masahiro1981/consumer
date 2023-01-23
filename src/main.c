// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Driver code
int main()
{ 
    //Holds one character from file
    char ch;
    //Holds string to be appended
    char buffer[100];

    //declare file pointer
    FILE* fp;

    // Open file in append mode
    printf("Open file for reading /data/sample.conf\n");
    fp = fopen_preload("/data/sample.conf","r");
 

    //Error check
    if (NULL == fp) {
        printf("file can't be opened \n");
	return 0;
    }
 
    //print current content
    printf("content of this file are \n");
    while (!feof(fp)) {
        ch = fgetc(fp);
        printf("%c", ch);
    }
    fclose(fp);
    
    fp = fopen("/data/sample.conf","a");
    if(NULL == fp){
      printf("file cannot be opend as a\n");
      return 0;
    }
   
    printf("Please enter string to be appended =====");
    fgets(buffer,sizeof(buffer), stdin);
    fprintf(fp, "%s", buffer);
    fclose(fp);
    
    return 0;
}
