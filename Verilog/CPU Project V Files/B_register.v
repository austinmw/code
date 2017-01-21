`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:09:15 11/29/2015 
// Design Name: 
// Module Name:    B_register 
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
module B_register(
	input clock,
	input [W-1:0] b_in,
	output [W-1:0] b_out
   );

	parameter W = 32; // default

	reg [W-1:0] Reg;

	assign b_out = Reg;

	always@(posedge clock)
		begin
		Reg <= b_in;
		end

endmodule
