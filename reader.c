#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#include "converter.c"

typedef struct {
    uint16_t bytePerPixel;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    float level; 
}Image;

int main(void) {
    clock_t begin = clock();


    Image image;

    int width,height, channels;
    unsigned char *img =  stbi_load("images/flowertest.jpg", &width,&height,&channels,3);

    if(img==NULL){
        printf("Error when parsing the image");
        exit(1);
    }
    
    image.bytePerPixel= 3;
    char *rowbuffer = malloc(width +1);

    for(int i = 0; i<height; i++){
        for(int j=0; j<width; j++){
            unsigned char *pixel = img + (j + width * i) * image.bytePerPixel;
            image.r = pixel[0];
            image.g = pixel[1];
            image.b =pixel[2];
            
            image.level = 1.0f - rgbToBWLevel(image.r,image.g,image.b);
            rowbuffer[j] = getAsciiFromLevel(image.level, ascii, 70);           
        }
        rowbuffer[width] = '\n\n';
        fwrite(rowbuffer,1,width+1,stdout);
    }
    printf("Loaded image with a width of %ipx, a height of %ipx, and %i channels",width,height,channels);
    stbi_image_free(img);
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent in total : %f s", time_spent);
    printf("width: %i, height; %i",width,height);

}
