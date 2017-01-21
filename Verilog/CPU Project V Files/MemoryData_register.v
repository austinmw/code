`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:13:37 11/29/2015 
// Design Name: 
// Module Name:    MemoryData_register 
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
module MemoryData_register(
	input clock,
	input [W-1:0] data_in,
	output [W-1:0] data_out
   );

	parameter W = 32; // default data size

	reg [W-1:0] Reg;

	assign data_out = Reg;

	always@(posedge clock)
		begin
		Reg <= data_in;
		end

endmodule
