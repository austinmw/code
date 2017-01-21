`timescale 1ns / 1ns

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:42:52 11/30/2015
// Design Name:   CPU
// Module Name:   /ad/eng/users/a/u/austinmw/Desktop/verilog projects/CPU_Multicycle/CPU_test.v
// Project Name:  CPU_Multicycle
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CPU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module CPU_test;

	// Inputs
	reg clk;
	reg rst;

	// Outputs
	wire [31:0] pc_out;
	wire [31:0] ALU_OUT;

	always #25 assign clk = ~clk;

	// Instantiate the Unit Under Test (UUT)
	CPU uut (
		.clk(clk), 
		.rst(rst), 
		.pc_out(pc_out), 
		.ALU_OUT(ALU_OUT)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		
	end
      
endmodule

