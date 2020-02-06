[comment]: <> (Osman Emre Bilici - 2171353)
[commment]: <> (Ege Özbek - 2237709)

### Discovery Part
First of all, configuration scripts on the node R1 and the node R2, respectively 'configureR1.sh' and 'configureR2.sh' must be run.

After configuration, in the folder 'discoveryScripts', this order should be followed to run the scripts: 
1. script for the node s
2. script for the node d
3. script for the node r2
4. script for the node r1
5. script for the node r3

In the terminal of the nodes s, d and r2, one should wait until the server is started.

If the servers is not terminated, do not worry! Each servers have 60 seconds time to out.

Results of the cost of the links will be saved as link_costs.txt files on the node r1, r2 and r3. 
In this file, the RTT values for each link can be seen as 'clientName-targetName:'. For instance, 'r1-d:'.

### Experiment Part
First of all, configuration scripts on the node R3, S and D are in the folder 'experimentRouters'. 
For each delay value, there are different folders. If you want to run 20ms delay, you should use 20ms folder and so on.
Before the running each script, using the shell script in the below, look at the interfaces to see the delay values.
```
tc qdisc show
```
If the delay values are emulated delay which is adjusted by you, you should use this script in that node. 
This script converted netem to root which is original.
```
sudo tc qdisc del dev eth3 netem  //do delete delay instead of 'netem', write 'root'.
```
Every time when you want to change the delay value, you should use this script. 

If you get the error which is below, probably you did not run the script which is above.

> RTNETLINK answers: File exists

After configuration, in the 'experimentScripts' folder, there are scripts for each node. The order of the running the scripts should be:
1. script for the node d
2. script for the node r3
3. script for the node s

Results of the end to end delay will be saved as 'difference_times.txt' file on the node d.
