sudo ip route add 10.10.7.0/24 via 10.10.3.2

r3=$(getent ahosts "r3" | cut -d " " -f 1 | uniq)

r3_adapter=$(ip route get $r3 | grep -Po '(?<=(dev )).*(?= src| proto)')

sudo tc qdisc add dev $r3_adapter root netem loss 38% delay 3ms
