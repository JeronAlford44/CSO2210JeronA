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
a) value &= 0x55555555;
b)value |= 0x00000007;
c)remainder = value & 0x00000007;
d)value = 0xFFFFFFFF;
e)value ^= 0xC0000000;
f)value &= 0xFFFFFFF8;

