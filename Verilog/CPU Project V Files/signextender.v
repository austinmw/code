`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:26:17 11/15/2015 
// Design Name: 
// Module Name:    signextender 
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
module signextender(in, out);
	input  [15:0] in;
	output [31:0] out;
		
	assign out = { {16{in[15]}}, in};
	
endmodule
