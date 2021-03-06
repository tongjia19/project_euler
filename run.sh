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
    python)
        file_ext="py"
        language_name="Python"
        ;;
    *)
        echo -e "\"$1\" not found!"
        exit 1
esac

echo -e "Language: $language_name"
echo -e "=========================\n"

cd $1

function to_full_prod_num {
    size=${#prob_num}
    case "$size" in
        1)
            prob_num="00"${prob_num}
            ;;
        2)
            prob_num="0"${prob_num}
            ;;
        3)
            ;;
        *)
            echo "Bad problem number!"
            exit 1
    esac
}

function compile {
    printf "${prob_file}:  "
    case "$language_name" in
        C)
            gcc pe_p${prob_num}.${file_ext} -o pe_p${prob_num}.bin
            ;;
        Python)
            python pe_p${prob_num}.${file_ext}
            ;;
        *)
            echo -e "\"$$language_name\" not found!"
            exit 1
    esac
}

function execute {
    if [ "$language_name" = "C" ]; then
        ./pe_p${prob_num}.bin
    fi

    echo -e ""
    echo -e "-------------------------\n"
}

function clean {
    if [ "$language_name" = "C" ]; then
        rm *.bin
    fi
}

if [ "$2" = "all" ]; then
    for prob_file in $( ls ); do
        [[ "${prob_file}" =~ pe_p(.*).${file_ext} ]]
        prob_num=${BASH_REMATCH[1]}
        to_full_prod_num
        printf "${prob_num}: "
        compile
        execute
    done
else
    prob_num=$2
    to_full_prod_num
    prob_file=pe_p${prob_num}.${file_ext}
    compile
    execute
fi

clean

