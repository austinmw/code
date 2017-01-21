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
	input clk,
	input [W-1:0] a, b,
	input c_in,
	input [2:0] operation,
	output [W-1:0] result,
	output c_out
);
parameter W = 32;

wire [W-1:0] result_to_reg;
wire c_out_to_reg;


para_ALU
#(.W(W))
ALU
(
	.a(a),
	.b(b),
	.c_in(c_in),
	.operation(operation),
	.result(result_to_reg),
	.c_out(c_out_to_reg)
);

Register
#(.W(W))
Register_result
(
	.clk(clk),
	.reg_in(result_to_reg),
	.reg_out(result)
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
