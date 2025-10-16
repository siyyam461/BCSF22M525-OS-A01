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



## ✅ Feature 3: Static Library (Completed)

- Branch: static-build (merged into main)
- Library: lib/libmyutils.a
- Executable: bin/client_static
- Build: `make` (top-level) -> builds library and client_static

### Feature-3 Verification
- `ar -t lib/libmyutils.a` lists: mystrfunctions.o, myfilefunctions.o
- `nm -C bin/client_static` shows defined symbols: mystrlen, mygrep, wordCount
- Tag: v0.2.1-static
- Release: v0.2.1-static (assets: lib/libmyutils.a, bin/client_static)


## ✅ Feature 4: Dynamic Library (Completed)

- Branch: dynamic-build (merged into main)
- Library: lib/libmyutils.so
- Executable: bin/client_dynamic
- Build: `make` (top-level) -> builds shared lib and client_dynamic

### Feature-4 Report Questions & Answers

Q1) What is Position-Independent Code (-fPIC) and why is it required?
A1) Position-Independent Code (PIC, produced by -fPIC) generates machine code that can be loaded at any memory address without modification. For shared libraries the OS can map the same library into different process address spaces at different addresses; PIC avoids absolute addresses so relocation is minimal and safe. Without PIC, shared libraries may require runtime relocation fixes and cannot be safely shared across processes as efficiently.

Q2) Explain the difference in file size between static and dynamic clients. Why?
A2) The static client embeds the implementations of all used functions (copied from static lib) into the executable, making it large. The dynamic client only contains references to external symbols and loader information; the actual code lives in the shared .so, so the executable is smaller. The .so holds the function code, enabling sharing across processes and reducing binary size.

Q3) What is LD_LIBRARY_PATH and why did we need it?
A3) `LD_LIBRARY_PATH` is an environment variable that adds directories where the dynamic loader searches for shared libraries at runtime. Because our custom `lib/libmyutils.so` is in a nonstandard location, we temporarily set `LD_LIBRARY_PATH=$(pwd)/lib` so the loader can find it. This shows the loader’s responsibility: it locates and maps shared libraries into the process address space; if they’re not in standard paths (e.g., /usr/lib), the user or system must provide the path.

