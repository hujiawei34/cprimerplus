# Repository Guidelines

## Project Structure & Module Organization
- Chapters live under `chapter1` … `chapter11`, each with `example/`, `practice/`, and `revise/` subfolders. Each `.c` file is a standalone program with its own `main`.
- `blank/` provides minimal templates in `example/`, `practice/`, and `revise/`.
- Source files often include Chinese prompts/output. Use UTF-8 encoding.

## Build, Test, and Development Commands
- Compile a single file with GCC:
  - `gcc -Wall -Wextra -std=c11 -g path/to/file.c -o path/to/file.out && path/to/file.out`
- VS Code tasks (recommended):
  - Build active file: Run task "C/C++: gcc编译活动文件" (outputs `${fileBasenameNoExtension}.out`).
  - Debug active file: Launch "C/C++: gcc调试活动文件".
- Batch build example programs in a folder:
  - `for f in chapter5/example/*.c; do gcc -Wall -Wextra -std=c11 -g "$f" -o "${f%.c}.out"; done`

## Coding Style & Naming Conventions
- Indentation: 4 spaces, no tabs. Keep lines ≤ 100 chars.
- Braces: K&R style (`int main(void) { ... }`).
- Naming: macros UPPER_SNAKE_CASE; functions/variables lower_snake_case.
- Filenames:
  - `practice/`: keep numeric (e.g., `7.c`) to match book order.
  - `example/` and `revise/`: prefer descriptive names (e.g., `min_sec.c`).
- Compile cleanly with warnings enabled (`-Wall -Wextra -Wpedantic`).

## Testing Guidelines
- No formal test framework. Validate by compiling and running each binary.
- Include a brief comment at top with expected sample I/O if helpful.
- Keep `main` small; put logic in helper functions to ease manual testing.
- Optional: use sanitizers when available: `-fsanitize=address,undefined -fno-omit-frame-pointer`.

## Commit & Pull Request Guidelines
- Commit messages: concise and chapter-scoped. Format:
  - `chapterX(scope): summary` (e.g., `chapter5(practice): add 7.c minutes→hours`).
- PRs should include:
  - What changed and why, affected paths (e.g., `chapter5/practice/7.c`), and run instructions or sample I/O.
  - Link related issues (if any) and screenshots/terminal snippets for output.

## Security & Configuration Tips
- Prefer safe input patterns: check `scanf` return values; use `fgets` for strings; avoid `gets`.
- Avoid undefined behavior (uninitialized vars, out-of-bounds, integer overflow).
- Ensure terminal uses UTF-8 for correct Chinese text rendering.
