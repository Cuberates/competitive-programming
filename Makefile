# Resolve this Makefile's directory before any include directives.
# Older GNU Make may prefix MAKEFILE_LIST with a space.
CLEAN_ROOT := $(shell makefile_path="$(MAKEFILE_LIST)"; dirname "$${makefile_path\# }")

# Prune every hidden entry, including .git, .github, .cph, and .vscode,
# at every depth. Keep source files, headers, notes, PDFs, and other assets
# by selecting build/test artifacts instead of all non-.cpp files.
CLEAN_FILES = find . -mindepth 1 -name '.*' -prune -o -type f \
	\( -name '*.bin*' -o -name '*.out' -o -name '*.in' \
	   -o -name '*.o' -o -name '*.obj' -o -name '*.exe' \) \
	! -name '*.cpp' ! -name '*.h' ! -name '*.hpp' \
	! -name '*.typ' ! -name '*.pdf' ! -name '*.md' \
	! -name '*.png' ! -name '*.jpg' ! -name '*.jpeg'

.PHONY: clean clean-preview

clean:
	@cd "$(CLEAN_ROOT)" && $(CLEAN_FILES) -print -exec rm -f -- {} +

clean-preview:
	@cd "$(CLEAN_ROOT)" && $(CLEAN_FILES) -print
