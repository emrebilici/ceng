[comment]: <> (Ege Özbek - 2237709)
[comment]: <> (Osman Emre Bilici - 2171353)

### First Experiment
First of all, configuration scripts on the node S, R3 and D, respectively 'configureS.sh', 'configureR3.sh' and 'configureD.sh' must be run. These scripts are in the directory experiment1/experimentRouters. These configurations are to add given losses for experiments. 

First row of the configuration scripts are for static routing.

Also, if you get the following errors:

> RTNETLINK answers: File exists

> RTNETLINK answers :No such file or directory

Then you should make the following change the first row of the configuration scripts:

```
sudo ip route add [IP address] via [IP address of gateway]
```

change with the below

```
sudo ip route change [IP address] via [IP address of gateway]
```
Before the running, you make sure that there is a 'input.txt' file in the same directory as node s's main.py .

After configuration, in the folder 'experiment1', this order should be followed to run the scripts: 
1. script for the node d
2. script for the node s

For each experiment, which are %5, %15, %38 , use the scripts in the proper folder. These scripts are in the experiment1/experimentRouters. 

In the terminal of the nodes d, one should wait until the server is started.

If you want to check transferring the file is done correctly, then you should 'md5sum' command. 

The input file, which is used for transferring, its name will be 'input.txt' and it will be on the node S. 

In the node D, output file's name will be 'receivedFile.txt'. One can check the correctness of the file with using the following commands:

In the node S:
```
md5sum input.txt
```

In the node D:

```
md5sum receivedFile.txt
```

If the result is same then the file is exactly same. Also, total transfer time can be seen on terminal in the node D.

### Second Experiment

Scripts for the second experiment can be found in the experiment2 folder. This implementation also uses static routing, but we have also implemented an alternative method which doesn't uses routing, which is  down below.

To set up configurations according to your loss value , just like in experiment-1 run the scripts in experiment2/experimentRouters . 

The running setup for nodes should be that you first make sure that node D runs, then run S to start file transfer.


#### Alternative Method
Due to the fact that we couldn't come up with a static routing based solution at first, we have implemented a repeater based solution. If you do not want to use static routing , and opt out for an application level routing, you can see the other configurations in the folder experiment2/alternative/alternativeRouter5. This is given for the just %5 loss but other losses can be set easily as well.
 
If you apply these configurations, you should run the scripts for the nodes D, R1 and R2. After running these scripts, run the node S.

## IP Tables

You can see the first row of the our configuration scripts. These scripts also is written by considering the IP table. 

In below, you will see the IP tables.

For the node D,

| Destination   | Gateway       | Name of the destination  |
| ------------- |:-------------:| -----:|
| 10.10.2.0     | r2-link-4      | S   |
| 10.10.1.0     | r1-link-3      | S   |
| 10.10.3.0     | r3-link-6      | S   |


For the node S,

| Destination   | Gateway       | Name of the destination  |
| ------------- |:-------------:| -----:|
| 10.10.4.0     | r1-link-0      | D   |
| 10.10.5.0     | r2-link-1      | D   |
| 10.10.7.0     | r3-link-2      | D   |
