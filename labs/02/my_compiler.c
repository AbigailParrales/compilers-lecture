#include <stdio.h>
#include <stdlib.h>

int pCount = 0;
int bkCount = 0;
int bcCount = 0;
int qCount = 0;

void updateCount(char actCh){
    switch (actCh){
    case '(':
        pCount++;
        break;
    case ')':
        pCount--;
        break;
    case '{':
        bkCount++;
        break;
    case '}':
        bkCount--;
        break;
    case '[':
        bcCount++;
        break;
    case ']':
        bcCount--;
        break;
    case '\"':
        qCount++;
        break;

    default:
        break;
    }
}

void getInfo(void){
    
}

int main(int argc,char* argv[]){
    FILE *f = fopen(argv[1], "r"); // "r" for read
    char c ,cPrev; 
    char line = 0;

    // Open file 
    if (f == NULL) { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(f); 
    while (c != EOF){ 
        //printf ("%c", c); 

        updateCount(c);
        
        cPrev=c;
        c = fgetc(f);

        if ((c=='/') && (cPrev=='/')){ //comment detected
            do{c = fgetc(f);}while (c!='\n');   //just continue getting the remaining chars of the line
            
        } 
    } 
  
    fclose(f);

    //parentheses
    if(pCount < 0){printf("There are %d ( missing \n",(pCount+(2*pCount)));}
    if(pCount > 0){printf("There are %d ) missing \n",pCount);}
    //brackets
    if(bkCount < 0){printf("There are %d { missing \n",(bkCount+(2*bkCount)));}
    if(bkCount > 0){printf("There are %d } missing \n",bkCount);}
    //braces
    if(bcCount < 0){printf("There are %d [ missing \n",(bcCount+(2*bcCount)));}
    if(bcCount > 0){printf("There are %d ] missing \n",bcCount);}
    //quotes
    if((qCount%2) != 0){
        printf("There are %d \" missing \n",(qCount%2));
    }

    /*printf("Count p: %d\n",pCount);
    printf("Count bk: %d\n",bkCount);
    printf("Count bc: %d\n",bcCount);
    printf("Count q: %d\n",qCount);*/

    return 0;
}