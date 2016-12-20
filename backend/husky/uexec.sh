# This points to a file, which should contains hostnames (one per line).
# E.g.,
#
# worker1
# worker2
# worker3
#
MACHINE_CFG=machine.cfg.20.yuying
time pssh -o /data/yuying/husky-log -t 0 -P -h ${MACHINE_CFG} -x "-t -t" "ulimit -c unlimited && cd /data/yuying/project/Husky-Vis/backend/husky && ls > /dev/null && ./$@"
