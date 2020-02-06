r1=$(getent ahosts "r1" | cut -d " " -f 1 | uniq)
r2=$(getent ahosts "r2" | cut -d " " -f 1 | uniq)

r1_adapter=$(ip route get $r1 | grep -Po '(?<=(dev )).*(?= src| proto)')
r2_adapter=$(ip route get $r2 | grep -Po '(?<=(dev )).*(?= src| proto)')

sudo tc qdisc change dev $r1_adapter root netem loss 5% delay 3ms
sudo tc qdisc change dev $r2_adapter root netem loss 5% delay 3ms