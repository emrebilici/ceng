`timescale 1ns / 1ps

module testbench_ROM(
    );
	reg [3:0] romAddress; 
	wire[4:0] romData;
	integer result = 0;
	 
    FUNCROM ROM(romAddress,romData);

	initial begin
	
		$display("Starting Testbench");
		
		//sample 2 cases
		#1; 
		romAddress=4'b0000; 
		#7; 
		if (romData==5'b00000) result = result + 1; 	
			else $display("time:",$time,":For romAddress:%b Error in romData:%b",romAddress,romData);	

		#1; 
		
		romAddress=4'b0001; 
		#7; 
		if (romData==5'b00010) result = result + 1; 	
			else $display("time:",$time,":For romAddress:%b Error in romData:%b",romAddress,romData);	

		#1; 

		romAddress=4'b0010; 
		#7; 
		if (romData==5'b00100) result = result + 1; 	
			else $display("time:",$time,":For romAddress:%b Error in romData:%b",romAddress,romData);	

		#1; 
		romAddress=4'b1111; 
		#7; 
		if (romData==5'b11111) result = result + 1; 	
			else $display("time:",$time,":For romAddress:%b Error in romData:%b",romAddress,romData);	

		#1; 
		romAddress=4'b0001; 
		#7; 
		if (romData==5'b00010) result = result + 1; 	
			else $display("time:",$time,":For romAddress:%b Error in romData:%b",romAddress,romData);	

		#1; 
		romAddress=4'b0001; 
		#7; 
		if (romData==5'b00010) result = result + 1; 	
			else $display("time:",$time,":For romAddress:%b Error in romData:%b",romAddress,romData);	

		#1; 
		romAddress=4'b0001; 
		#7; 
		if (romData==5'b00010) result = result + 1; 	
			else $display("time:",$time,":For romAddress:%b Error in romData:%b",romAddress,romData);	

		#1; 
		romAddress=4'b0001; 
		#7; 
		if (romData==5'b00010) result = result + 1; 	
			else $display("time:",$time,":For romAddress:%b Error in romData:%b",romAddress,romData);	

		#1; 
		//fill the remaining cases...
	
		$display("Result %d",result);	
		$display("Testbench was finished");	
		$finish;
	end
	
	
endmodule

