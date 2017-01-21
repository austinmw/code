`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:47:09 10/09/2015 
// Design Name: 
// Module Name:    ALU 
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
module ALU(
	input a, b,
	input c_in, 
	input [2:0] operation,
	output result,
	output c_out
	);
	parameter zero = 1'b0;

	wire a_inv, or_mux, and_mux, Binvert, b_not, b_to_FA, FA_to_mux;
	wire op_msb, op_lsb, FA_to_c_out, op_add, add_or_sub;
	reg SLT_to_mux;

	// 8-Function Mux Wires
	not (a_inv, a);           // 1: NOT

	// 2: ADD, 3: SUB, Binvert & c_out logic
	not (b_not, b); // inverts b
	not (op_msb, operation[2]); // inverts MSB of operation to use for following AND gate
	and (Binvert, op_msb, operation[1], operation[0]); // inverts B if operation is 3: SUB
	mux_1x2 mux_b_inv(b, b_not, Binvert, b_to_FA); // Binvert mux
	FA_str adder1b(FA_to_c_out, FA_to_mux, a, b_to_FA, c_in); // addition/subtraction, c_out
	// logic to create intermediate c_out, since c_out is always calculated
	// will only output c_out for ADD or SUB operations
	not (op_lsb, operation[0]);
	and (op_add, op_msb, operation[1], op_lsb);
	or (add_or_sub, op_add, Binvert);
	and (c_out, FA_to_c_out, add_or_sub);

	or (or_mux, a, b);        // 4: OR
	and (and_mux, a, b);      // 5: AND


	// 6: SLT
	always@*
		begin
			if (a < b)
				assign SLT_to_mux = 1;
			if (a >= b)
				assign SLT_to_mux = 0;
		end
		

	// Operation selection
	mux_8to1 alu_select(a, a_inv, FA_to_mux, FA_to_mux, or_mux, and_mux, SLT_to_mux, zero, operation, result);

endmodule
