`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:20:19 10/21/2015 
// Design Name: 
// Module Name:    S1_Register 
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
module S1_Register(

	input clk, rst,
	input [31:0] InstrIn,
	output reg [4:0] ReadSelect1, ReadSelect2, WriteSelect_S1,
	output reg [15:0] Immediate_S1,
	output reg DataSource_S1, WriteEnable_S1,
	output reg [2:0] AluOp_S1
);

	always@(posedge clk)
		begin
		if (rst)
			begin
				WriteSelect_S1 <= 5'd0;
				ReadSelect1 <= 5'd0;
				ReadSelect2 <= 5'd0;
				WriteEnable_S1 <= 1'b0;
				Immediate_S1 <= 16'd0;
				DataSource_S1 <= 1'b0;
				AluOp_S1 <= 3'b0;
			end
		else
			begin
				WriteSelect_S1 <= InstrIn[25:21];
				ReadSelect1 <= InstrIn[20:16];
				ReadSelect2 <= InstrIn[15:11];
				WriteEnable_S1 <= 1'b1;
				Immediate_S1 <= InstrIn[15:0];
				DataSource_S1 <= InstrIn[29];
				AluOp_S1 <= InstrIn[28:26];
			end
		end

endmodule



