#!/bin/bash

arch=$(uname -msr)
os=$(lsb_release -d | cut -f2)

physical_cpus=$(lscpu | grep "^CPU(s):" | awk '{print $2}')
virtual_cpus=$(lscpu | grep "^CPU(s):" | awk '{print $2}')
	
ram_usage=$(free -h | awk '/Mem:/ {printf "%s/%s (%.0f%%)\n", $3, $2, $3/$2 * 100}')
disk_usage=$(df -h --output=used,size,pcent / | tail -1 | awk '{print $1 "/" $2 " (" $3 ")"}')
cpu_usage=$(mpstat 1 1 | awk '/^Average:/ {usage=100-$12} END {printf "%.2f%%\n", usage}')

last_reboot=$(who -b | awk '{print $3, $4}')

lvm_active=$(grep -q "mapper" /etc/fstab && echo "Yes" || echo "No")

active_connections=$(ss -t | tail -n +2 | wc -l)
num_users=$(who | wc -l)

ipv4=$(ip addr show | grep "inet " | grep -v "127.0.0.1" | awk '{print $2}' | cut -d"/" -f1)
mac=$(ip link show | grep "link/ether" | awk '{print $2}')

sudo_commands=$(journalctl -q  _COMM=sudo | wc -l)
nonroot_sudo_commands=$(cat /var/log/sudo/sudo.log | wc -l); nonroot_sudo_commands=$((nonroot_sudo_commands / 2))

wall <<EOF
******************************
** Server Monitoring Report **
******************************
Architecture:       $arch
Operating System:   $os
Physical CPUs:      $physical_cpus
Virtual CPUs:       $virtual_cpus
RAM:                $ram_usage
Disk:               $disk_usage
CPU Utilization:    $cpu_usage
Last Reboot:        $last_reboot
LVM Active:         $lvm_active
Active Connections: $active_connections
Number of Users:    $num_users
IPv4 Address:       $ipv4
MAC Address:        $mac
Sudo Commands:      $sudo_commands
Non-Root Sudo Comm: $nonroot_sudo_commands
EOF
