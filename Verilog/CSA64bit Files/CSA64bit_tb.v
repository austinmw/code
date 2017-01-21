`timescale 1ns / 1ns

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:48:25 10/01/2015
// Design Name:   CSA64bit
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/CSA64bit/CSA64bit_tb.v
// Project Name:  CSA64bit
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CSA64bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module CSA64bit_tb;

	// Inputs
	reg [63:0] a;
	reg [63:0] b;
	reg clk;

	// Outputs
	wire [63:0] sum, sum_verify;
	wire c_out, c_out_verify;
	
	verification_csa64bit verify(
	.c_out(c_out_verify),
	.sum(sum_verify),
	.a(a),
	.b(b)
	);
	
	// Assign Error_flag
	assign error_flag = (c_out != c_out_verify || sum != sum_verify);
	
	// Verification Logic
	always@(posedge clk)
		begin
		if(error_flag)
			$display("Error occurs when a = %d, b = %d\n", a, b);
		end
		
		// Define clk signal for verification purpose
		always #5 clk = ~clk;

	// Instantiate the Unit Under Test (UUT)
	CSA64bit uut (
		.a(a), 
		.b(b), 
		.sum(sum), 
		.c_out(c_out)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;
		clk = 0;
		
		#200
		a = 64'hffffffffffffffff;
		b = 64'd1;
					
	end
endmodule

