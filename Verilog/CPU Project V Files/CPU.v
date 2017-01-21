`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:09:36 11/30/2015 
// Design Name: 
// Module Name:    CPU 
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
module CPU(
input clk, rst,
output [31:0] pc_out, ALU_OUT
);

// gotta remove these from inputs once control is added: 
 // pc_on, IRWrite, RegSelect1, RegSelect2, RegWrite,
 // Write_data, ALUSrcA, ALUSrcB, ALUSelect, PCSource, 
 // PCWriteCond, MemWrite, MemtoReg, Instr26, ALUSelect gets removed too when ALUControl is added
 


// Constants
reg [31:0] Zero_constant = 32'd0, One_constant = 32'd1;

// Datapath connections
wire        pc_on, Zero, not_Zero, And_to_Or_wire, Zero_mux_out, PCWriteCond, PCWrite,
	         MemWrite, MemtoReg, IRWrite, RegWrite, Instr26, RegSelect1;
wire [1:0]  RegSelect2, ALUSrcA, ALUSrcB, PCSource, ALUOp;
wire [3:0]  ALUSelect;
wire [4:0]  r1, r2, r3, MuxtoReadReg1, MuxtoReadReg2;
wire [5:0]  opc; 
wire [15:0] Truncate_to_IMem, immediate, DMem_Address_Truncated;
wire [31:0] Instruction_to_IR, Read_data_to_A, Read_data_to_B,   // pc_out goes to A_mux and Concat box also
				A_to_MuxA, B_to_MuxB, SE_Immediate, ZE_Immediate,
				MuxA_to_ALU, MuxB_to_ALU, ALUResult_to_ALUReg,
				JumpAddress_wire, Final_mux_to_pc_in, ALU_Final_Result,
				MemData_wire, MemDataReg_out, mux_to_Reg_WriteData;

// Continuous Assignments				
assign not_Zero = ~Zero;
assign And_to_Or_wire = PCWriteCond && Zero_mux_out;
assign pc_on = PCWrite || And_to_Or_wire;
assign ALU_OUT = ALU_Final_Result;


// Control Instantiations
Control
Main_Control_State_Machine
(
	.opcode(opc),
	.clock(clk),
	.reset(rst),
	.PCWriteCond(PCWriteCond),
	.PCWrite(PCWrite),
	.MemWrite(MemWrite),
	.MemtoReg(MemtoReg),
	.IRWrite(IRWrite),
	.RegWrite(RegWrite),
	.Instr26(Instr26),
	.RegSelect1(RegSelect1),
	.PCSource(PCSource),
	.ALUOp(ALUOp),   
	.ALUSrcA(ALUSrcA),
	.ALUSrcB(ALUSrcB),
	.RegSelect2(RegSelect2)
);

aluControl
ALU_State_Machine
(
	.opcode(opc),
	.ALUOp(ALUOp),
	.aluSel(ALUSelect)
);


// Submodule Instantiations for Datapath
PC32bit
Program_Counter
(
	.clock(clk),
	.reset(rst),
	.PC_on(pc_on),
	.PC_in(Final_mux_to_pc_in),
	.PC_out(pc_out)
);

truncate32to16
Truncate_PC
(
	.in(pc_out),
	.out(Truncate_to_IMem)
);

IMem
Instruction_Memory
(
	.PC(Truncate_to_IMem),
	.Instruction(Instruction_to_IR)
);

Instruction_register
IR
(
	.clock(clk),
	.IRWrite(IRWrite),
	.Instr_in(Instruction_to_IR),
	.opcode(opc),
	.R1(r1), 
	.R2(r2), 
	.R3(r3), 
	.Immediate(immediate)
);

mux2
#(.bitwidth(5))
ReadReg1Mux
(
	.sel(RegSelect1),
	.a(r1),
	.b(r2),
	.y(MuxtoReadReg1)
);

mux3
#(.bitwidth(5))
ReadReg2Mux
(
	.sel(RegSelect2),
	.in0(r2),
	.in1(r3),
	.in2(r1),
	.out(MuxtoReadReg2)
);

signextender
Sign_Extend_Immediate
(
	.in(immediate),
	.out(SE_Immediate)
);

zeroextender
Zero_Extend_Immediate
(
	.in(immediate),
	.out(ZE_Immediate)
);

nbit_register_file
Registers
(
	.clk(clk),
	.RegWrite(RegWrite),
	.read_sel_1(MuxtoReadReg1),
	.read_sel_2(MuxtoReadReg2),
	.read_data_1(Read_data_to_A),
	.read_data_2(Read_data_to_B),
	.write_address(r1),
	.write_data(mux_to_Reg_WriteData)
);

A_register
A
(
	.clock(clk),
	.a_in(Read_data_to_A),
	.a_out(A_to_MuxA)
);

B_register
B
(
	.clock(clk),
	.b_in(Read_data_to_B),
	.b_out(B_to_MuxB)
);

mux3
Mux_to_ALU_A
(
	.sel(ALUSrcA),
	.in0(pc_out),
	.in1(A_to_MuxA),
	.in2(Zero_constant),
	.out(MuxA_to_ALU)
);

mux4
Mux_to_ALU_B
(
	.sel(ALUSrcB),
	.in0(B_to_MuxB),
	.in1(One_constant),
	.in2(SE_Immediate),
	.in3(ZE_Immediate),
	.out(MuxB_to_ALU)
);

ALU
alu_result_and_zero
(
	.aluSel(ALUSelect),
	.a(MuxA_to_ALU),
	.b(MuxB_to_ALU),
	.result(ALUResult_to_ALUReg),
	.zero(Zero)
);

ALUOut_register
ALU_Output_Register
(
	.clock(clk),
	.ALUOut_in(ALUResult_to_ALUReg),
	.ALUOut_out(ALU_Final_Result)
);

mux2
#(.bitwidth(1))
Zero_Mux
(
	.sel(Instr26),
	.a(Zero),
	.b(not_Zero),
	.y(Zero_mux_out)
);

JumpAddress
concat_PC31to28_00_Instr25to0
(
	.PC_31_to_28(pc_out[31:28]),
	.R1(r1),
	.R2(r2),
	.Immediate(immediate),
	.JumpAddress_out(JumpAddress_wire)
);

mux3
Mux_to_PC_in
(
	.sel(PCSource),
	.in0(ALUResult_to_ALUReg),
	.in1(ALU_Final_Result),
	.in2(JumpAddress_wire),
	.out(Final_mux_to_pc_in)
);

truncate32to16
Truncate_DMem_Address
(
	.in(ALU_Final_Result),
	.out(DMem_Address_Truncated)
);

DMem
Data_Memory
(
	.WriteData(B_to_MuxB),
	.MemData(MemData_wire),
	.Address(DMem_Address_Truncated),
	.MemWrite(MemWrite),
	.Clk(clk)
);

MemoryData_register
Data_Register
(
	.clock(clk),
	.data_in(MemData_wire),
	.data_out(MemDataReg_out)
);

mux2
DMemReg_to_WriteData_mux
(	
	.sel(MemtoReg),
	.a(ALU_Final_Result),
	.b(MemDataReg_out),
	.y(mux_to_Reg_WriteData)
);




endmodule


/*

		// Initialize Inputs
		clk = 0;
		rst = 1;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		rst = 0;
		IRWrite = 1;
		RegSelect1 = 0;
		RegSelect2 = 2'd0;
		RegWrite = 1;
		ALUSrcA = 2'd0;
		ALUSrcB = 2'd1;
		ALUSelect = 4'd3;
		Instr26 = 0;
		PCWriteCond = 0;
		PCWrite = 0;  // setting this to 1 will increment PC though IMEM opcode outputs
		PCSource = 0;
		MemWrite = 1;
		MemtoReg = 0;
		
        
		#100 
		rst = 1;
		#100
		rst = 0;	
	
*/
