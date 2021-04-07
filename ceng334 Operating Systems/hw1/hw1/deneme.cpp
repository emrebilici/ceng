#include <iostream>
#include <unistd.h> 
#include <stdio.h>
#include <string>
#include <vector>
#include <sys/types.h>
#include <typeinfo>
#include <array>
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/socket.h>
#include "lib/logging.h"
#include "lib/message.h"
#include <list>

#define PIPE(fd) socketpair(AF_UNIX, SOCK_STREAM, PF_UNIX, fd)


void readInput(std::vector<std::vector<std::string>> &bidders, int &startBid, int &minIncr){
    int a, b, c;
    std::cin >> a >> b >> c;
    startBid = a;
    minIncr = b;
    std::vector<std::string> lines;
        //burasi bidderlari string olarak aliyor.
    for (int i = 0; i < c; i++ )
    {
        std::string path;
        int argno ;
        std::vector<std::string> args;
        std::cin >> path >> argno;

        args.push_back(path);

        for (int j = 0; j < argno; j++){
            std::string ar;
            std:: cin >> ar;
            args.push_back(ar);
        }

        bidders.push_back(args);

    }
}


int max(int x, int y) 
{ 
    if (x > y) 
        return x; 
    else
        return y; 
} 

int main(){
    std::string line;

    // bidders tum bidderlari alıyor 2d vector.
    // bidders[i] kacinci bidder oldugu. bidders[i][j] kacinci arguman oldugu ismi falan.
    // bidders[2][0] => "./different_bidder" mesela.
    // bidders[2][1] => 2 arguman sayisi yani.
    // bidders[2][2] => ilk arguman.
    std::vector<std::vector<std::string>> bidders;
    int bidderCount = 0;
    int startingBid = 0;
    int minIncrement = 0;


    readInput(bidders, startingBid, minIncrement);

    std::vector<std::vector<char*>> bidders2;
    for(int j = 0; j < bidders.size(); j++) {



        std::vector<char*> bidderarg;
        for(int i = 0; i < bidders[j].size(); i++) {
            //std::cout << bidders[j][i] << std::endl;
            //std::string deneme[bidders[i].size()];
            //l.push_back(const_cast<char*>(k.c_str()));
            
            bidderarg.push_back((char*)bidders[j][i].c_str());

        }

        bidders2.push_back(bidderarg);

    }

    // her bidder'in 2 tane fd sini tutan vector olmali.
    // bidderFDs.
    // 
    //std::vector<std::array<int,2>> bidderFDs;
    //std::array <int,2> arr;

    bidderCount = bidders.size();

    int bidderFDs[bidderCount][2];

    // pipe
    for(int i = 0; i < bidderCount; i++)
    {
        PIPE(bidderFDs[i]);
    }

    pid_t bidderPIDs[bidderCount];
    //fork and dup2 and exec
    for(int i = 0; i < bidderCount; i++)
    {
        pid_t pid = fork();
        bidderPIDs[i] = pid;
        if(pid < 0) printf("FORK ERROR\n");

        else if(pid == 0) //child //bidder
        {
            dup2(bidderFDs[i][1], 0);   //STDIN_FILENO  //bidder side
            dup2(bidderFDs[i][1], 1);   //STDOUT_FILENO //bidder side

            // not necessary
            for(int j = 0; j  < bidderCount; j++){
                close(bidderFDs[j][0]);
                close(bidderFDs[j][1]);
            }

            char* deneme[bidders2[i].size()];
            int k = 0;
            for(; k <bidders2[i].size(); k++){
                deneme[k] = bidders2[i][k];
            }
            deneme[k] = NULL;

            //char* denemeee[] = {NULL};
            execvp(bidders2[i][0], deneme);

        }
        else{
            close(bidderFDs[i][1]);
        }
    }


    int currentBid = 0;

    fd_set fdset;

    int activeBidders[bidderCount];
    //bidder
    for (int i = 0; i < bidderCount; i++){
        activeBidders[i] = 1;
    }


    int bidderID;
    int delay[bidderCount];
    bidderID = 0;

    int maxfd=0;

    for(int i = 0; i <bidderCount; i++){
        maxfd = max(bidderFDs[i][0], maxfd);
    }

    maxfd++;


    while(bidderCount){
        FD_ZERO(&fdset);
        for (int i = 0; i < bidderCount; i++){
            if(activeBidders[i]){
                FD_SET(bidderFDs[i][0], &fdset);
            }
            
            select(maxfd, &fdset, NULL, NULL, NULL );
            if(FD_ISSET(bidderFDs[i][0], &fdset)){
                cm clientMessage;
                if(read(bidderFDs[i][0], &clientMessage, sizeof(clientMessage))==-1)    //server side
                {
                    fprintf(stderr, "READ ERROR %d \n", i);
                    fflush(stderr);
                }

                
                delay[i] = clientMessage.params.delay;


                
                if(clientMessage.message_id == CLIENT_CONNECT){
                    sm serverMessage;
                    smp serverMessagePar;
                    cei conEstInfo;

                    conEstInfo.client_id = bidderID;
                    conEstInfo.current_bid = currentBid;
                    conEstInfo.starting_bid = startingBid;
                    conEstInfo.minimum_increment = minIncrement;

                    serverMessage.message_id = SERVER_CONNECTION_ESTABLISHED;
                    serverMessage.params.start_info = conEstInfo;
                    serverMessagePar = serverMessage.params;



                    sleep(delay[i]/1000);

                    write(bidderFDs[i][0], &serverMessage, sizeof(serverMessage));

                    ii inputData;
                    inputData.type = CLIENT_CONNECT;
                    inputData.pid = bidderPIDs[i];
                    inputData.info = clientMessage.params;
                    print_input(&inputData, bidderID);


                    oi outputData;
                    outputData.type = SERVER_CONNECTION_ESTABLISHED;
                    outputData.pid = bidderPIDs[i];
                    outputData.info = serverMessagePar;
                    print_output(&outputData, bidderID);

                }

                else if (clientMessage.message_id == CLIENT_BID){
                    sm serverMessage;
                    smp serverMessagePar;
                    if (startingBid > clientMessage.params.bid){
                        serverMessagePar.result_info.result = BID_LOWER_THAN_STARTING_BID;
                    }
                    else if (currentBid > clientMessage.params.bid ){
                        serverMessagePar.result_info.result = BID_LOWER_THAN_CURRENT;
                    }
                    else if ( minIncrement > clientMessage.params.bid - currentBid){
                        serverMessagePar.result_info.result = BID_INCREMENT_LOWER_THAN_MINIMUM;
                    }
                    else{
                        serverMessagePar.result_info.result = BID_ACCEPTED;
                        if (currentBid < clientMessage.params.bid){
                            currentBid = clientMessage.params.bid;
                        }
                        else{
                            
                        }
                        serverMessagePar.result_info.current_bid = currentBid;
                        write(bidderFDs[i][0], &serverMessage, sizeof(serverMessage));

                        ii inputData;
                        inputData.type = CLIENT_BID;
                        inputData.pid = bidderPIDs[i];
                        inputData.info = clientMessage.params;
                        print_input(&inputData, bidderID);


                        oi outputData;
                        outputData.type = SERVER_BID_RESULT;
                        outputData.pid = bidderPIDs[i];
                        outputData.info = serverMessagePar;
                        print_output(&outputData, bidderID);

                    }







                    

                }
                else if(clientMessage.message_id==CLIENT_FINISHED){
                    activeBidders[i]--;
                    bidderCount--;
                }   


            }
            bidderID++; 
               
        }
    }




}