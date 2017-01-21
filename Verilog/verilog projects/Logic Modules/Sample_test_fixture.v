/*********************************************************
*	This is a sample test fixture, that would have an
*	automated error/glitch checking.
*	This module assumes a 4-bit adder named RCA4bit.
*	The ideal output is generated in the function
*	adder_4bit_ideal, and all the possible combinations
*	are looped through using a "for-loop"
*********************************************************/
`timescale 1ns / 1ps	// This line describes the time_units/simulation_precision

module test_RCA4;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg CIN;

	// Outputs
	wire COUT;
	wire [3:0] SUM;
	
	// counters (optional).
	integer k;
	
	// comparator part
	wire [4:0] error_bits;
	wire error_flag;
	
	// Instantiate the Unit Under Test (UUT) with some gate delay
	RCA4bit #(0) uut (	// Note the delay
		.COUT(COUT), 
		.SUM(SUM), 
		.A(A), 
		.B(B), 
		.CIN(CIN)
	);
	
	// create an ideal function
	function [4:0]adder_4bit_ideal;
		input [3:0]A, B;
		input CIN;
		begin
			adder_4bit_ideal = A + B + CIN;
		end
	endfunction
	
	// calculate the error bits, and create an error flag
	assign error_bits = adder_4bit_ideal(A, B, CIN)^{COUT,SUM};	//comparison
	assign error_flag = |error_bits;

	initial begin
		A = 0; B = 0; CIN = 0;
	end
	
	// create all possible combinations (stimuli)
	//	note that you can generate the combinations in different ways
	/*
	initial begin
		for (k = 1; k<=2**10; k = k+1) begin
			#10 {A,B,CIN} = {A,B,CIN} + 1'b1;
		end
	end
	*/
	
	// Use $random to test random inputs
	always begin
		#10 {A,B,CIN} = {$random, $random};	// $random returns a 32bit string
	end
    
endmodule

