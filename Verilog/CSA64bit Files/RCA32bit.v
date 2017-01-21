`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:26:13 10/01/2015 
// Design Name: 
// Module Name:    RCA32bit 
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
module RCA32bit(a, b, sum, c_in, c_out);

input [31:0] a, b;
input c_in;
output [31:0] sum;
output c_out;
wire [6:0] gate_connect;

// module FA4bit(c_out, sum, a, b, c_in)
FA4bit fa4_01(gate_connect[0], sum[3:0], a[3:0], b[3:0], c_in);
FA4bit fa4_02(gate_connect[1], sum[7:4], a[7:4], b[7:4], gate_connect[0]);
FA4bit fa4_03(gate_connect[2], sum[11:8], a[11:8], b[11:8], gate_connect[1]);
FA4bit fa4_04(gate_connect[3], sum[15:12], a[15:12], b[15:12], gate_connect[2]);
FA4bit fa4_05(gate_connect[4], sum[19:16], a[19:16], b[19:16], gate_connect[3]);
FA4bit fa4_06(gate_connect[5], sum[23:20], a[23:20], b[23:20], gate_connect[4]);
FA4bit fa4_07(gate_connect[6], sum[27:24], a[27:24], b[27:24], gate_connect[5]);
FA4bit fa4_08(c_out, sum[31:28], a[31:28], b[31:28], gate_connect[6]);

endmodule
