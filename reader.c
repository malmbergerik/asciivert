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

    float aspec =(float) height / width;
    float charAspect = 0.4;
    int target_w = 160;
    int target_h = (int)(target_w * aspec * charAspect);    
    if(img==NULL){
        printf("Error when parsing the image");
        exit(1);
    }
    
    image.bytePerPixel= 3;
    char *rowbuffer = malloc(target_w +1);

    for(int i = 0; i<target_h; i++){
        for(int j=0; j<target_w; j++){

            unsigned int startx =(int)(j*(float)width/target_w);
            unsigned int starty =(int)(i*(float)height/target_h);
            unsigned int endx =(int)((j+1)*(float)width/target_w);;
            unsigned int endy =(int)((i+1)*(float)height/target_h);
            
            int sum_r =0, sum_g=0,sum_b=0;
            int count=0;
            for(int k=starty; k<endy; k++){
                for(int l=startx; l <endx; l++){
                    unsigned char *pixel = img + (k * width + l) * image.bytePerPixel;
                    sum_r += pixel[0];
                    sum_g += pixel[1];
                    sum_b += pixel[2];
                    count++;
                }
            }
            if(count>0){
                image.r = (uint8_t)(sum_r/count);
                image.g = (uint8_t)(sum_g/count);
                image.b = (uint8_t)(sum_b/count);
            }
            
            image.level = 1.0f - rgbToBWLevel(image.r,image.g,image.b);
            rowbuffer[j] = getAsciiFromLevel(image.level, ascii, 70);           
        }
        rowbuffer[target_w] = '\n';
        fwrite(rowbuffer,1,target_w+1,stdout);
    }
    printf("Loaded image with a width of %ipx, a height of %ipx, and %i channels",width,height,channels);
    stbi_image_free(img);
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent in total : %f s", time_spent);
    printf("width: %i, height; %i",width,height);

}
