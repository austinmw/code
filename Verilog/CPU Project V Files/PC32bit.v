`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:00:37 11/15/2015 
// Design Name: 
// Module Name:    PC32bit 
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
module PC32bit(
	input clock,
	input reset,
	input PC_on,
	input [31:0] PC_in,
	output [31:0] PC_out
   );
	

	reg [31:0] Reg = 0; // set starting value at 0 if reset doesn't work properly 

	assign PC_out = Reg;
	
	always@(posedge clock or reset)   
		begin
			if (reset)
				Reg <= 32'd0;
			else if (PC_on)
				Reg <= PC_in;
		end

endmodule

// double check if this should be clocked or controlled by PC_on only



