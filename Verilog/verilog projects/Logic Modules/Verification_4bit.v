`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:19:58 09/28/2015 
// Design Name: 
// Module Name:    Verification_4bit 
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
module Verification_4bit(c_out, sum, a, b, c_in);

	input	 [3:0] a, b; 
	input c_in; //declare inputs a, b, and c_in, one bit each
	output c_out;
	output [3:0] sum; //declare outputs c_out and sum, one bit each

	assign {c_out, sum} = a + b + c_in;

endmodule

