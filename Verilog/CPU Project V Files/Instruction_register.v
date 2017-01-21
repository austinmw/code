`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:15:08 11/29/2015 
// Design Name: 
// Module Name:    Instruction_register 
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
module Instruction_register(
	input clock,
	input IRWrite,
	input [31:0] Instr_in,
	output [5:0] opcode,
	output [4:0] R1, R2, R3, 
	output [15:0] Immediate
   );

	reg [31:0] Reg;

	assign opcode = Reg[31:26];
	assign R1 = Reg[25:21];
	assign R2 = Reg[20:16];
	assign R3 = Reg[15:11];
	assign Immediate = Reg[15:0];

	always@(posedge clock)
		begin
			if (IRWrite)
				Reg <= Instr_in;
		end

endmodule
