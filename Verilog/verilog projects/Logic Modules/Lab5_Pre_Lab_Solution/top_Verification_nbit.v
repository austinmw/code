`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:37:47 10/05/2015 
// Design Name: 
// Module Name:    top_Verification_nbit 
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
module top_Verification_nbit(clk, c_out, sum, a, b, c_in);

	parameter W = 32;
	
	input clk;
	input [W-1:0] a, b;
	input c_in;
	output [W-1:0] sum;
	output c_out;
	
	wire c_out_to_reg;
	wire [W-1:0] sum_to_reg;
	
	Verification_nbit
	#(.W(W))
	Verification
	(
		.c_out(c_out_to_reg),
		.sum(sum_to_reg),
		.a(a),
		.b(b),
		.c_in(c_in)
	);
	
	Register
	#(.W(W))
	Register_sum
	(
		.clk(clk),
		.reg_in(sum_to_reg),
		.reg_out(sum)
	);	
	
	
	Register
	#(.W(1))
	Register_c_out
	(
		.clk(clk),
		.reg_in(c_out_to_reg),
		.reg_out(c_out)
	);	
	

endmodule
