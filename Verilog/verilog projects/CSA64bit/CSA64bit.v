`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:06:53 10/01/2015 
// Design Name: 
// Module Name:    CSA64bit 
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
module CSA64bit(a, b, sum, c_out);

input [63:0] a, b;
parameter c_in = 1'b1;
output [63:0] sum;
wire [1:0] c_out_mux;
output c_out;
wire select;
wire [31:0] mux_connect_0, mux_connect_1;
parameter zero = 1'b0;
parameter one = 1'b1;

RCA32bit rca32_base(a[31:0], b[31:0], sum[31:0], c_in, select);

RCA32bit rca32_0(a[63:32], b[63:32], mux_connect_0[31:0], zero, c_out_mux[0]);
RCA32bit rca32_1(a[63:32], b[63:32], mux_connect_1[31:0], one, c_out_mux[1]);

mux_1x2 mux[31:0](mux_connect_0, mux_connect_1, select, sum[63:32]);
mux_1x2 carry_mux(c_out_mux[0], c_out_mux[1], select, c_out);

endmodule
