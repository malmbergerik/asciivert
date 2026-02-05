#include <stdio.h>
char ascii[] = 
        "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'."; 
 
char int_to_ascii(int i){
    return ascii[i];
}

int main(void){

   
    for(int i=0; i<69; i++)
    {
        printf("Here is the ascii: %c\n", ascii[i]);
    }
    char charact = int_to_ascii(0);
    printf("Hello World\n");
    printf("This ascii %c", charact);
    return 0;
}