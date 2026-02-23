#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "reader.h"
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

int main(void) {

    #ifdef _WIN32
    _setmode(_fileno(stdin), _O_BINARY);
    #endif
    printf("\x1b[2J\x1b[H");

    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    int width = 320, height = 240, channels = 3;
    size_t bufsize = width * height * channels;
    fprintf(stderr, "Expecting %zu bytes per frame\n", bufsize);
    unsigned char *buffer = malloc(bufsize);

    if (!buffer) return -1;

    float aspec =(float) height / width;
    float charAspect = 0.4;
    int target_w = 240;
    int target_h = (int)(target_w * aspec * charAspect);

    //char *rowbuffer = malloc(target_w +1);

    fprintf(stderr, "C Program Started. Waiting for data...\n");

    // Read from stdin
    while (fread(buffer, 1, bufsize, stdin) == bufsize) {
        fprintf(stderr, "Frame Received!\n");
        printf("\x1b[H"); 
    // Now buffer contains the image, you can process in C
    // e.g., convert to grayscale
    process_frame(buffer,width,height,3,target_w);
    fflush(stdout); 
    
    }

    free(buffer);
    return 0;
}