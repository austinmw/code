`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:42:14 11/15/2015 
// Design Name: 
// Module Name:    Control 
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
module Control(opcode, clock, reset, PCWriteCond, PCWrite, MemWrite, MemtoReg, IRWrite,
			  PCSource, ALUOp, ALUSrcA, ALUSrcB, RegWrite, Instr26, RegSelect1, RegSelect2);
	input [5:0] opcode;
	input clock, reset;
	output reg PCWriteCond, PCWrite, MemWrite, MemtoReg, IRWrite, RegWrite,
				  Instr26, RegSelect1;
	output reg [1:0] PCSource, ALUOp, ALUSrcA, ALUSrcB, RegSelect2;
	
	reg [4:0] state;
	reg [4:0] next_state;
		
	// Opcode reference
	parameter NOOP = 6'b000000, MOV = 6'b010000, NOT = 6'b010001, ADD = 6'b010010,
				 SUB = 6'b010011, OR = 6'b010100, AND = 6'b010101, SLT = 6'b010111,
			    J = 6'b000001, BEQ = 6'b100000, BNE = 6'b100001, ADDI = 6'b110010,
				 SUBI = 6'b110011, ORI = 6'b110100, ANDI = 6'b110101, SLTI = 6'b110111,
				 LI = 6'b111001, LWI = 6'b111011, SWI = 6'b111100, LUI = 6'b111010, 
				 SW = 6'b111110, LW = 6'b111101, BLT = 6'b100010, BLE = 6'b100011,
				 XOR = 6'b010110, XORI = 6'b110110;
	
	// Initialize states
	initial
	begin
		state <= 5'd0;
		next_state <= 5'd0;
	end
	
	// State -> next_state
	always @(posedge clock)
		state <= next_state;
	
	// Output assignments
	always @(state)
	begin
		case(state)
			5'd0:  begin ALUSrcA = 0; ALUSrcB = 1; ALUOp = 0; PCSource = 0; PCWrite = 1; IRWrite = 1; 
							 RegSelect1 = 1; RegSelect2 = 1; RegWrite = 0; PCWriteCond = 0; MemWrite = 0;
							 Instr26 = 0; MemtoReg = 0; end
			5'd1:  begin ALUSrcB = 2; PCWrite = 0; IRWrite = 0; end			
			5'd2:  begin ALUSrcA = 1; ALUSrcB = 0; ALUOp = 2; end			
			5'd3:  begin ALUSrcA = 1; ALUSrcB = 3; ALUOp = 2; end	
			5'd4:  begin ALUSrcA = 1; ALUSrcB = 2; ALUOp = 2; end			
			5'd5:  begin RegSelect1 = 0; RegSelect2 = 0; end			
			5'd6:  begin PCWrite = 1; PCSource = 2; end				 
			5'd7:  begin RegSelect1 = 1; RegSelect2 = 1; ALUOp = 0; ALUSrcA = 1; ALUSrcB = 3; end							 
			5'd8:  begin RegSelect1 = 1; RegSelect2 = 1; ALUOp = 0; ALUSrcA = 2; ALUSrcB = 3; end			
			5'd9:  begin RegSelect1 = 1; RegSelect2 = 2; ALUOp = 0; ALUSrcA = 1; ALUSrcB = 3; end			
			5'd10: begin RegSelect1 = 1; RegSelect2 = 2; ALUOp = 0; ALUSrcA = 2; ALUSrcB = 3; end
			5'd11: begin RegWrite = 1; MemtoReg = 0; end	
			5'd12: begin Instr26 = 0; ALUSrcA = 1; ALUSrcB = 0; ALUOp = 2; PCSource = 1; PCWriteCond = 1; end	
			5'd13: begin Instr26 = 0; ALUSrcA = 1; ALUSrcB = 0; ALUOp = 1; PCSource = 1; PCWriteCond = 1; end	
			5'd14: begin Instr26 = 1; ALUSrcA = 1; ALUSrcB = 0; ALUOp = 1; PCSource = 1; PCWriteCond = 1; end						 						 
			5'd15: begin MemtoReg = 1; end			
			5'd16: begin MemWrite = 1; end
			5'd17: begin RegWrite = 1; end	
			default: begin PCWriteCond = 1'bx; PCWrite = 1'bx; MemWrite = 1'bx; MemtoReg = 1'bx; IRWrite = 1'bx;
								PCSource = 2'bx; ALUOp = 2'bx; ALUSrcA = 2'bx; ALUSrcB = 2'bx; RegWrite = 1'bx;
								Instr26 = 1'bx; RegSelect1 = 1'bx; RegSelect2 = 2'bx; end
		endcase
	end
	
	// State transitions
	always @(reset or state or opcode)
	begin
		if (reset)
			next_state = 0;
		else
			case (state)
				5'd0: next_state = 5'd1;		
				5'd1: 
						// NOOP
						if (opcode == NOOP)
							next_state <= 5'd0;	
						// Jump
						else if (opcode == J)
							next_state <= 5'd6;		
						// Branches	
						else if ((opcode == BNE) || (opcode == BEQ) || (opcode == BLT)
									|| (opcode == BLE))
							next_state <= 5'd5;	
						// Sign Extended Arithmetic/Logical I-types
						else if ((opcode == ADDI) || (opcode == SUBI) || (opcode == SLTI))
							next_state <= 5'd4;
						// Zero Extended Arithmetic/Logical I-types
						else if ((opcode == XORI) || (opcode == LUI) || (opcode == ORI)
									|| (opcode == ANDI) || (opcode == LI))
							next_state <= 5'd3;
						// R-types
						else if ((opcode == MOV) || (opcode == NOT) || (opcode == ADD) 
									|| (opcode == SUB) || (opcode == OR) || (opcode == AND)
									|| (opcode == SLT) || (opcode == XOR))
							next_state <= 5'd2;
					   // Loads and stores
						else if (opcode == SWI)
							next_state <= 5'd10;
						else if (opcode == SW)
							next_state <= 5'd9;
						else if (opcode == LWI)
							next_state <= 5'd8;
						else if (opcode == LW)
							next_state <= 5'd7;		
						else 
							next_state <= 5'd1;
												
				5'd2:  next_state <= 5'd11;
				5'd3:  next_state <= 5'd11;
				5'd4:  next_state <= 5'd11;	
				5'd5:  
						// BLT/BLE
						if ((opcode == BLT) || (opcode == BLE))
							next_state <= 5'd12;	
						// BEQ
						else if (opcode == BEQ)
							next_state <= 5'd13;		
						// BNE
						else if (opcode == BNE)
							next_state <= 5'd14;
						else 
							next_state <= 5'd5;
				5'd6:  next_state <= 5'd0;
				5'd7:  next_state <= 5'd15;
				5'd8:  next_state <= 5'd15;
				5'd9:  next_state <= 5'd16;
				5'd10: next_state <= 5'd16;
				5'd11: next_state <= 5'd0;
				5'd12: next_state <= 5'd0;
				5'd13: next_state <= 5'd0;
				5'd14: next_state <= 5'd0;
				5'd15: next_state <= 5'd17;
				5'd16: next_state <= 5'd0;
				5'd17: next_state <= 5'd0;	
			endcase
	end
	
	endmodule
	