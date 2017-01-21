`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:48:25 10/04/2015 
// Design Name: 
// Module Name:    top 
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
module adder_top(
	input clk,
	input [W-1:0] a,
	input [W-1:0] b,
	input c_in,
	output [W-1:0] sum,
	output c_out
   );

	parameter W = 32;
	
	wire [W-1:0] sum_to_reg;
	wire c_out_to_reg;
	
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
	
	Para_Adder
	#(.W(W))
	Adder
	(
		.c_out(c_out_to_reg),
		.sum(sum_to_reg),
		.a(a),
		.b(b),
		.c_in(c_in)
	);


endmodule
