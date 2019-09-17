#!/bin/bash

# Only works for scripts/virus folders, not test (hence test.sh is disabled)
# if script is called from virus (../src)
if [ $(find . -type d -name src | grep src) ]
then
    cd src
fi

exit= false

while [ true ]
do
    echo -e "Select the test you are wanting to run: "
    echo -e "a. addNumbers"
    echo -e "b. helloworld"
    echo -e "c. multiplyNumbers"
    echo -e "d. textFile"
    echo -e "e. tinderprofile"
    echo -e "f. while"
    echo -e "g. setupTest"
    echo -e "h. cleanupTest"
    # echo -e "i. test.sh"
    echo -e "q. quit"

    read input

    echo -e "\n\n"

    case $input in

        a)
            ../scripts/addNumbers.sh
            ;;

        b)
            ../scripts/helloworld.sh
            ;;

        c)
            ../scripts/multiplyNumbers.sh
            ;;

        d)
            ../scripts/textFile.sh
            ;;

        e)
            ../scripts/tinderprofile.sh
            ;;

        f)
            ../scripts/while.sh
            ;;

        g)
            ./setupTest.sh
            ;;

        # i)
        #     ./test.sh
        #     ;;

        q)
            break
            ;;

        b)
            ../scripts/helloworld.sh
            ;;

        *)
            echo "invalid input"
            ;;
        esac
done

