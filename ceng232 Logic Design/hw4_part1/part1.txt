`timescale 1ns / 1ps
module FUNCROM (input [3:0] romAddress, output reg[4:0] romData);

/*Write your code here*/
always@(*)
case(romAddress)
	
	4'b0000 : romData=5'b00000;
	4'b0001 : romData=5'b00010;
	4'b0010 : romData=5'b00100;
	4'b0011 : romData=5'b00111;
	4'b0100 : romData=5'b01010;
	4'b0101 : romData=5'b01011;
	4'b0110 : romData=5'b01101;
	4'b0111 : romData=5'b01110;
	4'b1000 : romData=5'b10001;
	4'b1001 : romData=5'b10010;
	4'b1010 : romData=5'b10100;
	4'b1011 : romData=5'b10111;
	4'b1100 : romData=5'b11001;
	4'b1101 : romData=5'b11010;
	4'b1110 : romData=5'b11110;
	4'b1111 : romData=5'b11111;

	
endcase

endmodule
																						
module FUNCRAM (input mode,input [3:0] ramAddress, input [4:0] dataIn,input op, input [1:0] arg,  input CLK, output reg [8:0] dataOut);
/*Write your code here*/

	integer j;
	initial begin
	
		dataOut=9'b000000000;
		
	end	
	integer k,i;
	reg [4:0] c;
	reg p[15:0];    //output icin
	FUNCROM fo(ramAddress,dataIn);
always@(posedge CLK) begin
	case(arg) 
		2'b00 : assign k=2;
		2'b01 : assign k=1;
		2'b10 : assign k=-1;
		2'b11 : assign k=-2;
	endcase

	if (mode)    	 // write
	begin
	for(i=0;i<5;i=i+1) begin   //coefficientleri 1 ve -1 e ceviriyo
		if(dataIn[i]==0) c[i]<=1;
		if(dataIn[i]==1) c[i]<=-1;
	end
	//	for(j=0;j<16;j=j+1)
	//	begin
			if(op)    //mod 7
			begin
				if( (k*k*k*k*c[4] + c[3]*k*k*k + c[2]*k*k + c[1]*k+ c[0] ) < 0 )
				begin
				p[ramAddress]<= (7+(k*k*k*k*c[4] + c[3]*k*k*k + c[2]*k*k + c[1]*k+ c[0] ))%7 ;
				end
				else begin
				p[ramAddress]<= (k*k*k*k*c[4] + c[3]*k*k*k + c[2]*k*k + c[1]*k+ c[0] )%7;
				
				end
			end
			
			else      //derivative
			begin 
			p[ramAddress]<= 4*c[4]*k*k*k + 3*c[3]*k*k + 2*c[2]*k + c[1] ;
			end
	//	end
		
	end

	else    			 //read
	begin
	dataOut<=p[ramAddress];
	end

end
endmodule


module FUNCMEMORY(input mode, input [6:0] memInput, input CLK, output wire [8:0] result);
	/*Don't edit this module*/
	wire [4:0]  romData;

	FUNCROM RO(memInput[6:3], romData);
	FUNCRAM RA(mode, memInput[6:3], romData, memInput[2],memInput[1:0], CLK, result);

endmodule
