#!/usr/bin/env bash
set -u
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
FAILED=0
PASSED=0

for f in "$ROOT"/questions/Q*.cpp; do
    name=$(basename "$f" .cpp)
    number="${name:1:2}"
    exe="$ROOT/questions/q$number"
    echo "==== $name ===="
    if g++ -std=c++17 -I"$ROOT/include" "$f" -o "$exe"; then
        if "$exe"; then
            PASSED=$((PASSED+1))
        else
            FAILED=$((FAILED+1))
        fi
    else
        FAILED=$((FAILED+1))
    fi
    echo
done

echo "Passed: $PASSED"
echo "Failed: $FAILED"
exit $FAILED
