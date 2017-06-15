// Example: two sorted arrays, find overall median.
// A = 1 , 2, 3 , 5, 16
// B= 8,9, 10,  12, 13, 14

// 1,2, *3* ,5,8   ,9,   *10* ,12, 13, 14, 16
//
// m=5,n=4
//
// median is 7

// Pseudocode:
//    if no overlap, A < B or B < A, median is at (n+m)//2.
//    
