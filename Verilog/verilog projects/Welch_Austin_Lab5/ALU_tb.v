`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:13:12 10/09/2015
// Design Name:   ALU
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/Lab_5/ALU_tb.v
// Project Name:  Lab_5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ALU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ALU_tb;

	// Inputs
	reg a;
	reg b;
	reg c_in;
	reg [2:0] operation;

	// Outputs
	wire result;
	wire c_out;

	// Instantiate the Unit Under Test (UUT)
	ALU uut (
		.a(a), 
		.b(b), 
		.c_in(c_in), 
		.operation(operation), 
		.result(result), 
		.c_out(c_out)
	);

	initial begin
		// Initialize Inputs
		a = 1;
		b = 0;
		c_in = 0;
		operation = 0;
		
		#10
		a = 0;
		b = 1;
		c_in = 0;
		operation = 0;		
		
		#10
		a = 1;
		b = 0;
		c_in = 0;
		operation = 1;	

		#10
		a = 0;
		b = 0;
		c_in = 0;
		operation = 1;		

		#10
		a = 1;
		b = 0;
		c_in = 0;
		operation = 2;		
		
		#10
		a = 1;
		b = 1;
		c_in = 0;
		operation = 2;	
		
		#10
		a = 1;
		b = 1;
		c_in = 1;
		operation = 2;	
		
		#10
		a = 1;
		b = 1;
		c_in = 0;
		operation = 3;		
		
		#10
		a = 1;
		b = 0;
		c_in = 0;
		operation = 3;		
		
		#10
		a = 0;
		b = 0;
		c_in = 0;
		operation = 3;	

		#10
		a = 0;
		b = 1;
		c_in = 0;
		operation = 3;	
      //what's the answer for this supposed to be?		

		#10
		a = 1;
		b = 1;
		c_in = 1;
		operation = 3;
		
		#10
		a = 0;
		b = 1;
		c_in = 0;
		operation = 4;		

		#10
		a = 1;
		b = 1;
		c_in = 0;
		operation = 5;	

		#10
		a = 1;
		b = 0;
		c_in = 0;
		operation = 5;			

		#10
		a = 1;
		b = 0;
		c_in = 0;
		operation = 6;		

		#10
		a = 1;
		b = 1;
		c_in = 0;
		operation = 7;		
		

		// Wait 100 ns for global reset to finish
		#200;
        
		// Add stimulus here

	end
      
endmodule

