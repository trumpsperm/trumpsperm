<p align="center">
  <a href="https://github.com/trumpsperm/trumpsperm/releases">
    <img src="https://img.shields.io/github/downloads/Bitcoin-II/Trumpsperm-Core/total?style=for-the-badge" alt="Downloads">
  </a>
  <a href="https://trumpsperm.cafe">
    <img src="https://img.shields.io/badge/Website-Online-brightgreen?logo=google-chrome&style=for-the-badge" alt="Website">
  </a>
</p>



Trumpsperm Core integration/staging tree
=====================================

https://trumpsperm.cafe

For an immediately usable, binary version of the Trumpsperm Core software, see
https://github.com/trumpsperm/trumpsperm/releases/

What is Trumpsperm Core?
---------------------

Trumpsperm is a nearly 1:1 re-launch of the Bitcoin protocol. 

Trumpsperm Core connects to the Trumpsperm peer-to-peer network to download and fully
validate blocks and transactions. It also includes a wallet and graphical user
interface, which can be optionally built.

Further information about Trumpsperm Core is available in the [doc folder](/doc).

License
-------

Trumpsperm Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `main` branch is regularly built (see `doc/build-*.md` for instructions) and tested, but it is not guaranteed to be
completely stable. [Tags](https://github.com/trumpsperm/trumpsperm/tags) are created
regularly from release branches to indicate new official, stable release versions of Trumpsperm Core.

The https://github.com/trumpsperm/trumpsperm/gui repository is used exclusively for the
development of the GUI. Its master branch is identical in all monotree
repositories. Release branches and tags do not exist, so please do not fork
that repository unless it is for development reasons.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled during the generation of the build system) with: `ctest`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python.
These tests can be run (if the [test dependencies](/test) are installed) with: `build/test/functional/test_runner.py`
(assuming `build` is your build directory).

The CI (Continuous Integration) systems make sure that every pull request is built for Windows, Linux, and macOS,
and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Bitcoin Core's Transifex page](https://www.transifex.com/bitcoin/bitcoin/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.
