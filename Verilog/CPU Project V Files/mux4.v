`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:16:27 11/15/2015 
// Design Name: 
// Module Name:    mux4 
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
module mux4(sel, in0, in1, in2, in3, out);
	parameter bitwidth = 32; // bitwidth default: 32-bit
	input [1:0] sel;
	input  [bitwidth-1:0] in0, in1, in2, in3;
	output [bitwidth-1:0] out;
	
	assign out = (sel == 0) ? in0 :  // in0: B
					 (sel == 1) ? in1 :  // in1: 32'd1;
					 (sel == 2) ? in2 :  // in2: immediate 32-bit (Instr[15:0] sign extended to 32-bit)
					 (sel == 3) ? in3 :  // in3: 32-bit address (might not need to shift by 2 if word addressable)
									    0 ;
endmodule
