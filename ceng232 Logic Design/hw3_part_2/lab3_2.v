
`timescale 1ns / 1ps
module lab3_2(
                input[4:0] word,
                input CLK,
                input selection,
                input mode,
                output reg [7:0] hipsterians1,
                output reg [7:0] hipsterians0,
                output reg [7:0] nerdians1,
                output reg [7:0] nerdians0,
                output reg warning
    );

    integer i ;
    integer language_identifier ;

    initial begin
            hipsterians0=0;
            nerdians0=0;
            hipsterians1=0;
            nerdians1=0;
            warning=0;
            language_identifier = 0;
    end

    always@(posedge CLK) begin
	   assign language_identifier = 0 ;
      if(selection == 0) begin
           for(i=0; i<4; i=i+1) begin
              if(word[i] == 0 )
						if(word[i+1] == 0)
							assign language_identifier = 1;
           end

        if(language_identifier) begin
				 warning <= 0;
             if(mode) begin
				 	if(hipsterians1 == 2) begin
					hipsterians1 <= 0;
					hipsterians0 <= 0;
					end
					else begin
					hipsterians0 <= (hipsterians0 + 1) ;
					
					if(hipsterians0[0] & hipsterians0[3] ) begin
						hipsterians0 <= 0 ;
						hipsterians1 <= (hipsterians1 + 1) ;
					end
				 end
				 end
				else begin 
					if(hipsterians0 | hipsterians1)
						if(hipsterians0 == 0) begin
							hipsterians1 <= (hipsterians1 - 1) ;
							hipsterians0 <= 8'b00001001 ;
						end
					   else 
							hipsterians0 <= (hipsterians0 - 1) ;
				end
			end
		  else warning <= 1 ;
      end

       

    if(selection == 1) begin
          for(i=0; i<4; i=i+1) begin
              if(word[i] == 1)
						if(word[i+1] == 1)
							assign language_identifier = 1;
						
          end

      if(language_identifier) begin
			 warning <= 0;
          if(mode) begin
				if(nerdians1 == 2) begin
					nerdians1 <= 0;
					nerdians0 <= 0;
				end
				else begin
					nerdians0 <= (nerdians0 + 1) ;
					if(nerdians0[0] & nerdians0[3] ) begin
						nerdians0 <= 0 ;
						nerdians1 <= (nerdians1 + 1) ;
					end	
					end
			end		
         else begin 
				if(nerdians0 | nerdians1)
					if(nerdians0 == 0) begin
						nerdians1 <= (nerdians1 - 1) ;
						nerdians0 <= 8'b00001001 ;
					end
					
					else 
						nerdians0 <= (nerdians0 - 1) ;
			end			
       end
       
      else warning <= 1 ;
		end
    end

endmodule


