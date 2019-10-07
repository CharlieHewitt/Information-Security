#!/bin/bash
i=500
while [ $i -lt 1000 ]
do
    #pin= ./bruteforcepin $i
    # decryption command
    echo $i
    gpg -d --no-tty --pinentry-mode loopback --batch --passphrase "0$i" -o password password.enc #2> /dev/null

    if [[ "$?" == "0" ]]; then
    echo $i
    break;
    fi
    let i++
done
