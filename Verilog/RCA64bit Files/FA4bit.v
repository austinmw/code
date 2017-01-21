`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:09:24 09/28/2015 
// Design Name: 
// Module Name:    FA4bit 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module FA4bit(c_out, sum, a, b, c_in);

output [3:0] sum;
output c_out;
input [3:0] a, b;
input c_in;
wire c1, c2, c3;

FA_str fa0 (c1, sum[0], a[0], b[0], c_in);
FA_str fa1 (c2, sum[1], a[1], b[1], c1);
FA_str fa2 (c3, sum[2], a[2], b[2], c2);
FA_str fa3 (c_out, sum[3], a[3], b[3], c3);

endmodule
