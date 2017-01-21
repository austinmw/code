`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:57:52 10/10/2015 
// Design Name: 
// Module Name:    alu_top 
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
module alu_top(
	input [W-1:0] a, b,
	input c_in,
	input [2:0] operation,
	output [W-1:0] result,
	output c_out
);
parameter W = 32;

para_ALU
#(.W(W))
ALU
(
	.a(a),
	.b(b),
	.c_in(c_in),
	.operation(operation),
	.result(result),
	.c_out(c_out)
);


endmodule
