slib (silly lib)
================

This project is all about poking SoCs without a vendor SDK. There is an
series of articles related to this repo at ( https://lowerstrata.net ) which
refer to specific tags within the repo history.

NOTE: The code is horrific! It certainly does not demonstrate best conventions.
      The humble objective is to progressively make it better by introducing
      new concepts.

Current execution environment is FRDM-K64F, and you'll probably want to run
your make on an UNIXy system with gcc/binutils suitable for bare metal ARM
Cortex work installed.

Changes
-------

2017-03-08: Pinmaps added, Pinmux and GPIO APIs added (for second article).

2017-02-25: First article released and code works, but K64 does not run.