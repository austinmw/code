`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:55:14 11/29/2015 
// Design Name: 
// Module Name:    JumpAddress 
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
module JumpAddress(
	input [3:0] PC_31_to_28,
	input [4:0] R1, R2,
	input [15:0] Immediate,
	output [31:0] JumpAddress_out
);

	assign JumpAddress_out = {PC_31_to_28, 2'd0, R1, R2, Immediate};

endmodule
