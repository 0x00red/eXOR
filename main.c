#include <stdio.h>
#include <stdlib.h>
int getFileLen(FILE *); //gets the length of a file;
int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: eXOR input_file key_file\n");
        return 0;
    }


    //above line checks for the correct arguments, exiting otherwise;
    FILE *iFile; //input file pointer;
    FILE *kFile; //key file pointer;
    iFile = fopen(argv[1], "rb"); // opens input file for binary read;
    kFile = fopen(argv[2], "rb"); // opens key file for binary read;
    int iLen = getFileLen(iFile); //get file length;
    int kLen = getFileLen(kFile); //get file length;
    int maxLen = iLen * kLen; // guarantee we have enough space;
    maxLen++; //to accomodate for EOF character;


    //now we set and load character buffers for both;
    char iBuffer[maxLen];
    char kBuffer[maxLen];


    //loading character buffer;
    fgets(iBuffer, maxLen-1, iFile); //input file should be larger than key file;
    fgets(kBuffer, maxLen-1, kFile);
    iBuffer[maxLen - 1] = '\0'; //terminating characters;
    kBuffer[maxLen - 1] = '\0';


    int i = 0; //incrementor for loop;
    while(i<maxLen-1) {
        iBuffer[i] ^= kBuffer[i]; //XORs the current characters;
        i++; //increments;
    }


    printf("%s\n", iBuffer);
    return 0;
}
int getFileLen(FILE *fp) { //see line 3;
    int len; //used for storing length;
    fseek(fp, 0L, SEEK_END); //moves file indicator to end of file;
    len = ftell(fp); //gets file length;
    rewind(fp); //resets the file indicator;
    return len; //returns the length;
}
