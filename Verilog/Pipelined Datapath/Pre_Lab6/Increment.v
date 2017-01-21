`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    02:08:30 10/17/2015 
// Design Name: 
// Module Name:    Increment 
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
module Increment(
	input [31:0] in1,
	input [31:0] in2,
	output [31:0] out
   );

	assign out = in1 + in2;

endmodule
