#!/usr/bin/env bash
set -euo pipefail

workspace_folder="$1"
file_path="$2"

artifact_dir="$workspace_folder/questions_artifacts/vscode"
output_path="$artifact_dir/active_question"

mkdir -p "$artifact_dir"
g++ -std=c++17 -g -I"$workspace_folder/include" "$file_path" -o "$output_path"

echo "Built $output_path"
