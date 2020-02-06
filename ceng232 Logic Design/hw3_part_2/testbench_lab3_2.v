`timescale 1ns / 1ps

module testbench_lab3_2;

	// Inputs
	reg [4:0] word;
	reg CLK;
	reg selection;
	reg mode;
	
	// Outputs
	wire [7:0] hipsterians1;
	wire [7:0] hipsterians0;
	wire [7:0] nerdians1;
	wire [7:0] nerdians0;
	wire warning;

	// Instantiate the Unit Under Test (UUT)
	lab3_2 uut (
		.word(word), 
		.selection(selection), 
		.mode(mode), 
		.CLK(CLK),
		.hipsterians1(hipsterians1), 
		.hipsterians0(hipsterians0), 
		.nerdians1(nerdians1), 
		.nerdians0(nerdians0), 
		.warning(warning)
	);
    // At 5, 15, 25, .. clk will change 1->0 
    // At 10, 20, 30, .. clk will change 0->1
    initial CLK = 1;
	always #5 CLK = ~CLK;
    
	initial begin
		// set monitor to inputs and outputs
		$monitor("Time=%t | word=%b selection=%b mode=%b | hips1=%d hips0=%d nerd1=%d nerd0=%d, warning=%b", 
					$time, word, selection, mode, hipsterians1, hipsterians0, nerdians1, nerdians0, warning);
		
		// Initialize Inputs
		word = 5'b00000;
		selection = 0;
		mode = 0;

		// Wait 5 ns for global reset to finish
		#5;
        
		  
		// Add stimulus here
		
		// #1: 1st example from hw3.pdf - in mode, increment 
		// word |s|m|h1|h0|n1|n0|next->|h1|h0|n1|n0|w
		// 10010|0|1|0 |0 |0 |0 |      |0 |1 |0 |0 |0
		word = 5'b10010;
		selection = 0;
		mode = 1;
		#10; // Wait for clock edge
		if (hipsterians1 != 0) $display("Test 1: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 1) $display("Test 1: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 1: Value of nerdians1 is wrong");
		else if (nerdians0 != 0) $display("Test 1: Value of nerdians0 is wrong");
		else if (warning != 0) $display("Test 1: Value of warning is wrong");
		else $display("Test 1: Successful");
		
		// #2: In mode, word in neither of the languages.
		// word |s|m|h1|h0|n1|n0|next->|h1|h0|n1|n0|w
		// 10101|0|1|0 |1 |0 |0 |      |0 |1 |0 |0 |1
		word = 5'b01010;
		selection = 0;
		mode = 1;
		#10; // Wait for clock edge
		if (hipsterians1 != 0) $display("Test 2: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 1) $display("Test 2: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 2: Value of nerdians1 is wrong");
		else if (nerdians0 != 0) $display("Test 2: Value of nerdians0 is wrong");
		else if (warning != 1) $display("Test 2: Value of warning is wrong");
		else $display("Test 2: Successful");
		
		// #3: In mode, nerdian increment
		// word |s|m|h1|h0|n1|n0|next->|h1|h0|n1|n0|w
		// 11111|1|1|0 |1 |0 |0 |      |0 |1 |0 |1 |0
		word = 5'b11111;
		selection = 1;
		mode = 1;
		#10; // Wait for clock edge
		if (hipsterians1 != 0) $display("Test 3: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 1) $display("Test 3: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 3: Value of nerdians1 is wrong");
		else if (nerdians0 != 1) $display("Test 3: Value of nerdians0 is wrong");
		else if (warning != 0) $display("Test 3: Value of warning is wrong");
		else $display("Test 3: Successful");
		
		// #4: Out mode, wrong selection
		// word |s|m|h1|h0|n1|n0|next->|h1|h0|n1|n0|w
		// 01101|0|0|0 |1 |0 |1 |      |0 |1 |0 |1 |1
		word = 5'b01101;
		selection = 0;
		mode = 0;
		#10; // Wait for clock edge
		if (hipsterians1 != 0) $display("Test 4: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 1) $display("Test 4: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 4: Value of nerdians1 is wrong");
		else if (nerdians0 != 1) $display("Test 4: Value of nerdians0 is wrong");
		else if (warning != 1) $display("Test 4: Value of warning is wrong");
		else $display("Test 4: Successful");
		
		// #5: Out mode, decrement
		// word |s|m|h1|h0|n1|n0|next->|h1|h0|n1|n0|w
		// 01101|1|0|0 |1 |0 |1 |      |0 |1 |0 |0 |0
		word = 5'b01101;
		selection = 1;
		mode = 0;
		#10; // Wait for clock edge
		if (hipsterians1 != 0) $display("Test 5: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 1) $display("Test 5: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 5: Value of nerdians1 is wrong");
		else if (nerdians0 != 0) $display("Test 5: Value of nerdians0 is wrong");
		else if (warning != 0) $display("Test 5: Value of warning is wrong");
		else $display("Test 5: Successful");
		
		// #6: Out mode, decrement when number of memorized words is 0.
		// word |s|m|h1|h0|n1|n0|next->|h1|h0|n1|n0|w
		// 01101|1|0|0 |1 |0 |0 |      |0 |1 |0 |0 |0
		word = 5'b01101;
		selection = 1;
		mode = 0;
		#10; // Wait for clock edge
		if (hipsterians1 != 0) $display("Test 6: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 1) $display("Test 6: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 6: Value of nerdians1 is wrong");
		else if (nerdians0 != 0) $display("Test 6: Value of nerdians0 is wrong");
		else if (warning != 0) $display("Test 6: Value of warning is wrong");
		else $display("Test 6: Successful");
		
		// #7: In mode, increment until 20
		// word |s|m|h1|h0|n1|n0|19 clk cycles->|h1|h0|n1|n0|w
		// 00101|0|1|0 |1 |0 |0 |               |2 |0 |0 |0 |0
		word = 5'b00101;
		selection = 0;
		mode = 1;
		#190 // 19 clock cycles
		if (hipsterians1 != 2) $display("Test 7: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 0) $display("Test 7: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 7: Value of nerdians1 is wrong");
		else if (nerdians0 != 0) $display("Test 7: Value of nerdians0 is wrong");
		else if (warning != 0) $display("Test 7: Value of warning is wrong");
		else $display("Test 7: Successful");
		
		// #8: In mode, reset after 20
		// word |s|m|h1|h0|n1|n0|19 clk cycles->|h1|h0|n1|n0|w
		// 00101|0|1|2 |0 |0 |0 |               |0 |0 |0 |0 |0
		word = 5'b00101;
		selection = 0;
		mode = 1;
		#10 // Wait for clock edge
		if (hipsterians1 != 0) $display("Test 8: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 0) $display("Test 8: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 8: Value of nerdians1 is wrong");
		else if (nerdians0 != 0) $display("Test 8: Value of nerdians0 is wrong");
		else if (warning != 0) $display("Test 8: Value of warning is wrong");
		else $display("Test 8: Successful");
		
		// #9: In mode, word in both languages
		// word |s|m|h1|h0|n1|n0|next->|h1|h0|n1|n0|w
		// 00110|1|1|0 |0 |0 |0 |      |0 |0 |0 |1 |0
		word = 5'b00110;
		selection = 1;
		mode = 1;
		#10 // Wait for clock edge
		if (hipsterians1 != 0) $display("Test 9: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 0) $display("Test 9: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 9: Value of nerdians1 is wrong");
		else if (nerdians0 != 1) $display("Test 9: Value of nerdians0 is wrong");
		else if (warning != 0) $display("Test 9: Value of warning is wrong");
		else $display("Test 9: Successful");
		
		// #10: Increment & decrement
		// word |s|m|h1|h0|n1|n0|  ->  |h1|h0|n1|n0|w
		// 00110|0| |0 |0 |0 |1 |      |1 |3 |0 |1 |0
		word = 5'b00110;
		selection = 0;
		mode = 1;
		#150 // 15 clock cycles
		mode = 0;
		#20 // 2 clock cycles
		if (hipsterians1 != 1) $display("Test 10: Value of hipsterians1 is wrong");
		else if (hipsterians0 != 3) $display("Test 10: Value of hipsterians0 is wrong");
		else if (nerdians1 != 0) $display("Test 10: Value of nerdians1 is wrong");
		else if (nerdians0 != 1) $display("Test 10: Value of nerdians0 is wrong");
		else if (warning != 0) $display("Test 10: Value of warning is wrong");
		else $display("Test 10: Successful");
		
		$finish;
	end
      
endmodule