`timescale 1ns / 1ns

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:44:41 10/11/2015
// Design Name:   top_verification_alu
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/Lab_5/top_verification_alu_tb.v
// Project Name:  Lab_5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: top_verification_alu
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module top_verification_alu_tb;

parameter W = 32;

	// Inputs
	reg clk;
	reg c_in;
	reg [W-1:0] a;
	reg [W-1:0] b;
	reg [2:0] operation;

	// Outputs
	wire [W-1:0] result_verify;
	wire c_out_verify;

	// Instantiate the Unit Under Test (UUT)
	top_verification_alu uut (
		.clk(clk), 
		.c_in(c_in), 
		.a(a), 
		.b(b), 
		.operation(operation), 
		.result_verify(result_verify), 
		.c_out_verify(c_out_verify)
	);



always #5 assign clk = ~clk;


	initial begin
		// Initialize Inputs
		clk = 0;
		c_in = 0;
		a = 32'hffffffff;
		b = 1'b1;
		operation = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

