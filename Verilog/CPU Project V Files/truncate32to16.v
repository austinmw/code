`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:47:08 11/27/2015 
// Design Name: 
// Module Name:    truncate32to16 
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
module truncate32to16(in, out);

	input [31:0] in;
	output [15:0] out;
	
	assign out = in[15:0];

endmodule
