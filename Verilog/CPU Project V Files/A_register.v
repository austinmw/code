`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:06:29 11/29/2015 
// Design Name: 
// Module Name:    A_register 
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
module A_register(
	input clock,
	input [W-1:0] a_in,
	output [W-1:0] a_out
   );

	parameter W = 32; // default

	reg [W-1:0] Reg;

	assign a_out = Reg;

	always@(posedge clock)
		begin
		Reg <= a_in;
		end

endmodule
