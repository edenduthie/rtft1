RTFT1
=====

Research work into real-time fault-tolerant peer-to-peer systems.

This software contains code derived from ACE(tm), which is copyrighted
by Douglas C. Schmidt and his research group at Washington University,
University of California, Irvine, and Vanderbilt University, Copyright
(c) 1993-2009, all rights reserved.

Operating system abstraction provided by the ACE framework, which is
open-source software copyrighted by Douglas C. Schmidt and his
research group at Washington University, University of California,
Irvine, and Vanderbilt University. The original software is available
from:
http://www.cs.wustl.edu/~schmidt/ACE.html

Configuration support is provided by the libconfig++, which is
open-source software, written and copyrighted by Mark Lindner. The
original software is available from:
http://www.hyperrealm.com/libconfig/

Unit tests support is provided by libunit++ which is open-source
software, written and copyrighted by Claus Draeb and David Hallas. The
original software is available from:
http://sourceforge.net/projects/unitpp/

Compiling:
==========

* $ git clone https://github.com/rolandomar/stheno.git
* $ cd stheno
* $ mkdir build && cd build
* $ cmake .. && make (or make -j#of_processors (e.g., make -j4))

Generating documentation:
=========================

The default configuration generates both latex and html documents.
* $ cd stheno
* $ doxygen doxygen.conf

[![githalytics.com alpha](https://cruel-carlota.pagodabox.com/602d4c5d57783f779f0dab6a9540870f "githalytics.com")](http://githalytics.com/rolandomar/stheno)
