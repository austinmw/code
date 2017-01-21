`timescale 1ns / 1ns
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:37:22 11/15/2015 
// Design Name: 
// Module Name:    ALU 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module ALU(aluSel, a, b, result, zero);
	input [3:0] aluSel; 
	input [31:0] a, b;
	output[31:0] result;
	output zero;
	reg [31:0] result = 32'd0;
	reg zero;
	
	always @(a or b or aluSel)
	begin
		case (aluSel)		
			4'd0 : result <= result;			   // NOOP
			4'd1 : result = a;    				   // MOV
			4'd2 : result = ~a; 	  					// NOT
			4'd3 : result = a + b; 					// ADD
			4'd4 : result = a - b; 					// SUB
			4'd5 : result = a | b;					// OR
			4'd6 : result = a & b; 					// AND
			4'd7 : if ($signed(a) < $signed(b)) result = 32'd1; 	// SLT 
					 else result = 32'd0;    
			4'd8 : result = b;      				// LI			
			4'd9 : result = {b[15:0], 16'd0}; 	// LUI
			4'd10: if (a < b) result = 32'd0; 	// BLT (makes result = 0 -> zero = 1 -> take branch)
					 else result = 32'd1;         //     (result = 1 -> zero = 0 -> don't take branch)
			4'd11: if (a <= b) result = 32'd0; 	// BLE (makes result = 0 -> zero = 1 -> take branch)
					 else result = 32'd1;         //      (result = 1 -> zero = 0 -> don't take branch)
			4'd12: result = a ^ b; 				   // XOR
						
			default : result = 32'hxxxxxxxx;
		endcase
		
		if (result == 32'd0) zero = 1;
		else zero = 0;
	end
endmodule

// gotta change a lot of this 