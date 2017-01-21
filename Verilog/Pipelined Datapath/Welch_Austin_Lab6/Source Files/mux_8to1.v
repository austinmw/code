`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:58:35 10/09/2015 
// Design Name: 
// Module Name:    mux_8to1 
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
module mux_8to1(
input in0, in1, in2, in3, in4, in5, in6, in7,   
input [2:0] select,
output reg out
);

always @*
begin
	if (select == 0)
		out = in0;
	if (select == 1)
		out = in1;
	if (select == 2)
		out = in2;
	if (select == 3)
		out = in3;
	if (select == 4)
		out = in4;
	if (select == 5)
		out = in5;
	if (select == 6)
		out = in6;
	if (select == 7)
		out = in7;
end
endmodule
