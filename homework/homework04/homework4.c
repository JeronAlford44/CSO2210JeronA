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
 JMP     start   ;jump to start
 count: 0               ; initialize count
 limit: 256             ; set limit to 256 to write all values 0-255
 start: LOAD count      ; bring the value into accumulator to use
        WRITE   0x64     ; output the current count to port 8
        ADD     0x01    ; add 1 to count
        STORE   count   ; store current value of count
        SUB     limit   ; gets limit - accumulator value
        JZ     start   ; loop until limit - accumulator value == 0
   end: JUMP    end     ; end of program



5)
   C0000003
   00000000
   000000FF
   00000001
   30000008
   40000002
   10000001
   50000003 
   D0000004
   C0000009


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




