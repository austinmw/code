`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:05:55 10/21/2015 
// Design Name: 
// Module Name:    Pipeline_Top 
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
module Pipeline_Top(
	input clk, rst,
	input [31:0] InstrIn,
	output [31:0] Out
);

wire [4:0] RS1_to_file, RS2_to_file;
wire [31:0] RD1_file_to_S2, RD2_file_to_S2, RD1_S2_to_ALU, RD2_S2_to_mux; 
wire [31:0] RD2_mux_to_ALU, ALU_to_S3;
wire [4:0] WriteSelect_S1_to_S2, WriteSelect_S2_to_S3, WriteSelect_S3_to_file;
wire [15:0] Immediate_S1_to_S2, Immediate_S2_to_mux;
wire DataSource_S1_to_S2, DataSource_S2_to_mux;
wire WriteEnable_S1_to_S2, WriteEnable_S2_to_S3, WriteEnable_S3_to_file;
wire [2:0] AluOp_S1_to_S2, AluOp_S2_to_ALU;
wire c_out;
reg c_in = 0;

	S1_Register S1_Reg(
		.clk(clk),
		.rst(rst),
		.InstrIn(InstrIn),
		.ReadSelect1(RS1_to_file),
		.ReadSelect2(RS2_to_file),
		.WriteSelect_S1(WriteSelect_S1_to_S2),
		.Immediate_S1(Immediate_S1_to_S2),
		.DataSource_S1(DataSource_S1_to_S2),
		.WriteEnable_S1(WriteEnable_S1_to_S2),
		.AluOp_S1(AluOp_S1_to_S2)
	);
	
	
	nbit_register_file Reg_File(
		.WriteData(Out),   
      .ReadData1(RD1_file_to_S2),   
      .ReadData2(RD2_file_to_S2),   
      .ReadSelect1(RS1_to_file), 
      .ReadSelect2(RS2_to_file), 
      .WriteSelect(WriteSelect_S3_to_file), 
      .WriteEnable(WriteEnable_S3_to_file), 
      .Reset(rst),       
      .Clk(clk)	
		); 
		
		
	S2_Register S2_Reg(
		.clk(clk),
		.rst(rst),
		.ReadData1_in(RD1_file_to_S2),
		.ReadData2_in(RD2_file_to_S2),
		.Immediate_S1(Immediate_S1_to_S2),
		.DataSource_S1(DataSource_S1_to_S2),
		.WriteEnable_S1(WriteEnable_S1_to_S2),
		.AluOp_S1(AluOp_S1_to_S2),
		.WriteSelect_S1(WriteSelect_S1_to_S2),
		.ReadData1_out(RD1_S2_to_ALU),
		.ReadData2_out(RD2_S2_to_mux),
		.Immediate_S2(Immediate_S2_to_mux),
		.DataSource_S2(DataSource_S2_to_mux),
		.WriteEnable_S2(WriteEnable_S2_to_S3),
		.AluOp_S2(AluOp_S2_to_ALU),
		.WriteSelect_S2(WriteSelect_S2_to_S3)	
	);
				
		
	mux_R2_or_Imm Source_Mux(
		.R2(RD2_S2_to_mux),
		.Imm(Immediate_S2_to_mux),
		.select(DataSource_S2_to_mux),
		.mux_to_R3(RD2_mux_to_ALU)
	);
	
	
	alu_top ALU_32(
		.a(RD1_S2_to_ALU),
		.b(RD2_mux_to_ALU),
		.c_in(c_in),
		.operation(AluOp_S2_to_ALU),
		.result(ALU_to_S3),
		.c_out(c_out)
	);


	S3_Register S3_Reg(
		.clk(clk),
		.rst(rst),
		.ALU_to_S3(ALU_to_S3),
		.WriteSelect_S2(WriteSelect_S2_to_S3),
		.WriteEnable_S2(WriteEnable_S2_to_S3),
		.Out(Out),
		.WriteSelect_S3(WriteSelect_S3_to_file),
		.WriteEnable_S3(WriteEnable_S3_to_file)			
	);

endmodule
