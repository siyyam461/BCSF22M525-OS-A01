---
### ✅ Feature 1: Project Scaffolding & Version Control (Completed)

- Repository: BCSF22M525-OS-A01
- Directory structure created (src/, include/, lib/, bin/, obj/)
- REPORT.md initialized
- Configured SSH for GitHub authentication
- Initial commit pushed successfully
- Repository link: https://github.com/siyyam461/BCSF22M525-OS-A01

---

## ✅ Feature 2: Multi-file Project (Completed)

- Branch: multifile-build (merged into main)
- Files added:
  - include/mystrfunctions.h
  - include/myfilefunctions.h
  - src/mystrfunctions.c
  - src/myfilefunctions.c
  - src/main.c (test driver)
  - Makefile
- Build instructions: `make` → produces `bin/client`
- Notes: Implementations use portable C (fgets + my_strdup) to avoid non-portable GNU extensions.
- Tag planned: `v0.1.1-multifile` (see Release)


### Feature-2 Report Questions & Answers

Q1) Explain the linking rule in this part's Makefile: $(TARGET): $(OBJECTS). How does it differ from a Makefile rule that links against a library?
A1) The rule $(TARGET): $(OBJECTS) means the final executable depends directly on individual object files; the link command uses those objects to produce the executable. Linking against a library uses a static or shared archive (e.g., -lmyutils) so the linker pulls necessary symbols from that library; it decouples compilation units and can reduce rebuilds and improve encapsulation.

Q2) What is a git tag and why is it useful? Difference between lightweight and annotated tags?
A2) A git tag names a specific commit, commonly used for release points. Lightweight tags are simple pointers to commits; annotated tags store metadata (message, tagger info) and are preferred for releases.

Q3) What is the purpose of creating a "Release" on GitHub? Why attach binaries?
A3) A Release bundles a tag with release notes and downloadable assets. Attaching binaries allows graders/users to download runnable artifacts without building from source.

