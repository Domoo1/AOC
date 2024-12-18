#include <stdio.h>

int main(){
    int safe = 0;
    FILE *file = fopen("numb", "r");
    if (file == NULL){
        return 1;
    }
    int ch;
    int array[6];
    while((ch = getc(file)) != EOF){
        for(int i = 0; (ch != '\n') || (ch != EOF); i++){
            array[i] = ch;
            ch = getc(file);
            printf("%c ",array[i]);
        }
        
    }    
    fclose(file);
    return 0;
}
