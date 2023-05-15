#include<stdio.h>
#include<string.h>

char encryptMsg(char msg[], int key){
    int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0;
    char railMatrix[key][msgLen];
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = msg[i];
        if(row == 0 || row == key-1)
            k= k * (-1);
        row = row + k;
    }
    printf("\nEncrypted Message: \n");
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] != '\n')
                printf("%c", railMatrix[i][j]);
           
               
}
 
void decryptMsg(char enMsg[], int key){
    int msgLen = strlen(enMsg), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = '*';
        if(row == 0 || row == key-1)
            k= k * (-1);
        row = row + k;
    }
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] == '*')
                railMatrix[i][j] = enMsg[m++];
    row = col = 0;
    k = -1;
    printf("\nDecrypted Message: ");
    for(i = 0; i < msgLen; ++i){
        printf("%c", railMatrix[row][col++]);
        if(row == 0 || row == key-1)
            k= k * (-1);
        row = row + k;
    }
}
 
int main(){
    char msg[50];
    char enMsg[50];
    int key;
    printf("enter the message\n");
    scanf("%s", msg);
    printf("enter the key\n");
    scanf("%d",&key);
    printf("Original Message: %s\n", msg);
    encryptMsg(msg, key);
    printf("\nenter the encrypted msg to decrypt\n");
    scanf("%s", enMsg);
    decryptMsg(enMsg, key);
    return 0;
}
