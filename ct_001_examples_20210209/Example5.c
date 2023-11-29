//Example5.c  
#define MARGE(x,y) x##y  
 
int main() {  
 
    int num = MARGE(52,34);

    printf("MARGE(52,34) = %d\n", num); 
    return 0;
}

