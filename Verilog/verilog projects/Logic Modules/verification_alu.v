`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:34:43 10/10/2015 
// Design Name: 
// Module Name:    verification_alu 
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
module verification_alu(
input c_in,
input [W-1:0] a, b,
input [2:0] operation,
output reg [W-1:0] result,
output reg c_out
);
parameter W = 32;

always@*
begin
	case(operation)
			0: begin result = a; c_out = 0; end
			1: begin result = ~a; c_out = 0; end
			2: {c_out, result} = a + b + c_in;
			3: {c_out, result} = a - b + c_in;
			4: begin result = a | b; c_out = 0; end
			5: begin result = a & b; c_out = 0; end
			default: {c_out, result} = 0;
		endcase
end
endmodule
