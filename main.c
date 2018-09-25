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
    iFile = fopen(argv[1], "r"); // opens input file for read;
    kFile = fopen(argv[2], "r"); // opens key file for read;
    int iLen = getFileLen(iFile); //get file length;
    int kLen = getFileLen(kFile); //get file length;
    iLen++; //to accomodate for EOF character;
    //now we set and load character buffers for both;
    char iBuffer[iLen];
    char kBuffer[iLen];
    //loading character buffer;
    fgets(iBuffer, iLen-1, iFile); //input file should be larger than key file;
    fgets(kBuffer, iLen-1, kFile);
    iBuffer[iLen - 1] = '\0'; //terminating characters;
    kBuffer[iLen - 1] = '\0';
    int i = 0; //incrementor for loop;
    while(i<iLen-1) {
        iBuffer[i] ^= kBuffer[i]; //XORs the current characters;
        i++; //increments;
    }
    iBuffer[i] = '\0'; //EOF character, assures no data was overwritten;
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
