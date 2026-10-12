#!/bin/bash
# Démo : serveur + 6 IA réparties en 2 équipes + interface graphique.
./zappy_server -p 4242 -x 15 -y 10 -n red blue -c 6 -f 60 > /tmp/server.log 2>&1 &
sleep 1
for t in red red red blue blue blue; do ./zappy_ai -p 4242 -n $t -h 127.0.0.1 > /dev/null 2>&1 & done
sleep 1
sleep infinity | ./zappy_gui -p 4242 -h 127.0.0.1
