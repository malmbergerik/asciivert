#include <stdio.h>
char ascii[] = 
        "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'."; 
 
char intToAscii(int i){
    return ascii[i];
}

float rgbToBWScale(float red, float green, float blue){
    
    float rWeight = 0.299;
    float gWeight = 0.587;
    float bWeight = 0.114;

    float level = rWeight*(red/255.0) + gWeight*(green/255.0) + bWeight*(blue/255.0);

    return level;

}

int main(void){   
    for(int i=0; i<69; i++)
    {
        printf("Here is the ascii: %c\n", ascii[i]);
    }
    char charact = intToAscii(0);
    printf("Hello World\n");
    printf("This ascii %c \n", charact);
    float level = rgbToBWScale(180,255,255);
    printf("This level shold be 1 : %f", level);
    return 0;
}