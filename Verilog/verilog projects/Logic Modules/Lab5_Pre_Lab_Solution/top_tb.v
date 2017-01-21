`timescale 1ns / 1ns

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:20:24 10/05/2015
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

module top_tb;

	parameter W = 32;

	// Inputs
	reg clk;
	reg [W-1:0] a;
	reg [W-1:0] b;
	reg c_in;

	// Outputs
	wire c_out;
	wire [W-1:0] sum;
	wire c_out_verify;
	wire [W-1:0] sum_verify;

	// Instantiate the Unit Under Test (UUT)
	top 
	#(.W(W))
	top_module
	(
		.clk(clk), 
		.a(a), 
		.b(b), 
		.c_in(c_in), 
		.c_out(c_out), 
		.sum(sum), 
		.c_out_verify(c_out_verify), 
		.sum_verify(sum_verify)
	);


	// Set clk input
	always #5 assign clk = ~clk;
	
	// Assign random input to a, b, c_in
	always #200 assign {c_in, b, a} = {$random, $random, $random};
	
	// Assign Error_flag
	assign error_flag = (c_out != c_out_verify || sum != sum_verify);

	// Verification logic
	always@(posedge clk)
		begin
		if(error_flag)
			$display("Error occurs when a = %d, b = %d, c_in = %d\n", a, b, c_in);
		end

	initial begin
		// Initialize Inputs
		clk = 0;
		a = 0;
		b = 0;
		c_in = 0;

	end
      
endmodule

