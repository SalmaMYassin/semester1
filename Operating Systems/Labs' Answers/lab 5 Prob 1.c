#include <cstdio>
 
 
 
int main ()
{
 
    int testCases;
 
    scanf ("%d", &testCases);
 
    printf ("Lumberjacks:\n");
 
    
 
        int lumberjack [10 + 2];
 
        for ( int i = 0; i < 10; i++ ) {
            scanf ("%d", &lumberjack [i]);
        }
 
        bool isBig = true;
 
        if (lumberjack [0] > lumberjack [1]) isBig = false;
 
        bool ordered = true;
 
        if (isBig) {
 
            for ( int i = 1; i < 10; i++ ) {
                if (lumberjack [i] < lumberjack [i - 1]) ordered = false;
            }
 
        } else {
 
            for ( int i = 1; i < 10; i++ ) {
                if (lumberjack [i] > lumberjack [i - 1]) ordered = false;
            }
        }
 
        if (ordered)
            printf ("Ordered\n");
        else
            printf ("Unordered\n");
 
    
 
    return 0;
}