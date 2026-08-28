#!/usr/bin/env bash
#
# leetcode-commit.sh
#
# Copies a solved LeetCode solution file into a dedicated repo, organized as
#   problems/<number>-<slug>/solution.<ext>
# then commits it with a clean, consistent message.
#
# USAGE:
#   ./leetcode-commit.sh <problem-number> <problem-slug> <path-to-solution-file>
#
# EXAMPLE:
#   ./leetcode-commit.sh 9 palindrome-number ~/code/scratch/palindrome.cpp
#
# SETUP (one-time):
#   1. Create a dedicated repo just for this, e.g. on GitHub: leetcode-solutions
#   2. git clone it locally
#   3. Set REPO_DIR below to point at that local clone
#   4. chmod +x leetcode-commit.sh

set -euo pipefail

# ---- CONFIG: edit this to point at your local leetcode repo clone ----
REPO_DIR="/Users/ahmadtobasei/leetcode-solutions"
# ------------------------------------------------------------------------

if [[ $# -ne 3 ]]; then
    echo "Usage: $0 <problem-number> <problem-slug> <path-to-solution-file>"
    echo "Example: $0 9 palindrome-number ~/scratch/palindrome.cpp"
    exit 1
fi

PROBLEM_NUM="$1"
PROBLEM_SLUG="$2"
SRC_FILE="$3"

if [[ ! -f "$SRC_FILE" ]]; then
    echo "Error: solution file not found: $SRC_FILE"
    exit 1
fi

if [[ ! -d "$REPO_DIR/.git" ]]; then
    echo "Error: $REPO_DIR is not a git repo. Clone your leetcode-solutions repo there first,"
    echo "or edit REPO_DIR at the top of this script."
    exit 1
fi

# Zero-pad the problem number to 4 digits (e.g. 0009) so folders sort nicely
PADDED_NUM=$(printf "%04d" "$PROBLEM_NUM")
PROBLEM_DIR="$REPO_DIR/problems/${PADDED_NUM}-${PROBLEM_SLUG}"
EXT="${SRC_FILE##*.}"
DEST_FILE="$PROBLEM_DIR/solution.${EXT}"

mkdir -p "$PROBLEM_DIR"
cp "$SRC_FILE" "$DEST_FILE"

cd "$REPO_DIR"
git add "$DEST_FILE"

# If nothing actually changed, don't create an empty commit
if git diff --cached --quiet; then
    echo "No changes to commit for problem ${PROBLEM_NUM} (${PROBLEM_SLUG})."
    exit 0
fi

git commit -m "Solve #${PROBLEM_NUM}: ${PROBLEM_SLUG}"
echo "Committed problems/${PADDED_NUM}-${PROBLEM_SLUG}/solution.${EXT}"
echo "Don't forget to 'git push' when you're ready."