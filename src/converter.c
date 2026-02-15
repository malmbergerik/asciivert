#include <stdio.h>
#include "converter.h"
char ascii[] = 
        "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'."; 
 
char intToAscii(int i){
    return ascii[i];
}

char getAsciiFromLevel(float level, char arr[], int n){
    
    if (level < 0.0f) level = 0.0f;
    if(level == 1.0f){
        return ' ';
    }
    if (level > 1.0f) level = 1.0f;

    int index = (int)(level * (n - 1));

    return arr[index];
}



float rgbToBWLevel(int red, int green, int blue){   
    float rWeight = 0.299;
    float gWeight = 0.587;
    float bWeight = 0.114;
    float level = rWeight*(red/255.0) + gWeight*(green/255.0) + bWeight*(blue/255.0);
    return level;

}

