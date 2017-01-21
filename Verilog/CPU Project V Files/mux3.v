`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:05:53 11/15/2015 
// Design Name: 
// Module Name:    mux3 
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
module mux3(sel, in0, in1, in2, out);
	parameter bitwidth = 32; // bitwidth default: 32-bit
	input [1:0] sel;
	input  [bitwidth-1:0] in0, in1, in2;
	output [bitwidth-1:0] out;
	
	assign out = (sel == 0) ? in0 :  // in0: ALUResult
					 (sel == 1) ? in1 :  // in1: ALUOut
					 (sel == 2) ? in2 :  // in2: PC
									    0 ;
endmodule
