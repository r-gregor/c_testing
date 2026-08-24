Usage:
$> cat data.txt
line_1
line_2
line_3
line_4
line_5
line_6
---

$> cat data.txt | xargs echo
line_1 line_2 line_3 line_4 line_5 line_6
---

$> cat data.txt | xargs ./bin/arguments-check
[INFO] got 6 arguments:
arg 01: line_1
arg 02: line_2
arg 03: line_3
arg 04: line_4
arg 05: line_5
arg 06: line_6
---

$> ./bin/arguments-check $(cat data.txt | xargs)
[INFO] got 6 arguments:
arg 01: line_1
arg 02: line_2
arg 03: line_3
arg 04: line_4
arg 05: line_5
arg 06: line_6
---

$> cat data.txt | xargs -n3 ./bin/arguments-check
[INFO] got 3 arguments:
arg 01: line_1
arg 02: line_2
arg 03: line_3

[INFO] got 3 arguments:
arg 01: line_4
arg 02: line_5
arg 03: line_6
---

$> cat data.txt | xargs -n5 ./bin/arguments-check
[INFO] got 5 arguments:
arg 01: line_1
arg 02: line_2
arg 03: line_3
arg 04: line_4
arg 05: line_5

[INFO] got 1 arguments:
arg 01: line_6
---

$> cat data.txt |xargs -n2 ./bin/arguments-check
[INFO] got 2 arguments:
arg 01: line_1
arg 02: line_2

[INFO] got 2 arguments:
arg 01: line_3
arg 02: line_4

[INFO] got 2 arguments:
arg 01: line_5
arg 02: line_6
---

