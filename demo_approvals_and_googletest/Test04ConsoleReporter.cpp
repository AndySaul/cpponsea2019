#include "ApprovalTests.hpp"
#include <gtest/gtest.h>

#include "../include/ConsoleDiffReporter.h"

TEST(Test04, UseConsoleReporter)
{
    FirstWorkingReporter diff_reporter(
        {
            // On Windows, SystemLauncher does not yet know how to use the "where" command to find
            // the location of a program that is in the PATH, so we have to give the full
            // path to fc.exe here:
            new ConsoleDiffReporter("C:\\Windows\\System32\\fc.exe"),
            // On Linux and Mac, this one will be used:
            new ConsoleDiffReporter("diff")
        });
    Approvals::verify("Some\nMulti-line\noutput", diff_reporter);
}