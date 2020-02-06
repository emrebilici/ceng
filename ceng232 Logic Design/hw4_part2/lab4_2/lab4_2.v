`timescale 1ns / 1ps
module lab4_2(
        input[3:0] userID,
        input CLK,
        input team,
        input [1:0] mode,
        output reg  [7:0] numPlyLP,
        output reg  [7:0] numPlyCF,
        output reg  teamWng,
        output reg capWngLP,
        output reg capWngCF,
        output reg findRes,
        output reg [3:0] listOut,
        output reg  listMode
    );

reg [3:0] MemLP [0:4] ;
reg [3:0] MemCF [0:4] ;
integer i,espot,exist ;
reg [2:0] clp ;
reg [2:0] ccf ;
initial begin
        for(i = 0; i < 5; i = i + 1) begin
                MemLP[i] <= 4'b0000 ;
                MemCF[i] <= 4'b0000 ;
        end
        clp <= 3'b000 ;
        ccf <= 3'b000 ;
        numPlyLP <= 0 ;
        numPlyCF <= 0 ;
        listMode <= 0 ;
        capWngLP <= 1 ;
        capWngCF <= 1 ;
        teamWng <= 0 ;
        findRes <= 0 ;
end

always@(posedge CLK) begin
        if(mode == 2'b00) begin // Logout Mode
                clp <= 3'b000 ;
                ccf <= 3'b000 ;
                teamWng <= 0 ;
                findRes <= 0 ;
                listMode <= 0 ;
                if(team == 1) begin
                        for(i = 0; i < 5; i = i + 1) begin
                                if(MemCF[i] == userID) exist = i ;
                        end
                        MemCF[exist] <= 4'b0000 ;
                        exist = 0 ;
                        numPlyCF <= numPlyCF - 1 ;
                        capWngCF <=(numPlyCF == 8'b00000001) ;
                end

                if(team == 0) begin
                        for(i = 0; i < 5; i = i + 1) begin
                                if(MemLP[i] == userID) exist = i ;
                        end
                        MemLP[exist] <= 4'b0000 ;
                        exist = 0 ;
                        numPlyLP <= numPlyLP - 1 ;
                        capWngLP <= (numPlyLP == 8'b00000001) ;
                end
        end // end of Logout Mode

        if(mode == 2'b01) begin // Login Mode
                clp <= 3'b000 ;
                ccf <= 3'b000 ;
                findRes <= 0 ;
                listMode <= 0 ;
                if(userID[3] != team) teamWng <= 1 ;
                else if(team == 1) begin
                        if(numPlyCF == 5) teamWng <= 1 ;
                        else begin
                                teamWng <= 0 ;
                                for(i = 4; i>(-1); i = i - 1) begin
                                        if(userID == MemCF[i]) exist = 1 ;
                                        if(MemCF[i]==4'b0000) espot = i ; //[i] ekledim
                                end
                                if(~exist) begin
                                        MemCF[espot] <= userID ;
                                        numPlyCF <= numPlyCF + 1 ;
                                        capWngCF <= (numPlyCF == 8'b00000100) ;
                                end
                                exist = 0 ;
                        end

                end

                else if(team == 0) begin
                        if(numPlyLP == 5) teamWng <= 1 ;
                        else begin
                                teamWng <= 0 ;
                                for(i = 4; i > (-1); i = i - 1) begin
                                        if(userID == MemLP[i]) exist = 1 ;
                                        if(MemLP[i] == 4'b0000) espot = i ; //ayni sekilde
                                end
                                if(~exist) begin
                                        MemLP[espot] <= userID ;
                                        numPlyLP <= numPlyLP + 1 ;
                                        capWngLP <= (numPlyLP == 8'b00000100) ;
                                end
                                exist = 0 ;
                        end
                end

        end // end of Login Mode

        if (mode == 2'b10) begin         //Find Mode
                teamWng <= 0 ;
                clp <= 3'b000 ;
                ccf <= 3'b000 ;
                listMode <= 0 ;
                if(team) begin
                        for(i = 0; i < 5 ; i = i + 1) begin
                                if(userID == MemCF[i]) findRes <=1 ;
                                else findRes <= 0 ;
                        end
                end

                else begin
                        for(i = 0; i < 5 ; i = i + 1) begin
                                if(userID == MemLP[i])  findRes <= 1 ;
                                else findRes <= 0 ;
                        end
                end

        end // end of Find Mode

        if ( mode == 2'b11 ) begin         // List Mode
                teamWng <= 0 ;
                listMode <= 1;
                findRes <= 0 ;
                if( team )  begin
                        clp <= 3'b000 ;
                        listOut <= MemCF[ccf];
                        if(ccf == 3'b100) ccf <= 3'b000 ;
                        else ccf <= ccf + 1 ;
                end

                else  begin
                        ccf <= 3'b000 ;
                        listOut <= MemLP[clp];
                        if(clp == 3'b100) clp <= 3'b000 ;
                        else clp <= clp + 1 ;
                end
        end // end of List Mode


end // end

endmodule
