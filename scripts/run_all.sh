#!/usr/bin/env bash
set -u

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
FAILED=0
PASSED=0
QUESTION_FILES=("$ROOT"/questions/Q*.cpp "$ROOT"/questions/coderpad_rendering/Q*.cpp "$ROOT"/questions/tesla/Q*.cpp)
ARTIFACT_ROOT="$ROOT/questions_artifacts"
mkdir -p "$ARTIFACT_ROOT" "$ARTIFACT_ROOT/coderpad_rendering" "$ARTIFACT_ROOT/tesla"

for f in "${QUESTION_FILES[@]}"; do
    [ -e "$f" ] || continue

    name=$(basename "$f" .cpp)
    number="${name:1:2}"
    dir=$(dirname "$f")
    if [[ "$dir" == *"coderpad_rendering"* ]]; then
        exe="$ARTIFACT_ROOT/coderpad_rendering/coderpad_q$number"
    elif [[ "$dir" == *"tesla"* ]]; then
        exe="$ARTIFACT_ROOT/tesla/tesla_q$number"
    else
        exe="$ARTIFACT_ROOT/q$number"
    fi

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
