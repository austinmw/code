`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:31:41 11/15/2015 
// Design Name: 
// Module Name:    mux2 
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
module mux2(sel, a, b, y);
	parameter bitwidth = 32;  // bitwidth default: 32-bit
	input sel;
	input  [bitwidth-1:0] a, b;
	output [bitwidth-1:0] y;
	
	assign y = sel ? b : a;
	
endmodule

/*  Instantiations:

mux2 #(16) my16bit_mux(s, a, b, c);
mux2 myDefault32bit_mux(s, j, k, l);

*/