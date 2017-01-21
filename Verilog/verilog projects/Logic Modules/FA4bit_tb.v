`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:25:01 09/28/2015
// Design Name:   FA4bit
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/lab4prelab/FA4bit_tb.v
// Project Name:  lab4prelab
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: FA4bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module FA4bit_tb;

	// Inputs
	reg [3:0] a;
	reg [3:0] b;
	reg c_in;

	reg clk;


		
		
	// Outputs
	wire c_out, c_out_verify;
	wire [3:0] sum, sum_verify;
	
	
	// Verification module
	Verification_4bit Verification (
		.c_out(c_out_verify), 
		.sum(sum_verify), 
		.a(a), 
		.b(b), 
		.c_in(c_in)
	);
	
	// Assign Error_flag
	assign error_flag = (c_out != c_out_verify || sum != sum_verify);
	
	// Verification logic
	always@(posedge clk)
		begin
		if(error_flag)
			// Use $display here instead of $monitor
			// $monitor will display the message whenever there's a change of a, b, c_in
			// $display will only display once when it's been executed
			$display("Error occurs when a = %d, b = %d, c_in = %d\n", a, b, c_in);
		end
		
	// Derfine clk signal for Verfication purpose
	always #5 clk = ~clk;
	// Instantiate the Unit Under Test (UUT)
	FA4bit uut (
		.c_out(c_out), 
		.sum(sum), 
		.a(a), 
		.b(b), 
		.c_in(c_in)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;
		c_in = 0;
		clk = 1;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      always #10
		assign {a, b} = {a, b} +1'b1; 
		
endmodule

