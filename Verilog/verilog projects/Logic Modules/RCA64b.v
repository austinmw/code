`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:09:33 09/29/2015 
// Design Name: 
// Module Name:    RCA64b 
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
module RCA64b(A, B, sum, C_in, C_out);

	input [63:0] A, B;	
	input C_in;
	output [63:0] sum;
	output C_out;
	wire [14:0] gate_connect;
	// module FA4bit(c_out, sum, a, b, c_in);
	FA4bit fa4_01(gate_connect[0], sum[3:0], A[3:0], B[3:0], C_in);
	FA4bit fa4_02(gate_connect[1], sum[7:4], A[7:4], B[7:4], gate_connect[0]);
	FA4bit fa4_03(gate_connect[2], sum[11:8], A[11:8], B[11:8], gate_connect[1]);
	FA4bit fa4_04(gate_connect[3], sum[15:12], A[15:12], B[15:12], gate_connect[2]);
	FA4bit fa4_05(gate_connect[4], sum[19:16], A[19:16], B[19:16], gate_connect[3]);
	FA4bit fa4_06(gate_connect[5], sum[23:20], A[23:20], B[23:20], gate_connect[4]);
	FA4bit fa4_07(gate_connect[6], sum[27:24], A[27:24], B[27:24], gate_connect[5]);
	FA4bit fa4_08(gate_connect[7], sum[31:28], A[31:28], B[31:28], gate_connect[6]);
	FA4bit fa4_09(gate_connect[8], sum[35:32], A[35:32], B[35:32], gate_connect[7]);
	FA4bit fa4_10(gate_connect[9], sum[39:36], A[39:36], B[39:36], gate_connect[8]);
	FA4bit fa4_11(gate_connect[10], sum[43:40], A[43:40], B[43:40], gate_connect[9]);
	FA4bit fa4_12(gate_connect[11], sum[47:44], A[47:44], B[47:44], gate_connect[10]);
	FA4bit fa4_13(gate_connect[12], sum[51:48], A[51:48], B[51:48], gate_connect[11]);
	FA4bit fa4_14(gate_connect[13], sum[55:52], A[55:52], B[55:52], gate_connect[12]);
	FA4bit fa4_15(gate_connect[14], sum[59:56], A[59:56], B[59:56], gate_connect[13]);
	FA4bit fa4_16(C_out, sum[63:60], A[63:60], B[63:60], gate_connect[14]);	
	

endmodule
