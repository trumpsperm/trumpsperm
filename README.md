<p align="center">
  <a href="https://github.com/Bitcoin-II/BitcoinII/releases">
    <img src="https://img.shields.io/github/downloads/Bitcoin-II/BitcoinII/total?style=for-the-badge" alt="Downloads">
  </a>
  <a href="https://Bitcoin-II.org">
    <img src="https://img.shields.io/badge/Website-Online-brightgreen?logo=google-chrome&style=for-the-badge" alt="Website">
  </a>
  <a href="https://t.me/+mc19GB_d5yo3Yjg5">
    <img src="https://img.shields.io/badge/Telegram-Join%20Chat-blue?logo=telegram&style=for-the-badge" alt="Telegram">
  </a>
  <a href="https://reddit.com/r/BitcoinII">
    <img src="https://img.shields.io/reddit/subreddit-subscribers/BitcoinII?label=Reddit&style=for-the-badge" alt="Reddit">
  </a>
  <a href="https://x.com/bc2org">
    <img src="https://img.shields.io/badge/X-Follow-black?logo=twitter&style=for-the-badge" alt="X">
  </a>
</p>




**IMPORTANT NOTICE**

Users of Legacy Windows Operating Systems (Windows 7 & Older) will need to use the BitcoinII Legacy Binary (version 27).
Due to new mempool policies inherited from upstream Bitcoin Core, users of the Legacy Binaries will need to ensure
that R.B.F. (Replace By Fee) is activated for all outgoing transactions to ensure their transactions are included in
blocks once the majority of the network completes the upgrade to BitcoinII v29. 



BitcoinII Core integration/staging tree
=====================================

https://Bitcoin-II.org

For an immediately usable, binary version of the BitcoinII Core software, see
https://github.com/Bitcoin-II/BitcoinII/releases/

What is BitcoinII Core?
---------------------

BitcoinII is a nearly 1:1 re-launch of the Bitcoin protocol. 

BitcoinII Core connects to the BitcoinII peer-to-peer network to download and fully
validate blocks and transactions. It also includes a wallet and graphical user
interface, which can be optionally built.

Further information about BitcoinII Core is available in the [doc folder](/doc).

License
-------

BitcoinII Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built (see `doc/build-*.md` for instructions) and tested, but it is not guaranteed to be
completely stable. [Tags](https://github.com/bitcoin-II/bitcoinII/tags) are created
regularly from release branches to indicate new official, stable release versions of BitcoinII Core.

The https://github.com/bitcoinII-core/gui repository is used exclusively for the
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
