`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:36:56 11/15/2015 
// Design Name: 
// Module Name:    aluControl 
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
module aluControl(opcode, ALUOp, aluSel);
	input [5:0] opcode;
	input [1:0] ALUOp;
	output reg[3:0] aluSel;

always @(opcode, ALUOp)
begin
	case(ALUOp)
		2'd0: aluSel <= 3; // ADD
		2'd1: aluSel <= 4; // SUB
		2'd2: 
			begin
				case(opcode)
				6'b000000: aluSel <= 0;  // NOOP
				6'b010000: aluSel <= 1;  // MOV
				6'b010001: aluSel <= 2;  // NOT
				6'b010010: aluSel <= 3;  // ADD
				6'b010011: aluSel <= 4;  // SUB
				6'b010100: aluSel <= 5;  // OR
				6'b010101: aluSel <= 6;  // AND
				6'b010111: aluSel <= 7;  // SLT 
				6'b000001: aluSel <= 3;  // J
				6'b100000: aluSel <= 4;  // BEQ
				6'b100001: aluSel <= 4;  // BNE
				6'b110010: aluSel <= 3;  // ADDI
				6'b110011: aluSel <= 4;  // SUBI
				6'b110100: aluSel <= 5;  // ORI
				6'b110101: aluSel <= 6;  // ANDI
				6'b110111: aluSel <= 7;  // SLTI
				6'b111001: aluSel <= 8;  // LI
				6'b111011: aluSel <= 3;  // LWI
				6'b111100: aluSel <= 3;  // SWI
				6'b111010: aluSel <= 9;  // LUI
				6'b111110: aluSel <= 3;  // SW
				6'b111101: aluSel <= 3;  // LW
				6'b100010: aluSel <= 10; // BLT	
				6'b100011: aluSel <= 11; // BLE
				6'b010110: aluSel <= 12; // XOR
				6'b110110: aluSel <= 12; // XORI
				default:   aluSel <= 0;  // shouldn't get used			
				endcase
			end
	endcase
end
endmodule
