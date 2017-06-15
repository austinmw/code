// Austin Welch EC413  (Answers to questions include in comments)

// SOLUTION FILE

main()
{
  int var_int;                    // 2

  unsigned char uchar1, uchar2;   // 3
  signed char schar1, schar2;

  int x, y;                       // 4

  char i;                         // 5
  char shift_char;

  int a[10] = {0,10,20,30,40,50,60,70,80,90};    // 6

  int b[10], c[10];               // 7
  int *ip, *ip2;
  int j, k;

  char AString[] = "HAL";           // 8

//test
  // 1 -- change "World" to your name
  printf("\n\n PART 1 ---------\n");

  printf("\n Hello Austin! \n");

  // 2 -- find sizes of the other C datatypes
  printf("\n\n PART 2 ----------\n");

  printf("\n size of data type int = %d ", sizeof(var_int));

  printf("\n size of data type char = %d ", sizeof(i));

  printf("\n size of data type unsigned char = %d ", sizeof(uchar1));

  printf("\n size of data type signed char = %d ", sizeof(schar1));

  printf("\n size of data type int (array) = %d ", sizeof(a)); 

  printf("\n size of data type char (string) = %d ", sizeof(AString));
  // string literal is implicitly null-terminated, so adds one byte 

// 3 -- explore signed versus unsigned datatypes and their interactions
  printf("\n\n PART 3 ----------\n");

  uchar1 = 0xFF;
  uchar2 = 0xFE;
  schar1 = 0xFF;
  schar2 = 0xFE;

  printf("\n uchar1 = %d ", uchar1);
  printf("\n schar1 = %d ", schar1);

  printf("\n uchar2 = %d ", uchar2);
  printf("\n schar2 = %d ", schar2);

  /* First question:
     The unsigned char uses the most significant bit instead of treating it
     as a bit flag, so hex FF as unsigned is 11111111 which is 2^8, or 256.
     as a signed char FF also equals 11111111, but in this case the MSB means
     that the number is negative. It uses 2's complement notation, so you
     flip each bit and then add one. This results in 1 which is negative, so -1.  */

  if (uchar1 > uchar2) 
	printf("\n\n uchar1 larger than uchar2");
  else if (uchar2 > uchar1) 
	printf("\n\n uchar2 larger than uchar1");

  if (schar1 > schar2) 
	printf("\n\n schar1 larger than schar2");
  else if (schar2 > schar1) 
	printf("\n\n schar2 larger than schar1");

  if (uchar1 > schar1) 
	printf("\n\n uchar1 larger than schar1");
  else if (schar1 > uchar1) 
	printf("\n\n schar1 larger than uchar1");

  // The comparison of the unsigned and signed values where what I expected.

  
  printf("\n\n schar1 + schar2 = %d", schar1+schar2);  
  // This is what I expected, -1 + -2 = -3.

  printf("\n\n uchar1 + uchar2 = %d", uchar1+uchar2);
  // This is what I expected, 255 + 254 = 509.

  printf("\n\n schar1 + uchar1 = %d", schar1+uchar1);
  // This is also what I expected, 255 + -1 = 254.
   	


  // 4 -- Booleans
  printf("\n\n PART 4 ----------\n");

  x = 1; y = 2;

  
  
  printf("\n\n Boolean true is %d", y && x);
  printf("\n Boolean false is %d", x > y);
  printf("\n size of internal data type for Boolean is %d", sizeof(y > x));

  printf("\n x = %d and y = %d", x, y);
  printf("\n x & y = %d", x & y);
  printf("\n x && y = %d", x && y);
  
  printf("\n ~y = %d", ~y);
  printf("\n !y = %d", !y);
 






  // 5 -- shifts
  printf("\n\n PART 5 ----------\n");

  shift_char = 15;
  i = 1;

  printf("\n shift_char = %d", shift_char);
  printf("\n shift_char << %d = %d", i, shift_char << i);
  
  printf("\n shift_char << %d = %d", 3, shift_char << 3);
  printf("\n shift_char << %d = %d", 4, shift_char << 4);
  printf("\n shift_char << %d = %d", 8, shift_char << 8);
  printf("\n shift_char << %d = %d", 9, shift_char << 9);


  /* 
  I'm not sure if I'm missing something here, but all the shifted
  values were what I'd expect them to be. shift_char starts out in 
  binary as 1111. Shift by 1 results in 11110 which is 30. Shift by
  3 results in 1111000 which is 120. Shift by 4 is 11110000 which is
  240. Shift by 8 results in 111100000000 which is 3840. Shift by 9 
  is 1111000000000 which is 7680. All the results printed correctly. 
  I don't think you would run into problems until you shift past 
  the 32nd bit since type int is 4 bytes.
  */  
  


  // 6 -- pointer basics
  printf("\n\n PART 6 ----------\n");

  ip = a;
  printf("\nstart %d %d %d %d %d %d %d \n",
	 a[0], *(ip), *(ip+1), *ip++, *ip, *(ip+3), *(ip-1));

  ip = &a[1];
  printf("\nstart %d %d %d %d %d %d %d \n",
	 a[1], *(ip), *(ip+1), *ip++, *ip, *(ip+3), *(ip-1));

  ip = a;
  printf("\n size of integer pointer data type is %lu", sizeof(ip));
  // size of pointer is 8 bytes on 64-bit C compiler 
  
  printf("\n pointer value is %x", *(ip));
  printf("\n pointer value is %x", *(ip+1));
  printf("\n pointer value is %x", *ip+1);

  /*
  In the first case the value at the address of a[0] is printed in hex,
  which is 0. In the second case the +1 is in parenthesis, so the value
  of a[0+1] = a[1] is printed in hex, where 10 = a. In the third case,
  the value at the address of a[0] is printed, and then 1 is added, where
  1 = 1 in hex. 
  */


  // 7 -- programming with pointers
  printf("\n\n PART 7 ----------\n");


  
  int n = sizeof(a) / sizeof(a[0]); // or could just divide by sizeof(int)
  printf("\n size of a is %d", sizeof(a));
  printf("\n size of a[0] is %d", sizeof(a[0]));
  printf("\n length of array a is %d", n);
	

  for (int i = 0, j = n - 1; i < n; i++, j--)
  	b[i] = a[j];
  printf("\n\n");
  for (int i = 0; i < n; i++)
  	printf("a[%d] = %d ", i, a[i]);
  printf("\n\n");
  for (int i = 0; i < n; i++)
  	printf("b[%d] = %d ", i, b[i]);
 

  for (int i = 0, j = n-1; i < n; i++, j--){
        ip2 = &a[j];
	c[i] = *ip2;
  }
  printf("\n\n");
  for (int i = 0; i < n; i++)
  	printf("a[%d] = %d ", i, a[i]);
  printf("\n\n");
  for (int i = 0; i < n; i++)
  	printf("c[%d] = %d ", i, c[i]);


  // 8 -- strings
  printf("\n\n PART 8 ----------\n");

  printf("\n %s \n", AString);

  // NEW CODE
  for (k = 0; k < 4; k++) printf("\n %d", AString[k]);

  // after the last character the value is 0 which is null
  // null is added as an extra byte to string literals 

  for (k = 0; k < 3; k++) AString[k] += 1;
  printf("\n My name is %s. \n", AString);


  AString[3] += 60;
  printf("\n %s \n", AString);

  for (k = 0; k < 10; k++) printf("\n %d", AString[k]);


  // 60 is added to the null character at AString[3]. The output for
  // AString[4] and greater is considered undefined behavior.




  
  printf("\n\n\n PART 9 \n");
  // 9 -- address calculation

  for (k = 0; k < 10; k++) b[k] = a[k];         // direct reference to array element

  for (k = 0; k < 10; k++)
  {
      printf("\n %d", &b[k]);  
  }

  printf("\n\n");

  ip = a;
  ip2 = b;

  for (k = 0; k < 10; k++)
  {
      printf("\n %d", &ip2[k]);  
      *ip2++ = *ip++;     // indirect reference to array element
  }

  // I think since I'm on a 64-bit system pointer addresses are incrementing by
  // 8 bytes where int array addresses are incrementing by 4 bytes


  // all done
  printf("\n\n ALL DONE\n");

}
