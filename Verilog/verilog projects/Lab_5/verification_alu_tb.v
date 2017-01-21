`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:23:10 10/11/2015
// Design Name:   verification_alu
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/Lab_5/verification_alu_tb.v
// Project Name:  Lab_5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: verification_alu
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module verification_alu_tb;

parameter W = 32;

	// Inputs
	reg c_in;
	reg [W-1:0] a;
	reg [W-1:0] b;
	reg [2:0] operation;

	// Outputs
	wire [W-1:0] result;
	wire c_out;

	// Instantiate the Unit Under Test (UUT)
	verification_alu uut (
		.c_in(c_in), 
		.a(a), 
		.b(b), 
		.operation(operation), 
		.result(result), 
		.c_out(c_out)
	);

	initial begin
		// Initialize Inputs
		c_in = 0;
		a = 32'hffffffff;
		b = 1'b1;
		operation = 2;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

