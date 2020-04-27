strangers on the internet were talking about how to know when to drop a class. as a joke, a person wrote the following method:

public bool MakePassFail(double grade, double GPA)
{
    return grade < GPA;
}

As a joke, I posted the following feedback:

" inefficient use of space. you only need a single precision float to represent the grade. this would decrease size of the data by half. (8 bytes per double to 4 bytes per single) 

even better, represent the grade and gpa as an array of two unsigned chars each. this will give you 16 bits of data for each. use the first bit for the sign (always zero since gpa and grade is always positive), use the next three bits for the ones place (only need to represent 0-4), the next 12 bits for the 10ths,100ths, and thousandths decimal places, with each being represented by four bits. in this way, you will have gone from using 16Bytes of data to using 4 bytes. comparison will be the same efficiency, perhaps a bit better because of the smaller data size.

for example, the grade A+ could be represented with : 0b0100001001010000 where starting from left to right, 
0 = positive 
100 = 4 
0010 = 2 
0101 = 5 
0000 = 0 
put it all together to represent 4.25 efficiently "

An epic battle ensued where I was told that one should not waste time optimizing such a trivial thing. My argument was that a bitfield is not a hard thing to implement and can be done legibly and is worth it for size and performance savings. I wrote some code to compare performance and space usage because it's quarantine time and i'm bored.

results:

who was faster?
OP:82 ticks
Mike:34 ticks

who used more memory?
OP:16 Bytes
Mike:4 Bytes

