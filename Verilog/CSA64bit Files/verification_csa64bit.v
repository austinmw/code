`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:03:10 10/01/2015 
// Design Name: 
// Module Name:    verification_csa64bit 
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
module verification_csa64bit(a, b, sum, c_out);

input [63:0] a, b;
output [63:0] sum;
output c_out;
parameter c_in = 0;

assign {c_out, sum} = a + b;

endmodule
