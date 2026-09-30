# Codex Notes

## Project

This repository is a competitive programming archive. It contains solutions and notes grouped by platform or contest, including Advent of Code, Codeforces, CSES, ICPC, and LeetCode.

## Working in this repository

- Keep solutions in the directory that matches their platform or contest, and follow the naming and language conventions already used there.
- Prefer focused changes. Do not reformat or rewrite unrelated archived solutions.
- Preserve problem-specific input/output behavior and any useful notes or comments in existing solutions.
- Before adding a new solution, inspect nearby files for the expected structure and compiler conventions.
- Solutions are 3-space tab (refactor accordingly)

## Build and cleanup

- The root `Makefile` defines `make clean`.
- **Review before running `make clean`:** it deletes `.out` and `.in` files and files without extensions throughout the repository (excluding `.git`). Such files may be intentional problem inputs or source files.
- There is no repository-wide test command. Run a solution's relevant compile or sample checks only when requested or needed for the change.
