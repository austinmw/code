`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:10:53 11/29/2015 
// Design Name: 
// Module Name:    ALUOut_register 
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
module ALUOut_register(
	input clock,
	input [W-1:0] ALUOut_in,
	output [W-1:0] ALUOut_out
   );

	parameter W = 32; // default

	reg [W-1:0] Reg;

	assign ALUOut_out = Reg;

	always@(posedge clock)
		begin
		Reg <= ALUOut_in;
		end

endmodule
