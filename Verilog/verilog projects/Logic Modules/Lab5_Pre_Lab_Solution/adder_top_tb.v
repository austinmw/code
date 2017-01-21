`timescale 1ns / 1ns

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:34:20 10/05/2015
// Design Name:   top
// Module Name:   C:/Users/Ethan/Desktop/Lab5_Pre_Lab/Pre_Lab5/top_tb.v
// Project Name:  Pre_Lab5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module adder_top_tb;

	parameter W = 16;

	// Inputs
	reg clk;
	reg [W-1:0] a;
	reg [W-1:0] b;
	reg c_in;

	// Outputs
	wire [W-1:0] sum;
	wire c_out;

	// Instantiate the Unit Under Test (UUT)
	adder_top 
	#(.W(W))
	top_module (
		.clk(clk), 
		.a(a), 
		.b(b), 
		.c_in(c_in), 
		.sum(sum),
		.c_out(c_out)
	);
	
	

	always #5 clk = ~clk;

	initial begin
		// Initialize Inputs
		clk = 0;
		a = 0;
		b = 0;
		c_in = 0;

		// Wait 100 ns for global reset to finish
		#100;
		a = 1;
		b = 1;
		c_in = 1;
        
		// Add stimulus here

	end
      
endmodule

