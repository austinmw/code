`timescale 1ns / 1ns

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:06:43 10/10/2015
// Design Name:   alu_top
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/Lab_5/alu_top_tb.v
// Project Name:  Lab_5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: alu_top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module alu_top_tb;

	parameter W = 32;
	
	// Inputs
	reg clk;
	reg [W-1:0] a;
	reg [W-1:0] b;
	reg c_in;
	reg [2:0] operation;

	// Outputs
	wire [W-1:0] result;
	wire c_out;
	
	// Instantiate the Unit Under Test (UUT)
	alu_top uut (
		.clk(clk), 
		.a(a), 
		.b(b), 
		.c_in(c_in), 
		.operation(operation), 
		.result(result), 
		.c_out(c_out)
	);

always #5 clk = ~clk;

	initial begin
		// Initialize Inputs
		clk = 0;
		a = 1;
		b = 32'd5;
		c_in = 0;
		operation = 6;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

