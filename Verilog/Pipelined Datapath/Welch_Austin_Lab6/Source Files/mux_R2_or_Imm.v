`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:42:32 10/21/2015 
// Design Name: 
// Module Name:    mux_R2_or_Imm 
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
module mux_R2_or_Imm(
	input [31:0] R2,
	input [15:0] Imm,
	input select,
	output reg [31:0] mux_to_R3
);

always @(R2 or Imm or select)
	begin
		if (select == 0)
			mux_to_R3 <= R2;
		if (select == 1)
			mux_to_R3 <= {16'd0, Imm};
	end

endmodule
