***
V1 works on large files becouse it does NOT load file into memmory.

   gregor.redelonghi@cygwin-en ~/C_and_Cpp_en_testing/c_en_testing/test_files/large
   $> for FFF in *; do ../../cn019_file-info_20211117/bin/file-info_V1.exe $FFF; done
   The size of bible.txt: 4047392 bytes
   ---
   The size of E.coli: 4638690 bytes
   ---
   The size of world192.txt: 2473400 bytes
   ---

***
V2 does NOT work on large files, becouse it tries to load file contents into
stack memory location...
41		char buffer[file_size];
... it should malloc into heap memory!! //todo

   gregor.redelonghi@cygwin-en ~/C_and_Cpp_en_testing/c_en_testing/test_files/large
   $> for FFF in *; do ../../cn019_file-info_20211117/bin/file-info_V2.exe $FFF; done
   Segmentation fault (core dumped)
   Segmentation fault (core dumped)
   Segmentation fault (core dumped)

***
V3 does NOT work on large files becouse the segmentation fault happens before the test!


