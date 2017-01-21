`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:47:02 10/10/2015 
// Design Name: 
// Module Name:    top_module 
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
module top_module(
	input clk,
	input [W-1:0] a, b,
	input c_in,
	input [2:0] operation,
	output [W-1:0] result, result_verify,
	output c_out, c_out_verify
);
parameter W = 32;

alu_top
#(.W(W))
struct_alu
(
	.clk(clk),
	.a(a),
	.b(b),
	.c_in(c_in),
	.operation(operation),
	.result(result),
	.c_out(c_out)
);

top_verification_alu
#(.W(W))
behavioral_alu
(
	.clk(clk),
	.c_in(c_in),
	.a(a),
	.b(b),
	.operation(operation),
	.result_verify(result_verify),
	.c_out_verify(c_out_verify)
);



endmodule
