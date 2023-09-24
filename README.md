# Requirements
conan, boost, libmagic, gtest

# Todo
binary input handling
setup clang-tidy and clang-format
setup cmake tests
test other linkers https://github.com/rui314/mold
distcc? open question
unified result printer

# Architecture
## TarFile example
TarFile <-> FileProcessor<TarFileBase>
                ^- base class
TarFileBase <-> FileBase <- base class

FileProcessor - set of functions to operate over filetype
FileBase - wrapper over file

FileBase is necessary to provide error type before creating proper File class
It goes like that:
Inhereted FileBase defines error result type
This inhereted FileBase is consumed as template type to AnalyseResult and ProcessError to create handlers for results and errors