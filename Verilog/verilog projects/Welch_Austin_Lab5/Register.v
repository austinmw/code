`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:44:05 10/04/2015 
// Design Name: 
// Module Name:    Register 
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
module Register(
	input clk,
	input [W-1:0] reg_in,
	output [W-1:0] reg_out
   );

	parameter W = 32;

	reg [W-1:0] Reg;

	assign reg_out = Reg;

	always@(posedge clk)
		begin
		Reg <= reg_in;
		end


endmodule
