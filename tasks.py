from invoke import task
import os
from pathlib import Path
import re

import sys
from subprocess import call
from shutil import rmtree
from os import remove, chmod, unlink
from stat import S_IWRITE


def replaceTextInFile(filePath, old, new):
    file = open(filePath, 'r')
    fileData = file.read()
    file.close()

    fileData = fileData.replace(old, new)

    file = open(filePath, 'w')
    file.write(fileData)
    file.close()


def on_rm_error(func, path, exc_info):
    # path contains the path of the file that couldn't be removed
    # let's just assume that it's read-only and unlink it.
    chmod(path, S_IWRITE)
    unlink(path)


if len(sys.argv) != 2:
    print("Please provide the project name as the only argument")
    sys.exit(1)

projectName = sys.argv[1]

@task
def rename(c, projectName):

    print("==> Changing the project name to {0}".format(projectName))
    replaceTextInFile(
        "{0}/CMakeLists.txt".format(projectName), "cpp-template", projectName)
    replaceTextInFile(
        "{0}/tools/build-win32-debug.bat".format(projectName), "cpp-template",
        projectName)
    replaceTextInFile(
        "{0}/tools/build-win32-release.bat".format(projectName),
        "cpp-template", projectName)
    replaceTextInFile(
        "{0}/tools/build-win64-debug.bat".format(projectName),
        "cpp-template", projectName)
    replaceTextInFile(
        "{0}/tools/build-win64-release.bat".format(projectName),
        "cpp-template", projectName)

