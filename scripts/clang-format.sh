#!/usr/bin/env bash

DO_ALL=0
CHECK_MODE=0
while [[ $# -gt 0 ]]
do
    ARG="$1"

    case "${ARG}" in
        -a|--all)
            DO_ALL=1
            echo "Will format all files (not just modified)"
            shift
        ;;
        -c|--check)
            CHECK_MODE=1
            shift
        ;;
        *)
            echo "Unknown argument ${ARG}:"
            echo "-a|--all                      Format all files (not just modified)"
            echo "-c|--check                    Check modified files; fail if not formatted"
            exit 1
        ;;
    esac
done

CLANG_FORMAT=`which clang-format`
if [[ ! -x "${CLANG_FORMAT}" ]]
then
    echo "${CLANG_FORMAT} does not exist;"
    exit 2
fi

cd "$( dirname "${BASH_SOURCE[0]}" )/.."

if [[ ${CHECK_MODE} == 1 ]]
then
    for file in $( git status --porcelain *.h *.cc *.c *.mm *.cpp | awk 'match($1, "A|M") { print $2 }' )
    do
        ${CLANG_FORMAT} -output-replacements-xml "${file}" | grep -c "<replacement " >/dev/null
        if [[ $? != 1 ]]
        then
            echo "Detected modified files (e.g. ${file}) which are not clang-formatted. Please run ./scripts/clang-format.sh, and re-stage your commit as needed."
            echo "Optionally, you can configure the build to run clang-format automatically, by adding '-DAUTO_CLANG_FORMAT=ON' when running cmake."
            exit 3
        fi
    done
elif [[ ${DO_ALL} == 1 ]]
then
    find . \( -iname \*.cc -or -iname \*.c -or -iname \*.mm -or -iname \*.h -or -iname \*.cpp \) -exec ${CLANG_FORMAT} -i {} \;
else
    for file in $( git status --porcelain *.h *.c *.cc *.mm *.cpp | awk 'match($1, "A|M") { print $2 }' )
    do
        ${CLANG_FORMAT} -i "${file}"
    done
fi