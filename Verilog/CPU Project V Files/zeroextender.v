`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:45:45 11/15/2015 
// Design Name: 
// Module Name:    zeroextender 
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
module zeroextender(in, out);
	input  [15:0] in;
	output [31:0] out;
		
	assign out = {16'd0, in};

endmodule