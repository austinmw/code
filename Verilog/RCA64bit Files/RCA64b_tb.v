`timescale 1ns / 1ns

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:41:05 09/29/2015
// Design Name:   RCA64b
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/RCA54b/RCA64b_tb.v
// Project Name:  RCA54b
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: RCA64b
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module RCA64b_tb;

	// Inputs
	reg [63:0] A;
	reg [63:0] B;
	reg C_in;
	reg clk;

	// Outputs
	wire [63:0] sum, sum_verify;
	wire C_out, C_out_verify;	// Verification module
	Verification_64b Verification (
		.C_out(C_out_verify), 
		.sum(sum_verify), 
		.A(A), 
		.B(B), 
		.C_in(C_in)
	);
	
	// Assign Error_flag
	assign error_flag = (C_out != C_out_verify || sum != sum_verify);
	
	// Verification logic
	always@(posedge clk)
		begin
		if(error_flag)
			// Use $display here instead of $monitor
			// $monitor will display the message whenever there's a change of a, b, c_in
			// $display will only display once when it's been executed
			$display("Error occurs when a = %d, b = %d, c_in = %d\n", A, B, C_in);
		end
		
	// Define clk signal for Verfication purpose
	always #5 clk = ~clk;	
	
	
	
	// Instantiate the Unit Under Test (UUT)
	RCA64b uut (
		.A(A), 
		.B(B), 
		.sum(sum), 
		.C_in(C_in), 
		.C_out(C_out)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		C_in = 0;
		clk = 0;

		// Wait 100 ns for global reset to finish
		#200;
		
		A = 64'hffffffffffffffff;
		B = 64'b1;
		C_in = 1;
        
		// Add stimulus here

	end
	      
endmodule

