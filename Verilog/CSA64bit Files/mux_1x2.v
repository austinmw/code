`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:21:13 09/29/2015 
// Design Name: 
// Module Name:    mux_1x2 
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
module mux_1x2(in0, in1, select, out);
// might need to make this mux bigger?
input in0, in1;
input select;
output out;

reg out;
wire [1:0] In;
wire Select;

always @(in0 or in1 or select)
begin
	if (select == 0)
		out = in0;
	if (select == 1)
		out = in1;
end
endmodule
