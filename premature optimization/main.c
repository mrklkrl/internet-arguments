#include "timingprofile.h"
#include "stdio.h"

#define __STDC_FORMAT_MACROS
#define GRADE(a,b,c,d) (0xFFFF & a << 12 | b << 8 | c << 4 | d)

////////////////////////////////////////////////////////////////////////////////
// GPA funcs
////////////////////////////////////////////////////////////////////////////////

typedef uint16_t Grade;
typedef uint16_t GPA;

// mike
static int make_pass_fail(Grade grade, GPA gpa)
{
    return (grade < gpa);
}

// OP
static int MakePassFail(double grade, double GPA)
{
    return grade < GPA;
}

////////////////////////////////////////////////////////////////////////////////
// main
////////////////////////////////////////////////////////////////////////////////

int main()
{
    // timing
    uint64_t t0, t1;
    init_clock_frequency();
    
    // OP's stuff
    t0 = mach_absolute_time();
    
    double gpa0 = 4.0;
    double grade0 = 3.5;
    
    MakePassFail(grade0, gpa0);
    
    get_ellapsed(&t0);
    
    // Mike's stuff
    t1 = mach_absolute_time();

    GPA gpa2 = GRADE(4,2,5,1);
    Grade grade2 = GRADE(3,0,0,0);

    make_pass_fail(grade2, gpa2);

    get_ellapsed(&t1);

    printf("who was faster?\n");
    printf("OP:%"PRIu64" ticks\nMike:%"PRIu64" ticks\n\n", t0, t1);
    printf("who used more memory?\n");
    printf("OP:%lu Bytes\nMike:%lu Bytes\n", sizeof(double)*2, sizeof(Grade)*2);
    
    return 0;
}
