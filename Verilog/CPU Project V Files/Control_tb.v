`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:31:14 11/28/2015
// Design Name:   Control
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/verilog projects/CPU_Multicycle/Control_tb.v
// Project Name:  CPU_Multicycle
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Control_tb;

	// Inputs
	reg [5:0] opcode;
	reg clock;
	reg reset;

	// Outputs
	wire PCWriteCond;
	wire PCWrite;
	wire MemWrite;
	wire MemtoReg;
	wire IRWrite;
	wire [1:0] PCSource;
	wire [1:0] ALUOp;
	wire [1:0] ALUSrcA;
	wire [1:0] ALUSrcB;
	wire RegWrite;
	wire Instr26;
	wire RegSelect1;
	wire [1:0] RegSelect2;

	always #5 assign clock = ~clock;            // this enough time for complete cycle?

	// Instantiate the Unit Under Test (UUT)
	Control uut (
		.opcode(opcode), 
		.clock(clock), 
		.reset(reset), 
		.PCWriteCond(PCWriteCond), 
		.PCWrite(PCWrite), 
		.MemWrite(MemWrite), 
		.MemtoReg(MemtoReg), 
		.IRWrite(IRWrite), 
		.PCSource(PCSource), 
		.ALUOp(ALUOp), 
		.ALUSrcA(ALUSrcA), 
		.ALUSrcB(ALUSrcB), 
		.RegWrite(RegWrite), 
		.Instr26(Instr26), 
		.RegSelect1(RegSelect1), 
		.RegSelect2(RegSelect2)
	);

	initial begin
		// Initialize Inputs
		opcode = 0;
		clock = 0;
		reset = 1;

		// Wait 100 ns for global reset to finish
		#100;
        
		// One test for each branch coming out of stage 1
		
		// J
		reset = 0;
		opcode = 6'b00001;
		
		// BNE
		#100
		opcode = 6'b100001;
		
		// BEQ
		#100
		opcode = 6'b100000;
		
		// BLT
		#100
		opcode = 6'b100010; 
		
		// ADDI
		#100
		opcode = 6'b110010;
		
		// LUI
		#100
		opcode = 6'b111010; 
		
		// AND
		#100
		opcode = 6'b010101;
		
		// SWI
		#100 
		opcode = 6'b111100;
		
		// SW
		#100
		opcode = 6'b111110;
		
		// LWI
		#100
		opcode = 6'b111011;
		
		// LW
		#100
		opcode = 6'b111101;		

		// NOOP
		#100
		opcode = 6'b000000;

	end
      
endmodule

