`timescale 1ns / 1ps

module Elevator(input CLK,
					input [1:0] mode,
					input [3:0] request,
					output reg[3:0] currentFloor1,
					output reg[3:0] currentFloor2,
					output reg doorOpen1, 
					output reg doorOpen2, 
					output reg [3:0] listingLeds,
					output reg listBusy,
					output reg state);

//Write your code below

initial begin
	currentFloor1[3:0] = 1;
	currentFloor2[3:0] = 1;
	doorOpen1=1;
	doorOpen2=1;
	listingLeds=4'b0000;
	listBusy = 0;
	state = 0;

end

endmodule