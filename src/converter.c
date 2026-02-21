#include <stdio.h>
#include "converter.h"
#include <stdint.h>

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



float rgbToBWLevel(int red, int green, int blue){   
    float rWeight = 0.299;
    float gWeight = 0.587;
    float bWeight = 0.114;
    float level = rWeight*(red/255.0) + gWeight*(green/255.0) + bWeight*(blue/255.0);
    return level;

}

