`timescale 1ns / 1ps

module af(
    input a,
    input f,
    input clk,
    output reg q
    );
    
    initial begin
        q = 0;
    end
	
    // write your code here
	 always @(posedge clk)
	 case({a,f})
	 2'b00: q<=~q;
	 2'b01: q<=q;
	 2'b10: q<=1'b1;
	 2'b11: q<=1'b0;

  endcase

endmodule


module ic1500(
    input a0, 
    input f0, 
    input a1, 
    input f1, 
    input clk, 
    output q0, 
    output q1, 
    output y
    );
    // write your code here
	 wire out0=q0,out1=q1;
	 assign y=out0^out1;

	 af af0(a0,f0,clk,q0);
	 af af1(a1,f1,clk,q1);
	 always @(posedge clk) begin
	
	end
	 

	
endmodule
