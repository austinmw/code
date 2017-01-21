`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:52:55 10/21/2015 
// Design Name: 
// Module Name:    S3_Register 
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
module S3_Register(  
	input clk, rst,
	input [31:0] ALU_to_S3,
	input [4:0] WriteSelect_S2,
	input WriteEnable_S2,
	output reg [31:0] Out,
	output reg [4:0] WriteSelect_S3,
	output reg WriteEnable_S3
);

always@(posedge clk)
	begin 
	if (rst)
		begin
			Out <= 32'd0;
			WriteSelect_S3 <= 5'd0;
			WriteEnable_S3 <= 1'b0;		
		end
	else
		begin
			Out <= ALU_to_S3;
			WriteSelect_S3 <= WriteSelect_S2;
			WriteEnable_S3 <= WriteEnable_S2;		
		end
	end

endmodule
