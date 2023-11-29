//Example7.c  
#define STRINGIZING(x) #x  
 
int main() {  
 
    printf(STRINGIZING(Hello World\n) );  
    return 0;
}

