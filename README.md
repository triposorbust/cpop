## Closest Pair of Points (in C)

Divide-and-conquer solution to Closest Pair of Points problem. Do it in a lower-level language!

### Quickstart

Program can be built using provided `Makefile` target `build`, which is also default. A symbolic link will be deposited that runs the `main` program.

```
% make && ./closest-pairs <some-filename>
...
```

Repository provides three test files.


### Makefile Targets

 - `make`: Default target, same as `make build`
 - `make build`: Builds the `closest-pairs` program and deposits symbolic link
 - `make check`: Builds and runs Check unit tests


### Directory Tree

 - `bin/`: Directory for built object files and binary.
 - `res/`: Directory for acceptance test resource files.
 - `spec/`: Unit test source files.
 - `src/`: Program source files.


### Known Issues

 - Design is inconsistent w.r.t. memory management. Should use outside-in passage.
 - Attempt at developing an "opaque" data type is a bit of a hack.


### Unit Tests

Software comes packaged with a full `Check`  unit test suite. Check is a unit testing framework for C programs. To run the unit tests, use the canonical `check` target:

```
% make check
Running suite(s): merge_sort
100%: Checks: 1, Failures: 0, Errors: 0
Running suite(s): closest_pair
100%: Checks: 2, Failures: 0, Errors: 0
```

Which automatically generates the test program. Tests should (obviously) pass.


### Authors

 - Andy Chiang
 - ...


### License

Copyright &copy; 2013 Andy Chiang.

Distributed under the MIT License.