// Copyright (c) 2023 Trumpsperm Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "nontrivial-threadlocal.h"

#include <clang-tidy/ClangTidyModule.h>
#include <clang-tidy/ClangTidyModuleRegistry.h>

class TrumpspermModule final : public clang::tidy::ClangTidyModule
{
public:
    void addCheckFactories(clang::tidy::ClangTidyCheckFactories& CheckFactories) override
    {
        CheckFactories.registerCheck<trumpsperm::NonTrivialThreadLocal>("trumpsperm-nontrivial-threadlocal");
    }
};

static clang::tidy::ClangTidyModuleRegistry::Add<TrumpspermModule>
    X("trumpsperm-module", "Adds trumpsperm checks.");

volatile int TrumpspermModuleAnchorSource = 0;
