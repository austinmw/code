`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:05:12 10/09/2015 
// Design Name: 
// Module Name:    para_ALU 
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
module para_ALU(
input c_in,
input [W-1:0] a, b,
input [2:0] operation,
output [W-1:0] result,
output c_out	 
);

parameter W = 32;
wire [31:0] result_data;
wire [31:0] slt_out;

wire [W:0] carry;
wire Binvert, not_msb_op, first_c_in;

// makes overall c_in = 1 if operation is SUB
not (not_msb_op, operation[2]);
and (Binvert, not_msb_op, operation[1], operation[0]);
or (first_c_in, Binvert, c_in);

assign carry[0] = first_c_in;
assign c_out = carry[W];


genvar i;
generate 
	for(i = 0; i < W; i = i + 1)
		begin: alu
		ALU	alu1bit(a[i], b[i], carry[i], operation, result_data[i], carry[i+1]);
		end
endgenerate		


assign slt_out = (a < b)? 32'd1 : 32'd0;
assign result = (operation == 3'd6)? slt_out : result_data;

endmodule
