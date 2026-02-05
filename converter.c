#include <stdio.h>
char ascii[] = 
        "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'."; 
 
char intToAscii(int i){
    return ascii[i];
}

char getAsciiFromLevel(float level, char arr[], int n){
    
    //If no value return blank
    if(level ==0){
        return ' ';
    }

    //As many steps
    float steps = 1.0/n;
    printf("Test \f",steps);

    //Binary Search for value
    int low = 0;
    int high = n -1; 

    while (low <=high){
        int mid = low + (high-low)/2;
        float current_value = steps*mid;

        printf("Current: %f target: %f\n\n",current_value,0.912059);

        if(current_value==level)
            return mid;
        if(current_value<level)
            low = mid+1;
        else
            high = mid-1;
        
        //printf("Low: %i High: %i\n\n",low,high);

    }
    
    return arr[low];
}


float rgbToBWLevel(float red, float green, float blue){
    
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
    float level = rgbToBWLevel(180,255,255);
    char test = getAsciiFromLevel(level, ascii, 70);
    printf("This is a test %c",test);
    printf("This level shold be 1 : %f", level);
    return 0;
}