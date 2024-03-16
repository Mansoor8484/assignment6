#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int decimaltobinary(int convert){
    int binary[32];
    int i = 0;

    while (convert > 0)
    {
        binary[i] = convert % 2;
        convert = convert / 2;
        i++;
    }
    printf("binary representation: ");
    for(int j = i -1; j >= 0; j--){
        printf("%d", binary[j]);
    }
    printf("\n");
    
}

double binarytodecimal(char *binary2){
    int sign = (binary2[0] == '1') ? -1 : 1;
    int exponent = 0;
    double fraction = 1.0;

    for (int i = 1; i <= 8; i++) {
        exponent = exponent * 2 + (binary2[i] - '0');
    }

    for (int i = 9; i < 32; i++) {
        fraction += (binary2[i] - '0') * pow(2, 9 - i);
    }

    return sign * pow(2, exponent) * fraction;

    /*
    long decimal2 = 0;
    int length = strlen(binary2);

    for(int i =0; i < length; i++){
        if(binary2[i] == '1'){
            decimal2 += pow(2, length - 1 - i);
        }
    }
    return decimal2;
    */
    
}



int main(){
    printf("Select the number 1 to convert from binary to decimal.\nSelect 2 to convert from decimal to binary.\n");
    int dec;
    printf("Your choice: ");
    scanf("%d", &dec);
    
    if (dec == 1)
    {
        char bin[33];
        printf("enter a binary number and I will give you floating point the decimal conversion\n");
        printf("your binary number: ");
        scanf("%32s", bin);

        double decimal = binarytodecimal(bin);
        printf("decimal representation: %f", decimal);

    }
    else if(dec == 2)
    {
        int decimal;
        printf("enter a decimal and I will give you the binary conversion\n");
        printf("your decimal number: ");
        scanf("%d", &decimal);

        decimaltobinary(decimal);
    }
    else{
        printf("please select 1 or 2");
    }
    
}
