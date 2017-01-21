`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:59:32 10/21/2015 
// Design Name: 
// Module Name:    S2_Register 
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
module S2_Register(
   
	input clk, rst,
	input [31:0] ReadData1_in, ReadData2_in,
	input [15:0] Immediate_S1,
	input DataSource_S1, WriteEnable_S1,
	input [2:0] AluOp_S1,
	input [4:0] WriteSelect_S1,
	output reg [31:0] ReadData1_out, ReadData2_out,
	output reg [15:0] Immediate_S2,
	output reg DataSource_S2, WriteEnable_S2,
	output reg [2:0] AluOp_S2,
	output reg [4:0] WriteSelect_S2	 
);

	always@(posedge clk)
		begin
			if (rst)
				begin
					ReadData1_out  <= 32'd0;
					ReadData2_out  <= 32'd0;
					Immediate_S2   <= 16'd0;
					DataSource_S2  <= 1'b0;
					WriteEnable_S2 <= 1'b0;
					AluOp_S2       <= 3'd0;
					WriteSelect_S2 <= 5'd0;
            end
			else
				begin	
					ReadData1_out  <= ReadData1_in;
					ReadData2_out  <= ReadData2_in;
					Immediate_S2   <= Immediate_S1;
					DataSource_S2  <= DataSource_S1;
					WriteEnable_S2 <= WriteEnable_S1;
					AluOp_S2       <= AluOp_S1;
					WriteSelect_S2 <= WriteSelect_S1;
				end
			end

endmodule
