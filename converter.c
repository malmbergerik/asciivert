#include <stdio.h>

int main(void){

    char ascii[] = 
        "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'."; 
    
    for(int i=0; i<69; i++)
    {
        printf("Here is the ascii: %c\n", ascii[i]);
    }
    printf("Hello World\n");
    return 0;
}