`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:06:42 10/26/2015
// Design Name:   alu_top
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/verilog projects/Lab6/alu_top_tb.v
// Project Name:  Lab6
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

	// Inputs
	reg [31:0] a;
	reg [31:0] b;
	reg c_in;
	reg [2:0] operation;

	// Outputs
	wire [31:0] result;
	wire c_out;

	// Instantiate the Unit Under Test (UUT)
	alu_top uut (
		.a(a), 
		.b(b), 
		.c_in(c_in), 
		.operation(operation), 
		.result(result), 
		.c_out(c_out)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;
		c_in = 0;
		operation = 0;

		// Wait 100 ns for global reset to finish
		#100;
		a = 32'd5;
		b = 32'd2;
		operation = 0;

		#100;
		a = 32'hffffffff;
		b = 0;
		operation = 1;

		#100;
		a = 32'hfffffffe;
		b = 1;
		operation = 2;

		#100;
		a = 32'hffffffff;
		b = 1;
		operation = 3;
		
		#100;
		a = 32'hfffffffe;
		b = 1;
		operation = 4;
	
		#100;
		a = 32'b101;
		b = 32'b111;
		operation = 5;
	
		#100;
		a = 32'd5;
		b = 32'd5;
		operation = 6;
	
		#100;
		a = 32'd5;
		b = 32'd6;
		operation = 6;
	
		#100;
		a = 32'd5;
		b = 32'd5;
		operation = 7;

	end
      
endmodule

