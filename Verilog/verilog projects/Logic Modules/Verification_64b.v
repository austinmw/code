`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:37:33 09/29/2015 
// Design Name: 
// Module Name:    Verification_64b 
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
module Verification_64b(A, B, sum, C_in, C_out);

input [63:0] A, B;
input C_in;
output [63:0] sum;
output C_out;

assign {C_out, sum} = A + B + C_in;

endmodule
