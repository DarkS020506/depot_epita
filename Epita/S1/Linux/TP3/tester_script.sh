#!/bin/bash
if [ $# -lt 2 ]; then
    echo "usage : tester_script.sh SCRIPT TEST..."
    exit 3
fi
script="$1"
shift
if [ ! -f "$script" ] || [ ! -x "$script" ]; then
    echo "tester_script.sh : $script : pas un script executable"
    exit 2
fi
total=0
ok=0
error_test=false
for test in "$@"; do
    total=$((total + 1))
    case "$test" in
        *=*)
            arg="${test%%=*}"
            expected="${test#*=}"
            ;;
        *)
            echo "tester_script.sh : $test : test mal specifie"
            error_test=true
            continue
            ;;
    esac
    result="$("$script" "$arg" 2>/dev/null)"

    if [ "$result" = "$expected" ]; then
        echo "OK $arg => $expected"
        ok=$((ok + 1))
    else
        echo "NOK $arg => $expected, obtenu : $result"
    fi
done
if [ "$total" -gt 0 ]; then
    percent=$((ok * 100 / total))
else
    percent=0
fi

echo "$total tests, $percent% OK"
if $error_test; then
    exit 2
elif [ "$ok" -eq "$total" ]; then
    exit 0
else
    exit 1
fi
