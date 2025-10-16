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


## ✅ Feature 3: Static Library (Completed)

- Branch: static-build (merged into main if required)
- Library: lib/libmyutils.a
- Executable: bin/client_static
- Build: `make` (top-level) -> builds library and client_static

### Feature-3 Report Questions & Answers

Q1) Compare the Makefile from Part 2 and Part 3. Key differences?
A1) In Part 2 the Makefile compiled multiple source files and linked them directly: the final target depended on many object files (OBJ). For Part 3, Makefile includes rules to create an archive (lib/libmyutils.a) from utility object files (using `ar`), and then the final executable links against that library (using -L and -l flags). Variables added/changed include LIB_DIR, AR, RANLIB, and rules include a `lib` target (to build the archive) and a `build_static` target (to link main against libmyutils.a). This separation reduces rebuilds, provides modularity, and supports reuse of the library.

Q2) What is the purpose of the `ar` command? Why use `ranlib`?
A2) `ar` creates/updates static archives (library files, e.g., `.a`) by bundling object files into one archive. `ranlib` builds an index of the archive's contents (on some systems `ar` with `s` does this; ranlib ensures the archive's symbol table is generated so linkers can quickly find needed symbols). Historically `ranlib` was required on some systems; `ar rcs` often performs indexing automatically but running `ranlib` is portable.

Q3) When you run `nm` on client_static, are symbols like `mystrlen` present? What does that tell you about static linking?
A3) `nm` on `bin/client_static` will show `mystrlen` as a defined symbol (not undefined). That tells us that static linking copies the required object code from the static archive into the final executable, so the executable contains the actual implementations of those functions. Unlike dynamic linking (which leaves undefined symbols resolved at runtime), static linking embeds code into the binary.

