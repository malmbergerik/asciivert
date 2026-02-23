#include <stdio.h>
#include "converter.h"
#include <stdint.h>

typedef struct{
    float r,g,b;
}Weights;



char ascii[] = 
        "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. "; 
 
char intToAscii(int i){
    return ascii[i];
}

char getAsciiFromLevel(float level, char arr[], uint8_t n, uint8_t range){

    if (range <= 1) return arr[0];

    if (level < 0.0f) level = 0.0f;
    if (level > 1.0f) level = 1.0f;
    
    uint8_t stop = (uint8_t)(level * (range-1) + 0.5f);
    uint8_t actualIndex = (stop * (n - 1)) / (range - 1);

    return arr[actualIndex];
}



float rgbToBWLevel(int red, int green, int blue, char mode){
    
    Weights weight;
    
    //Yuv mode
    if(mode==0){
        weight.r = 0.299;
        weight.g = 0.587;
        weight.b = 0.114;
    }

    //HDTV
    else if(mode==1){
        weight.r = 0.2126;
        weight.g = 0.7152;
        weight.b = 0.0722;
    }

    //HDR
    else{
        weight.r = 0.2627;
        weight.g = 0.6780;
        weight.b = 0.0593;
    }
    
    float level = weight.r*(red/255.0) + weight.g*(green/255.0) + weight.b*(blue/255.0);
    return level;

}

