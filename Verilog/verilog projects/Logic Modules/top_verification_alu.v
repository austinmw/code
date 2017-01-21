`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:31:07 10/10/2015 
// Design Name: 
// Module Name:    top_verification_alu 
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
module top_verification_alu(
input clk,
input c_in,
input [W-1:0] a, b,
input [2:0] operation,
output [W-1:0] result_verify,
output c_out_verify
);
parameter W = 32;

wire [W-1:0] result_to_reg;
wire c_out_to_reg;

verification_alu
#(.W(W))
behavioral_alu
(
	.c_in(c_in),
	.a(a),
	.b(b),
	.operation(operation),
	.result(result_to_reg),
	.c_out(c_out_to_reg)
);

Register
#(.W(W))
register_result_verify
(
	.clk(clk),
	.reg_in(result_to_reg),
	.reg_out(result_verify)
);

Register
#(.W(1))
register_c_out_verify
(
	.clk(clk),
	.reg_in(c_out_to_reg),
	.reg_out(c_out_verify)
);


endmodule
