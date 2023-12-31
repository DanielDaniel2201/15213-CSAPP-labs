/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return (~x & y) | (x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int min = 1 << 31;
  return !(~min ^ x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int AAAA = (0b10101010 << 8) + 0b10101010;
  int AAAAAAAA = (AAAA << 16) + AAAA;
  return !(AAAAAAAA ^ (AAAAAAAA & x));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int second_four = !(0b0011 ^ (x >> 4));
  int first_four = 0b1111 & x;
  int neg = ~first_four + 1;
  return second_four & !(((9 + neg) >> 31) ^ 0);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  x = !(!(x)); // convert it to 0 or 1
  return (y & (x << 31 >> 31)) | (z & ~(x << 31 >> 31));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int neg_x = ~x + 1;
  int same_sign = !((x >> 31) ^ (y >> 31));
  int same_sigh_rst = !(((y + neg_x) >> 31) ^ 0); // subtraction & comparison
  int diff_sign = ~same_sign;
  int diff_sign_rst = !(!(x >> 31));
  return ((~diff_sign + 1) & diff_sign_rst) | ((~same_sign + 1) & same_sigh_rst);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int neg = ~x + 1;
  return ((x | neg) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int copy = x;
  int tmp = 16;

  int tmp_plus = tmp + 8;
  int tmp_minus = tmp + ~8 + 1;
  int eql = !(~(~(x << tmp >> tmp) ^ copy)) << 31 >> 31; // 0b111..11 or 0b000..00
  tmp = (tmp_plus & eql) | (tmp_minus & (~eql));
  
  tmp_plus = tmp + 4;
  tmp_minus = tmp + ~4 + 1;
  eql = !(~(~(x << tmp >> tmp) ^ copy)) << 31 >> 31; // 0b111..11 or 0b000..00
  tmp = (tmp_plus & eql) | (tmp_minus & (~eql));

  tmp_plus = tmp + 2;
  tmp_minus = tmp + ~2 + 1;
  eql = !(~(~(x << tmp >> tmp) ^ copy)) << 31 >> 31; // 0b111..11 or 0b000..00
  tmp = (tmp_plus & eql) | (tmp_minus & (~eql));

  tmp_plus = tmp + 1;
  tmp_minus = tmp + ~0;
  eql = !(~(~(x << tmp >> tmp) ^ copy)) << 31 >> 31; // 0b111..11 or 0b000..00
  tmp = (tmp_plus & eql) | (tmp_minus & (~eql));

  eql = !(~(~(x << tmp >> tmp) ^ copy)) << 31 >> 31; // 0b111..11 or 0b000..00
  int rst = ((32 + ~tmp + 1) & eql) | ((32 + ~tmp + 1 + 1) & (~eql));

  return rst;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned expMask = 0b011111111 << 23;
  unsigned fracMask = (1 << 23) - 1; // 0b0 00000000 1111..11
  unsigned signMask = 1 << 31;

  unsigned expField = (expMask & uf) >> 23;
  unsigned expAllOnes = expField == 0b11111111;
  unsigned expAllZeros = expField == 0;
  unsigned fracAllZeros = (fracMask & uf) == 0;

  unsigned isZero = expAllZeros && fracAllZeros;
  unsigned isInf = expAllOnes && fracAllZeros;
  unsigned isNaN = expAllOnes && !fracAllZeros;
  unsigned isNorm = !expAllZeros && !expAllOnes;

  if (isZero || isInf || isNaN) {
    return uf;
  } else if (isNorm) {
    return uf + (1 << 23);
  } else { // is denormalized number
    unsigned isNeg = (signMask & uf);
    return (uf << 1) + isNeg;
  }
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned fracMask = (1 << 23) - 1; // 0b0 00000000 1111..11
  unsigned expMask = 0b011111111 << 23;
  unsigned signMask = 1 << 31;

  unsigned expField = (expMask & uf) >> 23;
  unsigned expAllOnes = expField == 0b11111111;
  unsigned fracAllZeros = (fracMask & uf) == 0;

  unsigned isInf = expAllOnes && fracAllZeros;
  unsigned isNaN = expAllOnes && !fracAllZeros;

  int E = expField - 127;

  unsigned lessThan1 = E < 0;

  if (lessThan1) {
    return 0;
  } else if (isNaN || isInf || E > 31) {
    return 0x80000000u;
  } else { // is normalized number
    unsigned isNeg = (signMask & uf) != 0;
    int num = 1 << E;
    return isNeg ? -num : num;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  if (x < -23 - 126) { // too small for denorm
    return 0;
  } else if (x > 127) { // too large
    return 0b011111111u << 23;
  } else if (x >= -126) { // norm: 127 >= x >= -126
    unsigned expField = x + 127;
    return expField << 23;
  } else { // denorm:  -126 > x >= -23 - 126
    return 1 << (23 + 126 + x);
  }
}
