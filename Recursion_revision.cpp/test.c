#include<stdio.h>
int * g (void) { 
    int x= 10; 
    return (&x); 
} 

int * g (void) { 
    int * px; 
    *px= 10; 
    return px; 
} 
int *g (void) { 
    int *px; 
    px = (int *) malloc (sizeof(int)); 
    *px= 10; 
    return px;  
}