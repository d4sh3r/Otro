#!/bin/bash
IP=$1
function scan
{
for ((port=1; port<=65535; port++))
do 
echo -ne "$port\r";sleep .1s
(echo >/dev/tcp/$IP/$port) > /dev/null 2>&1 && echo "$port open"
done
}
scan
