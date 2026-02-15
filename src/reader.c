#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#include "converter.h"
#include "reader.h"

typedef struct {
    uint16_t bytePerPixel;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    float level; 
}Image;

void buff_read(unsigned char *buffer, int width, int height, int channels, int target_w, int target_h){
    char *rowbuffer = malloc(target_w +1);
    Image image;

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
                    unsigned char *pixel = buffer + (k * width + l) * 3;
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
    free(rowbuffer);
}

void process_frame(unsigned char *buffer, int width, int height, int channels, int target_w){
    float aspec =(float) height / width;
    float charAspect = 0.4;
    int target_h = (int)(target_w * aspec * charAspect); 
    
    if(buffer==NULL){
        printf("Error when parsing the image");
        exit(1);
    }


    buff_read(buffer, width, height, channels, target_w, target_h);
}


void read_image(void) {
    clock_t begin = clock();
    Image image;
    
    int width,height, channels;
    unsigned char *img =  stbi_load("../images/mario.png", &width,&height,&channels,3);

    process_frame(img,width,height,channels,80);
    stbi_image_free(img);
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent in total : %f s", time_spent);
    printf("width: %i, height; %i",width,height);

}

