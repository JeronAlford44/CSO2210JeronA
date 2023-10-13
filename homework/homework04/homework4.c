1)

A  B  C  (A OR ((NOT A) AND B) AND C)   ((A NAND C) NAND A) = Y
0  0  0                0                          1
0  0  1                0                          1
0  1  0                0                          1
0  1  1                1                          1
1  0  0                1                          0
1  0  1                1                          1
1  1  0                1                          0
1  1  1                1                          1


2)

a1 ----|
       |-AND--|
b1 ----|      |
       |      |
       |      OR ---->
       |      |
a0 ----|      |
       |-AND--|
b0 ----|      |
       |      |
a0 ----|      |
       |-AND--|
b0 ----|      |
3)
a) value &= 0xAAAAAAAA;
b)value |= 0x00000007;
c)remainder = value & 0x00000007;
d)value = 0xFFFFFFFF;
e)value ^= 0xC0000000;
f)value &= 0xFFFFFFF8;

4)


5)


6)

JMP             Start

number1: 0
number2: 0
divisor: 0

start: READ       0x100
       STORE      number1
       READ       0x100
       STORE      number2
       ADD        0x01
       STORE      divisor

gcd:   LOAD       divisor
       SUB        0x01
       STORE      divisor
       LOAD       number1
       MOD        divisor
       JLZ        gcd
       JGZ        gcd
       LOAD       number2
       MOD        divisor
       JLZ        gcd
       JGZ        gcd
       LOAD       divisor
       WRITE      0x200
       
7)



8)
JGZ 0x837BBE1     ; Jump if A > 0 to address 0x837BBE1
JZ 0x837BBE1      ; Jump if A = 0 to address 0x837BBE1




9) 
1: The sequence swaps r8 and r9 w/ eachother, for example, the data that was in r8 will be in r9 and vice versa.

2: When two numbers are XORed, and then you XOR the result, you will get the origional number back... This is in a sense, is taking the properties of the XOR to swap values without immediate storage.




