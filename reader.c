#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#include "converter.c"


int main(void) {
    clock_t begin = clock();

    int width,height, channels;
    unsigned char *img =  stbi_load("images/flowertest.jpg", &width,&height,&channels,3);

    if(img==NULL){
        printf("Error when parsing the image");
        exit(1);
    }
    
    const int bytePerPixel = 3;

    for(int i = 0; i<height; i++){
        for(int j=0; j<width; j++){
            unsigned char* pixelOffset = img + (j + width * i) * bytePerPixel;
            unsigned int r = pixelOffset[0];
            unsigned int g =pixelOffset[1];
            unsigned int b =pixelOffset[2];
            
            float level = 1.0f - rgbToBWLevel(r,g,b);
            putchar(getAsciiFromLevel(level, ascii, 70));
           

        }
            putchar('\n');        
    }
    

    


    printf("Loaded image with a width of %ipx, a height of %ipx, and %i channels",width,height,channels);
    stbi_image_free(img);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent in total : %f s", time_spent);
}
