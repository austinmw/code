`timescale 1ns / 1ns

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:39:35 10/10/2015
// Design Name:   top_module
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/Lab_5/top_module_tb.v
// Project Name:  Lab_5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: top_module
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module top_module_tb;

parameter W = 4;

	// Inputs
	reg clk;
	reg [W-1:0] a;
	reg [W-1:0] b;
	reg c_in;
	reg [2:0] operation;

	// Outputs
	wire [W-1:0] result;
	wire [W-1:0] result_verify;
	wire c_out;
	wire c_out_verify;

	// Instantiate the Unit Under Test (UUT)
	top_module 
	#(.W(W))
	uut (
		.clk(clk), 
		.a(a), 
		.b(b), 
		.c_in(c_in), 
		.operation(operation), 
		.result(result), 
		.result_verify(result_verify), 
		.c_out(c_out), 
		.c_out_verify(c_out_verify)
	);

	// set clk
	always #5 assign clk = ~clk;
	
	// random inputs
	//always #200 assign {c_in, a, b, operation} = {$random, $random, $random, $random};
	
	// error_flag
	assign error_flag = (c_out != c_out_verify || result != result_verify);
	
	// verification logic
	always@(posedge clk)
		begin
		if(error_flag)
			$display("Error occurs when operation = %d, a = %d, b = %d, c_in = %d\n", operation, a, b, c_in);
		end
		
		
	initial begin
		// Initialize Inputs
		clk = 0;
		a = 32'hffffffff;
		b = 1'b1;
		c_in = 1;
		operation = 0;
		
		#10
		clk = 0;
		a = 0;
		b = 1;
		c_in = 0;
		operation = 1;
		
	   #10
		clk = 0;
		a = 32'hffffffff;
		b = 1;
		c_in = 0;
		operation = 2;
		
		#10
		clk = 0;
		a = 32'hffffffff;
		b = 32'hffffffff;
		c_in = 0;
		operation = 2;
		
		#10
		clk = 0;
		a = 32'hffffffff;
		b = 0;
		c_in = 1;
		operation = 2;
		
		#10
		clk = 0;
		a = 32'hffffffff;
		b = 1;
		c_in = 0;
		operation = 3;
		
		#10
		clk = 0;
		a = 32'hffffffff;
		b = 1;
		c_in = 1;
		operation = 3;
		
		#10
		clk = 0;
		a = 0;
		b = 1;
		c_in = 0;
		operation = 3;
		
		#10
		clk = 0;
		a = 0;
		b = 32'hffffffff;
		c_in = 0;
		operation = 3;
		
		#10
		clk = 0;
		a = 0;
		b = 1;
		c_in = 1;
		operation = 3;
		
		#10
		clk = 0;
		a = 1;
		b = 32'hfffffffe;
		c_in = 0;
		operation = 4;
		
		#10
		clk = 0;
		a = 32'hfffffffe;
		b = 0;
		c_in = 0;
		operation = 4;
		
		#10
		clk = 0;
		a = 32'heeeeeeee;
		b = 32'h0101010101010101;
		c_in = 0;
		operation = 5;
		
		#10
		clk = 0;
		a = 0;
		b = 32'hffffffff;
		c_in = 1;
		operation = 5;
		
		#10
		clk = 0;
		a = 32'hffffffff;
		b = 0;
		c_in = 1;
		operation = 6;
		
		#10
		clk = 0;
		a = 0;
		b = 32'hffffffff;
		c_in = 0;
		operation = 7;
		
		
		
		
		

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

