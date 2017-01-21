`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:13:03 10/05/2015 
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// In this top module, the same input is given to both adder and verification logic												  //
// The output of the two modules will be returned separately																			  //
// In the testbench for this module, only need to compare the output from the two modules to determine the correctness //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

module top(
	input clk,
	input [W-1:0] a,
	input [W-1:0] b,
	input c_in,
	output c_out,							// Output from adder
	output [W-1:0] sum,					// Output from adder
	output c_out_verify,					// Output from verification logic
	output [W-1:0] sum_verify			// Output from verification logic
   );

	parameter W = 32;
	
	
	// Adder top module (adder with registers to the output)
	adder_top
	#(.W(W))
	adder_structral
	(
		.clk(clk),
		.a(a),
		.b(b),
		.c_in(c_in),
		.sum(sum),
		.c_out(c_out)
	);
	
	// Verification top module (Verification logic with registers to the output)
	top_Verification_nbit
	#(.W(W))
	verification
	(
		.clk(clk),
		.c_out(c_out_verify),
		.sum(sum_verify),
		.a(a),
		.b(b),
		.c_in(c_in)
	);

endmodule
