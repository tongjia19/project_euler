#!/bin/bash

# Compile and run a particular problem
# Tong Jia
# 2014

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 [PROGRAMMING LANGUAGE] [PROBLEM #]";
    exit 1
fi

case "$1" in
    c)
        file_ext="c"
        language_name="C"
        ;;

    *)
        echo -e "\"$1\" not found!"
        exit 1
esac

echo -e "Language: $language_name"
echo -e "=========================\n"

cd $1

function compile {
    printf "${prob_file}:  "
    printf "compiling.. "
    case "$language_name" in
        C)
            gcc pe_p${prob_num}.${file_ext} -o pe_p${prob_num}.bin
            ;;

        *)
            echo -e "\"$$language_name\" not found!"
            exit 1
    esac
}

function execute {
    printf "executing:  "
    ./pe_p${prob_num}.bin

    echo -e ""
    echo -e "-------------------------\n"
}

function clean {
    rm *.bin
}

if [ "$2" = "all" ]; then
    for prob_file in $( ls ); do
        [[ "${prob_file}" =~ pe_p(.*).${file_ext} ]]
        prob_num=${BASH_REMATCH[1]}
        printf "${prob_num}: "
        compile
        execute
    done
else
    prob_num=$2
    prob_file=pe_p${prob_num}.${file_ext}
    compile
    execute
fi

clean

