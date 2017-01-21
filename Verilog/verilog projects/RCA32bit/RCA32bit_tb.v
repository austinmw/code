`timescale 1ns / 1ns

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:03:27 10/01/2015
// Design Name:   RCA32bit
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/RCA32bit/RCA32bit_tb.v
// Project Name:  RCA32bit
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: RCA32bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module RCA32bit_tb;

	// Inputs
	reg [31:0] a;
	reg [31:0] b;
	reg c_in;

	// Outputs
	wire [31:0] sum;
	wire c_out;

	// Instantiate the Unit Under Test (UUT)
	RCA32bit uut (
		.a(a), 
		.b(b), 
		.sum(sum), 
		.c_in(c_in), 
		.c_out(c_out)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;
		c_in = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

